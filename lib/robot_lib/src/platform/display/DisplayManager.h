#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H
#include <LiquidCrystal_I2C.h>

class DisplayManager {
    public:
        DisplayManager(uint8_t lcd_addr, uint8_t lcd_cols,uint8_t lcd_rows);
        void init();
        void show_splash_screen();
    
    private:
        LiquidCrystal_I2C* _lcd;
};

#endif