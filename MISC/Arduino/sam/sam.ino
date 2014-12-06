
#include <Servo.h>
Servo leftRightServo; 
int leftRightPos = 0; 

void setup() {
  
  leftRightServo.attach(6);

}

void loop() {
  for(leftRightPos=0;leftRightPos<360;leftRightPos+=10)
  {
    leftRightServo.write(leftRightPos);
  }
  
}
