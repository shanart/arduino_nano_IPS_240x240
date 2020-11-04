#include <Arduino_ST7789.h> // hardware-specific library for ST7789
#include <SPI.h>

#define TFT_DC 9 // pin of your choice
#define TFT_RST 8 // pin of your choice

Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST);

void setup(void) {

  Serial.begin (9600);
  Serial.println (); // cut the gibberish first line Serial Monitor
  Serial.println ();
  Serial.print ("Hello World"); // test Serial Monitor
  
  tft.init (240, 240); // initialize a ST7789 chip, 240×240 pixels
  tft.fillScreen (BLACK);
  tft.setCursor (10, 10);
  tft.setTextColor (YELLOW);
  tft.setTextSize (3);
  tft.println ("Hello world");
}

void loop (){

}
