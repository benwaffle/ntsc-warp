#include <Arduino.h>
#include <SparkFunMPU9250-DMP.h>
#include <TVout.h>     // import the library
#include <fontALL.h>   // and its built-in fonts
#include <image.h>

TVout tv;
MPU9250_DMP imu;

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
  if ((c = tv.begin(NTSC, 104, 87)) != 0) {
    while (1) {
      Serial.print(F("error tv begin "));
      Serial.print(' ');
      Serial.println((int)c);
      delay(1000);
    }
  }
  tv.bitmap(0, 0, image);
}

void loop() {
  if (imu.dataReady()) {
    imu.update(UPDATE_ACCEL | UPDATE_GYRO | UPDATE_COMPASS);
    float accelX = imu.calcAccel(imu.ax);
    float accelY = imu.calcAccel(imu.ay);
    float accelZ = imu.calcAccel(imu.az);
    float gyroX = imu.calcGyro(imu.gx);
    float gyroY = imu.calcGyro(imu.gy);
    float gyroZ = imu.calcGyro(imu.gz);
    float magX = imu.calcMag(imu.mx);
    float magY = imu.calcMag(imu.my);
    float magZ = imu.calcMag(imu.mz);

    Serial.println(String(accelX));

    // Serial.println("Accel: " + String(accelX) + ", " + String(accelY) + ", " +
    //                String(accelZ) + " g");
    // Serial.println("Gyro: " + String(gyroX) + ", " + String(gyroY) + ", " +
    //                String(gyroZ) + " dps");
    // Serial.println("Mag: " + String(magX) + ", " + String(magY) + ", " +
    //                String(magZ) + " uT");
    // Serial.println("Time: " + String(imu.time) + " ms");
    Serial.println(); // WTF
  }
}