/*
MIT License

Copyright (c) 2020 Margreve Mike

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/**
 * @file test_SharpDistSensor.cpp
 * @author Mike Margreve (mike.margreve@outlook.com)
 * @brief Unit test for the SharpDistSensor library.
 * @version 1.0
 * @date 2020-04-18
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
#include <SharpDistSensor.h>

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

#define SAMPLES_PER_TEST    30
#define DELAY_MS            500               

//Init objects
const byte sensorPin = IO_A_SHARP_IR_LEFT;
SharpDistSensor sensor_5(sensorPin, 5);
SharpDistSensor sensor_10(sensorPin, 10);
SharpDistSensor sensor_25(sensorPin, 25);

//TODO Move to other test
void test_sharp_ir_configuration(void) {
    TEST_ASSERT_EQUAL(A0, IO_A_SHARP_IR_LEFT);
    TEST_ASSERT_EQUAL(5, CONF_SHARP_MEDIAN_FILTER_NB_SAMPLES);
}

void test_SharpDistSensor_sampling(void) {
    
    uint16_t i;

    Serial.println("STEP 1: Get distance with median filter window set to 5");

    for(i = 0; i < SAMPLES_PER_TEST; i++)
    {
        unsigned long start=micros();  
        float distance = sensor_5.getDist(); 
        unsigned long time=micros()-start;  

        // Print distance to Serial
        Serial.print("[");
        Serial.print(i);
        Serial.print("] DIST: ");
        Serial.print(distance);
        Serial.print(" cm (time taken: ");
        Serial.print(time);  
        Serial.println(" micros)");

        delay(DELAY_MS);
    }

    Serial.println("STEP 2: Get distance with median filter window set to 10");

    for(i = 0; i < SAMPLES_PER_TEST; i++)
    {
        unsigned long start=micros();  
        float distance = sensor_10.getDist(); 
        unsigned long time=micros()-start;  

        // Print distance to Serial
        Serial.print("[");
        Serial.print(i);
        Serial.print("] DIST: ");
        Serial.print(distance);
        Serial.print(" cm (time taken: ");
        Serial.print(time);  
        Serial.println(" micros)");

        delay(DELAY_MS);
    }

    Serial.println("STEP 3: Get distance with median filter window set to 25");

    for(i = 0; i < SAMPLES_PER_TEST; i++)
    {
        unsigned long start=micros();  
        float distance = sensor_25.getDist(); 
        unsigned long time=micros()-start;  

        // Print distance to Serial
        Serial.print("[");
        Serial.print(i);
        Serial.print("] DIST: ");
        Serial.print(distance);
        Serial.print(" cm (time taken: ");
        Serial.print(time);  
        Serial.println(" micros)");

        delay(DELAY_MS);
    }
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
    RUN_TEST(test_SharpDistSensor_sampling);
    UNITY_END(); // stop unit testing
}