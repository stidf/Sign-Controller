/* 
 * File:   SoftwarePWM.h
 * Author: Cameron
 *
 * Created on April 23, 2016, 5:55 PM
 */

#ifndef SOFTWAREPWM_H
#define	SOFTWAREPWM_H

#include <avr/interrupt.h>

#include <AVR++/basicTypes.h>

#include "TripleBuffer.h"

ISR(TIMER0_COMPA_vect);

using namespace AVR;


class SoftwarePWM {
public:
 static constexpr unsigned int numChannels = 16;
private:
 
 friend void TIMER0_COMPA_vect();
 
 inline static void isr();
 
 static u1 counter;
 
 static TripleBuffer<SoftwarePWM::numChannels, false> buffer;
 
public:
 
 static void init();
 
 inline static u1 * getMatchArray() {return buffer.getWriteBuffer();}
 
 inline static void latch() {buffer.markNewestBuffer();}
 
private:

};

#endif	/* SOFTWAREPWM_H */

