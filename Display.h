/* 
 * File:   Display.h
 * Author: Cameron
 *
 * Created on April 23, 2016, 7:39 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#include <AVR++/basicTypes.h>

#include "SoftwarePWM.h"

using namespace AVR;

class Display {
public:
 static constexpr u1 numPixels = 13;
private:
 
 inline static u1 exponential(u1);
 
public:
 static void writePixel(u1 pixel, u1 val);
 inline static void latch() {SoftwarePWM::latch();}
private:

};

#endif	/* DISPLAY_H */

