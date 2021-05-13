#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <platform/display/DisplayManager.h>
#include <elapsedMillis.h>
#include <config.h>


elapsedSeconds time_elapsed;
unsigned long current_secs;

void setup() {
  Serial.begin(9600);

  DisplayManager(LCD_ADDR, LCD_COLS, LCD_ROWS).show_splash_screen();
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

