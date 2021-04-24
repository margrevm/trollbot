/*
MIT License

Copyright 2020 Mike Margreve  

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
 * @file Obet.h
 * @author Mike Margreve
 * @brief Declaration of OBET class
 * @version 0.1
 */

#ifndef OBET_H
#define OBET_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/**
 * @brief This class saves the current elapsed time (since boot)
 */
class Obet
{
public:

    /**
     * @brief Get the OBET (onboard elapsed time since boot) in milliseconds
     * 
     * @return OBET (milliseconds)
     */
    uint64_t getObetMs();

    /**
     * @brief Get the OBET (onboard elapsed time since boot) in seconds
     * 
     * @return OBET (seconds)
     */
    float getObetSec();



private:
    uint64_t _obet_ms;
    float _obet_s;
};

#endif