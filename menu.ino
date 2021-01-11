#include <Arduino_ST7789.h>                           // hardware-specific library for ST7789
#include <SPI.h>

#define TFT_DC    9
#define TFT_RST   8

Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST);

// UI variables
#define screen_border   10
#define pointer         "> "

short int gutter = 20;

void setup(void) {     
  tft.init (240, 240);
  tft.fillScreen (BLACK);
  
  tft.drawRect(screen_border, screen_border, 220, 220, WHITE);
  tft.setTextSize(2);
  tft.setCursor(screen_border*2, screen_border*2);
  tft.print("MAIN MENU");
  
  menu_item("Home", true, 1);
  menu_item("Update", false, 2);
  menu_item("Settings", false, 3);
  menu_item("On-Off", false, 4);
}

void loop (){

}

void menu_item(char *text, bool active, short index) {
  tft.setCursor(screen_border*2, (gutter*(2+index)+5));
  is_active(active); 
  tft.print(text);
}

void is_active(bool active) {
  if (active == true) {
    tft.print(pointer);
  } else {
    tft.print("  ");  
  }
  
}

void print_text(char *text, short x, short y) {
  tft.setCursor(x, y);
  tft.setTextColor(WHITE);
  tft.setTextWrap(true);
  tft.print(text);
}
