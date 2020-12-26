
/*
* lab06_B.c
*
* Created: 09-10-2018 11:17:41
* Author : Mirko Hoekman
*/

#include <avr/io.h>
#include "led.h"
#include "switch.h"
#include <Servo.h>

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;

int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos; // current position
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos; // previous position
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50], servo06SP[50]; // for storing positions/steps
int speedDelay = 20;
int index = 0;
int dataIn;
int program = 0;


void setup() 
{
  
  DDRB = 0xFF;    // PB som output
  PORTB = 0x00;   // Alle lysdioder slukkes

//attach pins
 servo01.attach(5);
  servo02.attach(6);
  servo03.attach(7);
  servo04.attach(8);
  servo05.attach(9);
  servo06.attach(10);

// default pos  
  servo1PPos = 90;
  servo01.write(servo1PPos);
  servo2PPos = 100;
  servo02.write(servo2PPos);
  servo3PPos = 100;
  servo03.write(servo3PPos);
  servo4PPos = 120;
  servo04.write(servo4PPos);
  servo5PPos = 72;
  servo05.write(servo5PPos);
  servo6PPos = 110;
  servo06.write(servo6PPos);
} 
 
  
  
  
void loop () {  

    
   while (switchOn(6)){ 
    {
      program = 0;
    }
    
    while (switchOn(7)) 
    {
      program = 1;
    }

   }

  
   while (program = 0) {
    // Move robot arm
    // Move servo 1 in positive direction
   
    if (switchOn(0)) 
    {
      servo01.write(servo1PPos);
      servo1PPos++;
      delay(speedDelay);  
    }
  
    // Move robot arm
    // Move servo 1 in negative direction
    if (switchOn(1))    // SW1 Initieres
    {
       servo01.write(servo1PPos);
      servo1PPos--;
      delay(speedDelay);  
    }
    
    if (switchOn(2))    // SW2 Initieres
    {
      servo02.write(servo2PPos);
      servo2PPos++;
      delay(speedDelay);  
    }
   if (switchOn(3))    // SW3 Initieres
      {
      servo02.write(servo2PPos);
      servo2PPos--;
      delay(speedDelay);
      } 

    if (switchOn(4))    // SW4 Initieres
     {
      servo03.write(servo2PPos);
      servo3PPos++;
      delay(speedDelay);  
      }
   if (switchOn(5))    // SW5 Initieres
      {
      servo03.write(servo2PPos);
      servo3PPos--;
      delay(speedDelay);
      } 

   
   }   


  while ( program = 1) {

 // skriv koden for program 1


    if (switchOn(0)) 
    {
      servo04.write(servo4PPos);
      servo4PPos++;
      delay(speedDelay);  
    }
  
    // Move robot arm
    // Move servo 1 in negative direction
    if (switchOn(1))    // SW1 Initieres
    {
       servo04.write(servo4PPos);
      servo4PPos--;
      delay(speedDelay);  
    }
    
    if (switchOn(2))    // SW2 Initieres
    {
      servo05.write(servo5PPos);
      servo5PPos++;
      delay(speedDelay);  
    }
   if (switchOn(3))    // SW3 Initieres
      {
      servo05.write(servo6PPos);
      servo5PPos--;
      delay(speedDelay);
      } 

    if (switchOn(4))    // SW2 Initieres
     {
      servo06.write(servo6PPos);
      servo6PPos++;
      delay(speedDelay);  
      }
   if (switchOn(5))    // SW3 Initieres
      {
      servo06.write(servo6PPos);
      servo6PPos--;
      delay(speedDelay);
      } 






}



}


   
