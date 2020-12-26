/* 
 * Aarhus University School of Engineering
 * All Rights Reserved
 * 
 */
#include <avr/io.h>
#define MAX_LED_NR 7

void initLEDport()
{
	DDRB = 0xFF;	 // PB as output
	PORTB = 0;		 // Turn off all LEDs
}

void writeAllLEDs(unsigned char pattern)
{
	PORTB = pattern;				// Assign pattern to PORTB   
}

void turnOnLED(unsigned char led_nr)
{
  unsigned char mask;				// Local variable

  if (led_nr <= MAX_LED_NR);		// S�rger for at den ikke g�r noget hvis v�rdien bliver over 7.
  {
    mask = 0b00000001 << led_nr;	// Make a mask 
    PORTB = PINB | mask;			// Turn on actual LED, others are unchanged
  }   
}

void turnOffLED(unsigned char led_nr)
{
 unsigned char mask; // TBD
 
 if (led_nr <= MAX_LED_NR);			// S�rger for at den ikke g�r noget hvis v�rdien bliver over 7.
 {
	 mask = 0b00000001 << led_nr;   // laver en maske
	 PORTB = PINB & ~mask;			// Afl�ser at hvis der kommer en t�ndt v�rdi skal den tilh�rende LED t�nde. De andre forbliver u�ndret.
 }
}

void toggleLED(unsigned char led_nr)
{
	unsigned char mask; // Erkl�ring af Variblen ''mask''
	
	if (led_nr <= MAX_LED_NR); // S�rger for at den ikke g�r noget hvis v�rdien bliver over 7.
	{
		mask = 0b00000001 << led_nr; // Skifter den t�ndte LED en bit til venstre.
		
		PORTB = PINB ^ mask; // S�rger for at kun den ''togglede'' LED lyser.
	}
}
