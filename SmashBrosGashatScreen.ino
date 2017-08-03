#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <TFT.h>
 
// PIN DEFINITION FOR LCD SCREEN
#define sd_cs  4
#define lcd_cs 10
#define dc     9
#define rst    8
 
TFT TFTscreen = TFT(lcd_cs, dc, rst);
PImage picture;
char last_code = 'z';
 
void(* resetFunc) (void) = 0; 
 
void setup() {
  Wire.begin(8); // Address 8
  Wire.onReceive(receiveEvent);
 
  // SD Card Ready
  if (!SD.begin(sd_cs)) {
    return;
  }
 
  // LCD screen Ready
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
}
 
void loop() {
  delay(100);
}
 
void receiveEvent(int howMany){
  char code;
  while(Wire.available()){
    code = Wire.read();
  }
  if(last_code != code){
    TFTscreen.background(0,0,0);
    switch(code){
    case 'a': picture = TFTscreen.loadImage("sb.bmp"); break;
    case 'b': picture = TFTscreen.loadImage("mar0.bmp"); break;
    case 'c': picture = TFTscreen.loadImage("mar1.bmp"); break;
    case 'd': picture = TFTscreen.loadImage("mar2.bmp"); break;
    case 'e': picture = TFTscreen.loadImage("mar3.bmp"); break;
    case 'f': picture = TFTscreen.loadImage("lin0.bmp"); break;
    case 'g': picture = TFTscreen.loadImage("lin1.bmp"); break;
    case 'h': picture = TFTscreen.loadImage("lin2.bmp"); break;
    case 'i': picture = TFTscreen.loadImage("lin3.bmp"); break;
    case 'j': picture = TFTscreen.loadImage("liz0.bmp"); break;
    case 'k': picture = TFTscreen.loadImage("liz1.bmp"); break;
    case 'l': picture = TFTscreen.loadImage("liz2.bmp"); break;
    case 'm': picture = TFTscreen.loadImage("liz3.bmp"); break;
    case 'z': resetFunc(); break;
    default : picture = TFTscreen.loadImage("sb.bmp");
    }
    delay(2500);
    TFTscreen.image(picture, 0, 0);
  }
  last_code = code;
 
}
