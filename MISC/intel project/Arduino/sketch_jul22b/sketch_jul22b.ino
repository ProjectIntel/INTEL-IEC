#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"
 
//
// Hardware configuration
//
 
// Set up nRF24L01 radio on SPI bus plus pins 9 & 10 
 
RF24 radio(9,10);
