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
 * @file io.h
 * @author Margreve Mike
 * @version 1.0
 * @date 2020-04-18
 * @brief Configuration file for I/O pins.
 *
 * This is the standart I/O configuration for the Romeo BLE board.
 */

#ifndef IO_H
#define IO_H

/* TODO Pin attribution has to be tested */ 

/* Analog Inputs */
/* - Buttons */

/* - Sharp infrared sensor */
#define IO_A_SHARP_IR_RIGHT         A2 
#define IO_A_SHARP_IR_MIDDLE        A1 
#define IO_A_SHARP_IR_LEFT          A0

/* Analog Outputs */
/* - None */

/* Digital Inputs */
/* - Wheel encoders */
#define IO_ENCODER_LEFT             D2
#define IO_ENCODER_LEFT             D3
/* - Line sensors */
#define IO_LINE_SENSOR_FAR_LEFT     D4
#define IO_LINE_SENSOR_LEFT         D5
#define IO_LINE_SENSOR_MIDDLE       D6
#define IO_LINE_SENSOR_RIGHT        D7
#define IO_LINE_SENSOR_FAR_RIGHT    D8

/* Digital Outputs */

#endif