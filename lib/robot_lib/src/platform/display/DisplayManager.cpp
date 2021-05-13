#include "DisplayManager.h"

#include <LiquidCrystal_I2C.h>


const char SPLASH_SCREEN[3][20] = {
  {"  ___              "},
  {"   |     _|_  _ |_ "},
  {"   | |_|| |_)(_)|_ "}
};


DisplayManager::DisplayManager(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows) {
  _lcd = new LiquidCrystal_I2C(0x20, lcd_cols, lcd_rows);
}


void DisplayManager::init() {
  _lcd->init();
  _lcd->backlight();
}


void DisplayManager::show_splash_screen() {
    _lcd->home();
    for (int i = 0; i < 3; i++) {
        _lcd->print(SPLASH_SCREEN[i]);
        _lcd->setCursor(0, i+1);
    }
}