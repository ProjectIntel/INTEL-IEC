#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
 
int  joystick[1];
int stick[1];
 
RF24 radio(9,10);
 
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL,0xF0F0F0F0D2LL };
 
void setup(void)
{
  Serial.begin(9600);
  radio.begin();
  //radio.openWritingPipe(pipes[0]);
}

 
void loop(void)
{
  
   //radio.setChannel(20);
   radio.openWritingPipe(pipes[0]);
  joystick[0] = 21;
  if(radio.write( joystick, sizeof(joystick) ))
    Serial.println("Pipe1 work");
  else
    Serial.println("Pipe1 Not Work");
 
 
 delay(1000);
  radio.openWritingPipe(pipes[1]);
  stick[0]=10;
  //joystick[1] = 2;
  
  if(radio.write(stick, sizeof(stick) ))
    Serial.println("Pipe2 work");
   else Serial.println("Pipe2 Not Work");
 
}
