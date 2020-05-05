#include <Arduino.h>

#include "WEMOS_SHT3X.h"
#include "Adafruit_NeoPixel.h"

#define PIN        17                //the pin on the board
#define NUMPIXELS  1                 //no of LEDs

SHT3X sht30(0x45);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  pixels.begin();
  Serial.begin(9600);
  
  
}

void loop() {

  if(sht30.get()==0){
    Serial.print("Temperature in Celsius : ");
    Serial.println(sht30.cTemp);
    Serial.print("Relative Humidity : ");
    Serial.println(sht30.humidity);
    Serial.println();
    if(sht30.cTemp >= 30)
    {
      pixels.clear();

      for(int i=0; i<NUMPIXELS; i++) 
      {
    
        pixels.setPixelColor(i, pixels.Color(150, 0, 0));
        pixels.show();
        delay(500);

      }
    }
    else
    {
      pixels.clear();
      for(int i=0; i<NUMPIXELS; i++) 
      {
        pixels.setPixelColor(i, pixels.Color(0, 0, 150));
        pixels.show();
        delay(500);
      }
    }
  }
  
  else
  {
    Serial.println("Error!");
  }
  delay(1000);


  
}