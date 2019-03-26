#include <Arduino.h>
#include <SparkFunMPU9250-DMP.h>
#include <TVout.h>     // import the library
#include <fontALL.h>   // and its built-in fonts
#include <image.h>

TVout tv;
MPU9250_DMP imu;
float magX, magY, magZ;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  if (imu.begin() != INV_SUCCESS) {
    while (1) {
      Serial.println("Unable to communicate with MPU-9250");
      Serial.println("Check connections, and try again.");
      Serial.println();
      delay(1000);
    }
  }

  imu.setSensors(INV_XYZ_GYRO | INV_XYZ_ACCEL | INV_XYZ_COMPASS);
  imu.setGyroFSR(2000);
  imu.setAccelFSR(16);
  imu.setLPF(5);
  imu.setSampleRate(10);
  imu.setCompassSampleRate(10);

  char c;
  if ((c = tv.begin(NTSC, 104, 86)) != 0) {
    while (1) {
      Serial.print(F("error tv begin "));
      Serial.print(' ');
      Serial.println((int)c);
      delay(1000);
    }
  }
}

void loop() {
  if (imu.dataReady()) {
    imu.update(UPDATE_COMPASS);
    magX = imu.calcMag(imu.mx);
    magY = imu.calcMag(imu.my);
    magZ = imu.calcMag(imu.mz);
    Serial.println(magX);
    Serial.println(magY);
    Serial.println(magZ);
    Serial.println("\n\n\n\n");
  }
  tv.bitmap((int)abs(magX), (int)abs(magY), image, 0, 104 - (int)abs(magX), 86 - (int)abs(magY));
}