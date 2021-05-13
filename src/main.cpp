#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <platform/lcd/LCD.h>
#include <elapsedMillis.h>


LiquidCrystal_I2C lcd(0x20, 20, 4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
elapsedSeconds time_elapsed;
unsigned long current_secs;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  lcd.init();                      // initialize the lcd 
  lcd.backlight();

  show_splash_screen();
  current_secs = time_elapsed; 
}

void loop() {
  if (time_elapsed > current_secs) {
    char text_buffer[20];
    // ltoa(time_elapsed, text_buffer, 10);
    sprintf(text_buffer, "%ul", current_secs);
    Serial.println(current_secs);
    current_secs = time_elapsed;
  }

}

