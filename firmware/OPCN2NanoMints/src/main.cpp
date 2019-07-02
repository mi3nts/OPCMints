#include <Arduino.h>
#include "OPCN2NanoMints.h"

#define CS 10
OPCN2NanoMints OPCN2(CS);
bool OPCN2Online;

void setup() {

  Serial.begin(9600);
  Serial.println("Serial Port Open");

 OPCN2Online = OPCN2.initialize();
 if(OPCN2Online)
  {
  Serial.println("OPC Initialized");
  }else
  {
  Serial.println("OPC Not Initialized");
  }
  delay(1000);
}

// the loop routine runs over and over again forever:
void loop()
 {
 if(OPCN2Online)
   {
    delay(10000);
    OPCN2.readHistogramData();
   }
}
