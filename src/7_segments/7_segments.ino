#include "digit.h"




void setup() {
  // put your setup code here, to run once:
  setAllOutput();
 Serial.begin(9600);
 Digit::init(); 
}

void setAllOutput()
{
 pinMode(segA, OUTPUT);
 pinMode(segB, OUTPUT);
 pinMode(segC, OUTPUT);
 pinMode(segD, OUTPUT);
 pinMode(segE, OUTPUT);
 pinMode(segF, OUTPUT);
 pinMode(segG, OUTPUT);
 pinMode(segDec, OUTPUT);
  
 pinMode(dig1, OUTPUT);
 pinMode(dig2, OUTPUT);
 pinMode(dig3, OUTPUT);
 pinMode(dig4, OUTPUT);
}

int n = 0;
void loop() {   
  
  int a = n / 1000;
  int b = (n / 100) % 10;
  int c = (n / 10) % 10;
  int d = n % 10; 
  n++;
  
  Digit::resetPosition();
  Digit::setPosition(1);
  Digit::setNumber(48 + a); // 48 is '0' in ASCII
  delay(8);
  Digit::resetPosition();
   Digit::setPosition(2);
  Digit::setNumber(48 + b);
  delay(8);
  Digit::resetPosition();
  Digit::setPosition(3);
  Digit::setNumber(48 + c);
  delay(8);
  Digit::resetPosition();
  Digit::setPosition(4);
  Digit::setNumber(48 + d);
  delay(8);
}
