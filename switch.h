/*
* Aarhus University School of Engineering
* All Rights Reserved
* Author: Mirko R. Hoekman
*/
#include <avr/io.h>
#define MAX_SWITCH_NR 7

void initSwitchPort()  
{
  DDRA = 0x00;    // PA as input
  
}

unsigned char switchStatus()
{
  
  return ~ PINA;  // SW 1
  
}

unsigned char switchOn(unsigned char switch_nr)
{
  unsigned char mask=0;           // Erkl�ring af variablen ''mask''
  
  if (switch_nr <= MAX_SWITCH_NR)        // S�rger for at den ikke g�r noget hvis v�rdien bliver over 7.
  {
    mask = 0b00000001 << switch_nr;   // S�rger for at den tilh�rende LED lyser.
  }
  
  return ~PINA & mask;            // returnere en t�ndt v�rdi hvis en switch er aktiveret.
}
