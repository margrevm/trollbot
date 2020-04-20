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
 * @file ArduinoExtensions.h
 * @author Mike Margreve (mike.margreve@outlook.com)
 * @brief Some useful functions that are not included in the standart Arduino library.
 * @version 1.0
 * @date 2020-04-20
 */

#ifndef ARDUINOEXTENSIONS_H
#define ARDUINOEXTENSIONS_H

/**
 * @brief Re-maps a number from one range to another (floating point variant).
 * 
 * That is, a value of fromLow would get mapped to toLow, 
 * a value of fromHigh to toHigh, values in-between to values in-between, etc.
 * 
 * Note that the "lower bounds" of either range may be larger or smaller than the "upper bounds" 
 * so the map() function may be used to reverse a range of numbers.
 * 
 * The original 'map' function is described here:
 * https://www.arduino.cc/reference/en/language/functions/math/map/
 * 
 * @param value the number to map.
 * @param fromLow the lower bound of the value’s current range.
 * @param fromHigh the upper bound of the value’s current range.
 * @param toLow the lower bound of the value’s target range.
 * @param toHigh the upper bound of the value’s target range.
 * @return The mapped value.
 */
float mapFloat(float value, float fromLow, float fromHigh, float toLow, float toHigh); 

#endif