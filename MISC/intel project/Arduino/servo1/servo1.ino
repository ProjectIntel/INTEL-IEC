

/* Radar Screen Visualisation for HC-SR-04
   Sends sensor readings for every degree moved by the servo
   values sent to serial port to be picked up by Processing 
*/

#include <Servo.h>                              // include the standard servo library
#include<LiquidCrystal.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <SD.h>
 

 
//const uint64_t pipes[1] = { 0xF0F0F0F0E1LL };
LiquidCrystal lcd(11, 10, 8, 7, 6, 5);
Servo leftRightServo;                           // set a variable to map the servo
int leftRightPos = 0;                           // set a variable to store the servo position
const int numReadings = 10;                     // set a variable for the number of readings to take
int start = 0;                                  // the start of the current reading
int total = 0;                                  // the total of all readings
int average = 0;                                // the average
int echoPin = 2;                                // the SRF04's echo pin
int trigPin = 3; 
//double val;                                       // the SRF04's init pin
//double x;
unsigned long pulseTime = 0;                    // variable for reading the pulse
unsigned long distance = 0;  // variable for storing distance
int  joystick[1];
int stick[1];
int x,y;
int k=0;
int arr[10];
int l=0;
 
RF24 radio(9,10);
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL,0xF0F0F0F0D2LL} ;
 
                                /* setup the pins, servo and serial port */

void setup(void) 
{
  leftRightServo.attach(6);                    // make the init pin an output:
  pinMode(trigPin, OUTPUT_FAST);                    // make the echo pin an input:
  pinMode(echoPin, INPUT_FAST);                     // initialize the serial port:
  Serial.begin(9600);
  lcd.begin(16, 2);
  radio.begin();
} 
 
                          
                                                                     /* begin rotating the servo and getting sensor values */

void loop(void) 
{
  
  

  for(leftRightPos = 0; leftRightPos < 180; leftRightPos+=60)    // going left to right.
 {
    
   ++k; ++l;
   leftRightServo.write(leftRightPos);
      for (start = 0; start<=numReadings;start++) {         // take x number of readings from the sensor and average them
        
        
        
       /* radio.openWritingPipe(pipes[0]);
        joystick[0] = -251;
        radio.write( joystick, sizeof(joystick) );         //rf1
        
        
        
        delay(1000);
        
        
        
        radio.openWritingPipe(pipes[1]);
        stick[0]=630;
        radio.write( stick, sizeof(stick) ); */             //rf2
       
       
       
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);                           // send signal
        delayMicroseconds(10);                                 // wait 50 microseconds for it to return
        digitalWrite(trigPin, LOW);                            // close signal
        pulseTime = pulseIn2(echoPin, HIGH);                    // calculate time for signal to return
        distance = pulseTime/58;                               // convert to centimetres
        total = total + distance;                              // update total
        delay(10);
      }
    average = total/numReadings;                               // create average reading
 
    if (start >= numReadings)  {                               // reset the counts when at the last item of the array
      start = 0;
      total = 0;
    }
    if(average>200)
      average=0;                                                //setting distance to zero for above 200cm
    Serial.print("X");                                         // print leading X to mark the following value as degrees
    Serial.print(leftRightPos);                                // current servo position
    Serial.print("V");                                         // preceeding character to separate values
    Serial.println(average);  
    
   /* x=average*cos((3.14/180)*leftRightPos);
    y=average*sin((3.14/180)*leftRightPos);
    File dataFile = SD.open("new.txt", FILE_WRITE);      //SD CARD WRITTING1
    String x1 = String(x);
    String y1 = String(y);
    dataFile.println(x1 + " " + y1);
    dataFile.close();
    
    dataFile=SD.open("new1.txt",FILE_WRITE);
    x=average*cos((3.14/180)*leftRightPos);
    x1=String(x);
    String k1=String(k);
    dataFile.println(x1 + " " + k1);
    dataFile.close();
    
    dataFile=SD.open("new2.txt",FILE_WRITE);
    y=average*sin((3.14/180)*leftRightPos);
    y1=String(x);
     k1=String(k);
    dataFile.println(y1 + " " + k1);
    dataFile.close();
    
    dataFile=SD.open("new3.txt",FILE_WRITE);
    String dist=String(average);
    String ang=String(leftRightPos);
    dataFile.println(dist + " " + ang);
    dataFile.close();
    
    if(l>2)
    {
      l=0;
    }
    else arr[l]=x;
    dataFile=SD.open("speed.txt",FILE_WRITE);
    int speed=arr[1]-arr[2];
    String speed1=String(speed);
    k1=String(k);
    dataFile.println(speed1 + " " + k1 );
    dataFile.close();*/
    
    
    
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distance is: ");
    lcd.setCursor(0,1);
    lcd.print(distance);
    lcd.setCursor(5,1);
    lcd.print("cm");
  }
  /*
  start going right to left after we got to 180 degrees
  same code as above
  */
  for(leftRightPos = 180; leftRightPos >=1; leftRightPos-=60)   // going right to left
   {
    leftRightServo.write(leftRightPos);
    for (start = 0; start<=numReadings;start++) {
      
      
        radio.openWritingPipe(pipes[0]);
        
        joystick[0] = 320;
        //Serial.println(joystick[0]);
        radio.write( joystick, sizeof(joystick) );         //rf1
        
        
        
        //delay(1000);
        
        
        
        radio.openWritingPipe(pipes[1]);
        stick[0]=420; 
        radio.write( stick, sizeof(stick) ); 
 
 
        
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      pulseTime = pulseIn2(echoPin, HIGH);
      distance = pulseTime/58;
      total = total + distance;
      delay(10);
    }
    average = total/numReadings;
    if (start >= numReadings)  {
      start = 0;
      total = 0;
    }
    Serial.print("X");
    Serial.print(leftRightPos);
    Serial.print("V");
    Serial.println(average);
    
    
    /* x=average*cos((3.14/180)*leftRightPos);
     y=average*sin((3.14/180)*leftRightPos);
    File dataFile = SD.open("new.txt", FILE_WRITE);      //SD CARD WRITTING2
    String x1 = String(x);
    String y1 = String(y);
    dataFile.println(x1 + " " + y1);
    dataFile.close();
    
    dataFile=SD.open("new1.txt",FILE_WRITE);
    x=average*cos((3.14/180)*leftRightPos);
    x1=String(x);
    String k1=String(k);
    dataFile.println(x1 + " " + k1);
    dataFile.close();
    
    
    dataFile=SD.open("new2.txt",FILE_WRITE);
    y=average*sin((3.14/180)*leftRightPos);
    y1=String(x);
    k1=String(k);
    dataFile.println(y1 + " " + k1);
    dataFile.close();
    
    dataFile=SD.open("new3.txt",FILE_WRITE);
    String dist=String(average);
    String ang=String(leftRightPos);
    dataFile.println(dist + " " + ang);
    dataFile.close();
    
    if(l>2)
    {
      l=0;
    }
    else arr[l]=x;
    dataFile=SD.open("speed.txt",FILE_WRITE);
    int speed=arr[1]-arr[2];
    String speed1=String(speed);
    k1=String(k);
    dataFile.println(speed1 + " " + k1 );
    dataFile.close();*/
    
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distance is: ");
    lcd.setCursor(0,1);
    lcd.print(distance);
    lcd.setCursor(5,1);
    lcd.print("cm");
  }
  //joystick[0] = 23;
  //joystick[1] = 2;
  
  //radio.write( joystick, sizeof(joystick) );
}
unsigned long pulseIn2(uint8_t pin, uint8_t state) {

    unsigned long pulseWidth = 0;
    unsigned long loopCount = 0;
    unsigned long loopMax = 5000000;

    // While the pin is *not* in the target state we make sure the timeout hasn't been reached.
    while ((digitalRead(pin)) != state) {
        if (loopCount++ == loopMax) {
            return 0;
        }
    }

    // When the pin *is* in the target state we bump the counter while still keeping track of the timeout.
    while ((digitalRead(pin)) == state) {
        if (loopCount++ == loopMax) {
            return 0;
        }
        pulseWidth++;
    }

    // Return the pulse time in microsecond!
    return pulseWidth ; // Calculated the pulseWidth //this is the value to be tweaked
}

