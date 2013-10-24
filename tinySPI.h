/*----------------------------------------------------------------------*
 * tinySPI.h - Arduino hardware SPI library for ATtiny44/84/45/85.      *
 * Runs about 15 times faster than shiftOut().                          *
 *                                                                      *
 * Jack Christensen 24Oct2013                                           *
 *                                                                      *
 * CC BY-SA:                                                            *
 * This work is licensed under the Creative Commons Attribution-        *
 * ShareAlike 3.0 Unported License. To view a copy of this license,     *
 * visit http://creativecommons.org/licenses/by-sa/3.0/ or send a       *
 * letter to Creative Commons, 171 Second Street, Suite 300,            *
 * San Francisco, California, 94105, USA.                               *
 *----------------------------------------------------------------------*/
 
#ifndef tinySPI_h
#define tinySPI_h

#include <stdint.h>
#include <avr/io.h>

#if defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
#define SPI_DDR_PORT DDRA
#define USCK_DD_PIN DDA4
#define DO_DD_PIN DDA5
#define DI_DD_PIN DDA6
#elif defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
#define SPI_DDR_PORT DDRB
#define USCK_DD_PIN DDB2
#define DO_DD_PIN DDB1
#define DI_DD_PIN DDB0
#endif

class tinySPI
{
    public:
        tinySPI();
        void begin();
        uint8_t transfer(uint8_t spiData);
};

extern tinySPI SPI;

#endif