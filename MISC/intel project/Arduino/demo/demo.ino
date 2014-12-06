#define trigPin 8
#define echoPin 7

void setup() {

Serial.begin (9600);

pinMode(trigPin, OUTPUT_FAST);
pinMode(echoPin, INPUT_FAST);
}

void loop() {
long duration, distance;
digitalWrite(trigPin, LOW); // Added this line
delayMicroseconds(2); // Added this line

digitalWrite(trigPin, HIGH);
// delayMicroseconds(1000); - Removed this line
delayMicroseconds(10); // Added this line
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance >= 200 || distance <= 0){
Serial.println("Out of range");
}
else {
Serial.print(distance);

Serial.println(" cm");

}
delay(500);
}


