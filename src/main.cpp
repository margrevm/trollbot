#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <platform/lcd/LCD.h>

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

LiquidCrystal_I2C lcd(0x20, 20, 4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


void setup() {
  Serial.begin(9600);
  // Serial.println("test");
  // put your setup code here, to run once:
  lcd.init();                      // initialize the lcd 
  lcd.backlight();

  show_splash_screen();
}

void loop() {
  
}

