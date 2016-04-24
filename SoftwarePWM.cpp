/* 
 * File:   SoftwarePWM.cpp
 * Author: Cameron
 * 
 * Created on April 23, 2016, 5:55 PM
 */

#include "SoftwarePWM.h"


u1 SoftwarePWM::counter = 0;

TripleBuffer<SoftwarePWM::numChannels, false> SoftwarePWM::buffer;

void TIMER0_COMPA_vect() {
 SoftwarePWM::isr();
}

void SoftwarePWM::isr() {
 counter++;
 if (!counter) {
  PORTB = 0xff;
  PORTD = 0xff;
  if (buffer.isNewData()) buffer.reserveNewestBufferForReading();
 }
 
 u1 const * const match = buffer.getReadBuffer();
 
 if (counter == match[000]) PORTB &= ~(1 << 0);
 if (counter == match[001]) PORTB &= ~(1 << 1);
 if (counter == match[002]) PORTB &= ~(1 << 2);
 if (counter == match[003]) PORTB &= ~(1 << 3);
 if (counter == match[004]) PORTB &= ~(1 << 4);
 if (counter == match[005]) PORTB &= ~(1 << 5);
 if (counter == match[006]) PORTB &= ~(1 << 6);
 if (counter == match[007]) PORTB &= ~(1 << 7);
 if (counter == match[010]) PORTD &= ~(1 << 0);
 if (counter == match[011]) PORTD &= ~(1 << 1);
 if (counter == match[012]) PORTD &= ~(1 << 2);
 if (counter == match[013]) PORTD &= ~(1 << 3);
 if (counter == match[014]) PORTD &= ~(1 << 4);
 if (counter == match[015]) PORTD &= ~(1 << 5);
 if (counter == match[016]) PORTD &= ~(1 << 6);
 if (counter == match[017]) PORTD &= ~(1 << 7);
}

void SoftwarePWM::init() {
 static bool initted = false;
 if (initted) return;
 initted = true;
 
 PORTB = 0;
 PORTD = 0;
 
 DDRB = 0xff;
 DDRD = 0xff;
 
 latch();
 
 for (u1 i = 0; i < numChannels; i++) {
  getMatchArray()[i] = 0xff;
 }
 
 latch();
 
 TCCR0A = 0b10;
 OCR0A = 50;
 TCCR0B = 0b010;
 TIFR0 = 0xff;
 TIMSK0 = 1 << OCIE0A;
}
