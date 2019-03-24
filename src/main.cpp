#include <Arduino.h>
#include <TVout.h>     // import the library
#include <fontALL.h>   // and its built-in fonts
#include <image.h>

TVout tv;   // instance of the TVout library

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  // init the TVout library and select a font
  tv.begin(NTSC, 128, 96);
  tv.clear_screen();
  // tv.select_font(font6x8);

  // // display some text!
  // tv.println("Hello world!");
  // delay(2000);

  // // show the various fonts
  // tv.clear_screen();
  // tv.println("I have a few fonts:");
  // tv.select_font(font4x6);
  // tv.println("4x6 font");
  // tv.select_font(font6x8);
  // tv.println("6x8 font");
  // tv.select_font(font8x8);
  // tv.println("8x8 font");
  // tv.delay(4000);
  tv.bitmap(0, 0, image);
  // tv.bitmap(0, 0, TVOlogo);
}


void loop() {

  // clear the screen every frame
  // tv.clear_screen();

  // tv.bitmap(0, 0, image, 0, 32, 25);
  // tv.bitmap(0, 0, TVOlogo);

  // circles
  // args: x, y, diameter, color (WHITE, BLACK, or INVERT)
  // tv.draw_circle(50,50, 30, WHITE);
  // tv.draw_circle(tv.hres()-50,tv.vres()-50, 30, WHITE);

  // rectangle
  // args: x, y, width, height, stroke color, fill color
  // tv.draw_rect(50,50, tv.hres()-1000,tv.vres()-100, WHITE, INVERT);

  // lines
  // args: start x, start y, end x, end y, stroke color
  // tv.draw_line(0,0, tv.hres(),tv.vres(), INVERT);
  // tv.draw_line(0,tv.vres(), tv.hres(),0, INVERT);
}