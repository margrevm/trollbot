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
 * @file SharpDistSensorArray.h
 * @author Mike Margreve (mike.margreve@outlook.com)
 * @brief This library manages the 3 Sharp distance sensors on the robot
 * @version 1.0
 * @date 2020-04-25
 */

#ifndef SHARPDISTSENSORARRAY_H
#define SHARPDISTSENSORARRAY_H

#include <Arduino.h>
#include <SharpDistSensor.h>
#include <config.h>
#include <io.h>

class SharpDistSensorArray
{
public:

    /** Constructor
    pin:    Arduino analog pin the sensor is connected to
    size: Window size of the median filter (1 = no filtering)
    **/
    SharpDistSensorArray(uint32_t rate_ms);

    /**
     * @brief Set the Sampling Rate of the 
     * 
     * @param rate_ms 
     */
    void setSamplingRate(uint32_t rate_ms);

    /**
     * @brief Calls the read function of all sensors.
     * The sampling rate is set by calling setSamplingRate
     * 
     * @return uint16_t Returns True if no error during read cycle
     */
    uint16_t read();

private:

    /**
     * @brief Array of Sharp distance sensors
     * The number of sensors is defined by CONF_SHARP_NB_SENSORS
     */
    SharpDistSensor sensors[CONF_SHARP_NB_SENSORS] = {
        SharpDistSensor(IO_A_SHARP_IR_LEFT, CONF_SHARP_MEDIAN_FILTER_NB_SAMPLES),
        SharpDistSensor(IO_A_SHARP_IR_MIDDLE, CONF_SHARP_MEDIAN_FILTER_NB_SAMPLES),
        SharpDistSensor(IO_A_SHARP_IR_RIGHT, CONF_SHARP_MEDIAN_FILTER_NB_SAMPLES)
        };

    /**
     * @brief Sampling rate of sensors in ms
     */
    uint32_t sampling_rate_ms;

};

#endif
