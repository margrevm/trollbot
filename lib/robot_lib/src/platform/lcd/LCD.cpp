#include "LCD.h"

#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;

const char SPLASH_SCREEN[3][20] = {
  {"  ___              "},
  {"   |     _|_  _ |_ "},
  {"   | |_|| |_)(_)|_ "}
};


void show_splash_screen() {
    lcd.home();
    for (int i = 0; i < 3; i++) {
        lcd.print(SPLASH_SCREEN[i]);
        lcd.setCursor(0, i+1);
    }
}