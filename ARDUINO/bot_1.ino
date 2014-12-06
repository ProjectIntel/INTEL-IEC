#include <SoftPWM.h>
#include <SoftPWM_timer.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

int joystick[1];
 
RF24 radio(3, 7);
const uint64_t pipe = 0xF0F0F0F0E1LL;
int motorPin1 =  5;    // One motor wire connected to digital pin 5
int motorPin2 =  6;    // One motor wire connected to digital pin 6
int motorPin3 =  9;
int motorPin4 = 10;

// The setup() method runs once, when the sketch starts

void setup()   {                
  // initialize the digital pins as an output:
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  int i=0;
  do
  {
    if ( radio.available() )
  {
    bool done = false;
    while (!done)
    {
      done = radio.read( joystick, sizeof(joystick) );
      i++;
      Serial.println(joystick[0]);
  }
  } 
  }
  while(i<20);
  int x= joystick[0]/100;
  int y= (joystick[0]/10)%10;
  int z= joystick[0]%10;
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
  SoftPWMBegin();
  SoftPWMSet(5, 0);
  SoftPWMSetFadeTime(5, 500, 1000);
  SoftPWMSet(6, 0);
  SoftPWMSetFadeTime(6, 500, 1000);
  SoftPWMSet(9, 0);
  SoftPWMSetFadeTime(9, 500, 1000);
  SoftPWMSet(10, 0);
  SoftPWMSetFadeTime(10, 500, 1000);
  pinMode(motorPin1, OUTPUT); 
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  if(z==0)
  {
  if(x<0)
 { 
  y=-1*y;
  x=-1*x;
  int a=1, b=1;
  while(a<=x)
  {
  straight(1000);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  a++;
  }
  rotateLeftFull(1400);
  while(b<=y)
  {
  straight(1000);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  b++;
  }
 }  
 else if(x>0)
 { 
  int a=1;
  int b=1;
  while(a<=x)
  {
  straight(1000);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  a++;
  }
  rotateRightFull(1400);
  while(b<=y)
  {
  straight(1000);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  b++;
  }
 }
  }
  else if(z>0)
  {
  z=-z;
  if(x<0)
 { 
  y=-1*y;
  x=-1*x;
  delay(200);
  int a=1, b=1;
  while(a<=x)
  {
  straight(1000);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  a++;
  }
  rotateLeftFull(1400);
  while(b<=y)
  {
  straight(1000);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  b++;
  }
 }  
 else if(x>0)
 { 
  delay(200);
  int a=1, b=1;
  while(a<=x)
  {
  straight(1000);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  a++;
  }
  rotateRightFull(1400);
  while(b<=y)
  {
  straight(1000);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  b++;
  }
 }
}
}

// the loop() method runs over and over again,
// as long as the Arduino has power
void loop()                     
{  
}

void rotateLeftFull(int length){
  /*digitalWrite(motorPin1, LOW); //rotates motor
  digitalWrite(motorPin2, HIGH);    // set the Pin motorPin2 LOW
  digitalWrite(motorPin3, LOW); //rotates motor
  digitalWrite(motorPin4, LOW);    // set the Pin motorPin2 LOW
  delay(length); //waits
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
  digitalWrite(motorPin3, LOW); //rotates motor
  digitalWrite(motorPin4, LOW);    // set the Pin motorPin2 LOW*/
  SoftPWMSet(motorPin1, 0);
  SoftPWMSet(motorPin2, 255);
  SoftPWMSet(motorPin3, 0);
  SoftPWMSet(motorPin4, 0);
  delay(length);
  SoftPWMSet(motorPin1, 0);
  SoftPWMSet(motorPin2, 0);
  SoftPWMSet(motorPin3, 0);
  SoftPWMSet(motorPin4, 0);
}

void rotateRightFull(int length){
  /*digitalWrite(motorPin1, LOW); //rotates motor
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);    // set the Pin motorPin2 LOW
  delay(length); //waits
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
  digitalWrite(motorPin3, LOW); //rotates motor
  digitalWrite(motorPin4, LOW);    // set the Pin motorPin2 LOW*/
  SoftPWMSet(motorPin1, 0);
  SoftPWMSet(motorPin2, 0);
  SoftPWMSet(motorPin3, 255);
  SoftPWMSet(motorPin4, 0);
  delay(length);
  SoftPWMSet(motorPin1, 0);
  SoftPWMSet(motorPin2, 0);
  SoftPWMSet(motorPin3, 0);
  SoftPWMSet(motorPin4, 0); 
}

void straight(int length)
{
  /*digitalWrite(motorPin2, HIGH); //rotates motor
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
  digitalWrite(motorPin3, HIGH); //rotates motor
  digitalWrite(motorPin4, LOW);    // set the Pin motorPin1 LOW
  delay(length); //waits
  digitalWrite(motorPin2, LOW); //rotates motor
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
  digitalWrite(motorPin3, LOW); //rotates motor
  digitalWrite(motorPin4, LOW);    // set the Pin motorPin1 LOW*/
  SoftPWMSet(motorPin1, 0);
  SoftPWMSet(motorPin2, 255);
  SoftPWMSet(motorPin3, 255);
  SoftPWMSet(motorPin4, 0);
  delay(length);
  SoftPWMSet(motorPin1, 0);
  SoftPWMSet(motorPin2, 0);
  SoftPWMSet(motorPin3, 0);
  SoftPWMSet(motorPin4, 0);
}

