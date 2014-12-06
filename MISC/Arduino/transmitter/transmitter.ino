#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN 9
#define CSN_PIN 10
#define JOYSTICK_X A0
#define JOYSTICK_Y A1

const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

RF24 radio(CE_PIN, CSN_PIN);
int joystick[2];

void setup()
{
Serial.begin(9600);
radio.begin();
radio.openWritingPipe(pipes[0]);
}

void loop()
{
joystick[0] = 1;
joystick[1] = 2;
radio.write( joystick, sizeof(joystick) );
}
