/* 
 * File:   main.cpp
 * Author: Cameron
 * 
 * Created on April 23, 2016, 4:12 PM
 */

#include "Board.h"
#include "SoftwarePWM.h"
#include "Display.h"

#include <avr/io.h>
#include <util/delay.h>

#include <math.h>

unsigned int delay = 50;


void main() {
 
 Board::A.off();
 Board::B.off();
 Board::C.off();
 
 Board::A.output();
 Board::B.output();
 Board::C.output();
  Board::C.on();
 
 SoftwarePWM::init();
  
 
  u2 j = 0;
  while (1) {
  _delay_ms(10);
   for (u1 i = 0; i < Display::numPixels; i++) {
    Display::writePixel(i, (sin(i / 3. - j / 10.) + 1) / 2 * 255);
   }

   Display::latch();
   
   j++;
  }
 
 
 while (1); {
  _delay_ms(1000);
  Board::C.on();
  
  PORTB = 0b00111110;
  _delay_ms(delay);
  PORTB = 0b00111101;
  _delay_ms(delay);
  PORTB = 0b00111011;
  _delay_ms(delay);
  PORTB = 0b00110111;
  _delay_ms(delay);
  PORTB = 0b00101111;
  _delay_ms(delay);
  PORTB = 0b00011111;
  _delay_ms(delay);
  PORTB = 0b00111111;
  PORTD = 0b01111110;
  _delay_ms(delay);
  PORTD = 0b10111110;
  _delay_ms(delay);
  PORTD = 0b11011110;
  _delay_ms(delay);
  PORTD = 0b11101110;
  _delay_ms(delay);
  PORTD = 0b11110110;
  _delay_ms(delay);
  PORTD = 0b11111010;
  _delay_ms(delay);
  PORTD = 0b11111100;
  _delay_ms(delay);
  PORTD = 0b11111110;
  
  Board::C.off();
 }
}