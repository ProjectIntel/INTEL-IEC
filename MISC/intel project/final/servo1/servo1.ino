

/* Radar Screen Visualisation for HC-SR-04
   Sends sensor readings for every degree moved by the servo
   values sent to serial port to be picked up by Processing 
*/

#include <Servo.h>                              // include the standard servo library
#include<LiquidCrystal.h>
LiquidCrystal lcd(11, 10, 8, 7, 6, 5);
Servo leftRightServo;                           // set a variable to map the servo
int leftRightPos = 0;                           // set a variable to store the servo position
const int numReadings = 10;                     // set a variable for the number of readings to take
int start = 0;                                  // the start of the current reading
int total = 0;                                  // the total of all readings
int average = 0;                                // the average
int echoPin = 2;                                // the SRF04's echo pin
int trigPin = 3;                                // the SRF04's init pin
unsigned long pulseTime = 0;                    // variable for reading the pulse
unsigned long distance = 0;                     // variable for storing distance

 
                                /* setup the pins, servo and serial port */

void setup() 
{
  leftRightServo.attach(9);                    // make the init pin an output:
  pinMode(trigPin, OUTPUT_FAST);                    // make the echo pin an input:
  pinMode(echoPin, INPUT_FAST);                     // initialize the serial port:
  Serial.begin(9600);
  lcd.begin(16, 2);
} 
 
                          /* begin rotating the servo and getting sensor values */

void loop() 
{
  for(leftRightPos = 0; leftRightPos < 180; leftRightPos+=1)    // going left to right.
 {
    leftRightServo.write(leftRightPos);
      for (start = 0; start<=numReadings;start++) {            // take x number of readings from the sensor and average them
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
    Serial.print("X");                                         // print leading X to mark the following value as degrees
    Serial.print(leftRightPos);                                // current servo position
    Serial.print("V");                                         // preceeding character to separate values
    Serial.println(average);                                   // average of sensor readings
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
  for(leftRightPos = 180; leftRightPos >=1; leftRightPos-=1)   // going right to left
   {
    leftRightServo.write(leftRightPos);
    for (start = 0; start<=numReadings;start++) {
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
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distance is: ");
    lcd.setCursor(0,1);
    lcd.print(distance);
    lcd.setCursor(5,1);
    lcd.print("cm");
  }
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

