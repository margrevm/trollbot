/**
 * @file test_sharp_ir_sensor.h
 * @author Margreve Mike
 * @date 18/04/2020
 * @brief Unit test for the 3 Sharp infrared sensors
 * 
 * Test results:
 *  - Average sensor readout duration: 3 - 4 ms
 *  - Can be changed by lowering the sampling in the SharpIR library
 * 
 * More information about PIO Unit Testing:
 * - https://docs.platformio.org/page/plus/unit-testing.html
 */

#include <Arduino.h>
#include <unity.h>
#include <io.h>
#include <config.h>
#include <SharpIR.h>

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

/* Initialize sharp IR objects */
SharpIR sensor_sharp_ir_left(IO_A_SHARP_IR_LEFT, CONF_SHARP_IR_MODEL);
SharpIR sensor_sharp_ir_middle(IO_A_SHARP_IR_MIDDLE, CONF_SHARP_IR_MODEL);
SharpIR sensor_sharp_ir_right(IO_A_SHARP_IR_RIGHT, CONF_SHARP_IR_MODEL);

void test_sharp_ir_configuration(void) {
    TEST_ASSERT_EQUAL(A7, IO_A_SHARP_IR_RIGHT);
    TEST_ASSERT_EQUAL(A6, IO_A_SHARP_IR_MIDDLE);
    TEST_ASSERT_EQUAL(A5, IO_A_SHARP_IR_LEFT);
    TEST_ASSERT_EQUAL(1080, CONF_SHARP_IR_MODEL);
}

void test_sharp_ir_left(void) {
    unsigned long pepe1=millis();  
    int dis=sensor_sharp_ir_left.distance();  
    unsigned long pepe2=millis()-pepe1;  

    Serial.print("[LEFT]   ");  
    Serial.print(dis);
    Serial.print(" cm (time taken: ");
    Serial.print(pepe2);  
    Serial.print(" ms) --- ");
}

void test_sharp_ir_right(void) {
    unsigned long pepe1=millis();  
    int dis=sensor_sharp_ir_right.distance();  
    unsigned long pepe2=millis()-pepe1;  

    Serial.print("[RIGHT]  ");  
    Serial.print(dis);
    Serial.print(" cm (time taken: ");
    Serial.print(pepe2);  
    Serial.print(" ms) --- ");
}

void test_sharp_ir_middle(void) {
    unsigned long pepe1=millis();  
    int dis=sensor_sharp_ir_middle.distance();  
    unsigned long pepe2=millis()-pepe1;  

    Serial.print("[MIDDLE] ");  
    Serial.print(dis);
    Serial.print(" cm (time taken: ");
    Serial.print(pepe2);  
    Serial.print(" ms) --- ");
}

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();

    RUN_TEST(test_sharp_ir_configuration);
}

uint8_t i = 0;
uint8_t nb_samples = 30;

void loop() {
    delay(1000);   

    if (i < nb_samples)
    {
        RUN_TEST(test_sharp_ir_left);
        RUN_TEST(test_sharp_ir_middle);
        RUN_TEST(test_sharp_ir_right);
        Serial.println("\n");

        i++;
    }
    else if (i == nb_samples) {
      UNITY_END(); // stop unit testing
    }
}