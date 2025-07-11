// Author: Lam
// Date: 19/5/2025
// Description: Approach light
#define OFF HIGH
#define ON LOW
#define LED1 5
#define LED2 6
#define LED3 7
#define LED4 8
#define LED5 9
#define LED6 10
#define LED7 11
#define LED8 12
#define SWCH 2
void setup() {
  // put your setup code here, to run once:
  pinMode(SWCH,INPUT_PULLUP);
  for(int pin = 5; pin < 13; pin++){
    pinMode(pin,OUTPUT);
    digitalWrite(pin,OFF);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int pin = 5; pin < 13; pin ++){
          while(digitalRead(SWCH) == ON){
        delay(10);
      }
      digitalWrite(pin, ON);
      delay(2);
      digitalWrite(pin, OFF);
      delay(60);
      delayMicroseconds(500);
      while (digitalRead(SWCH) == ON) {
        delay(10);
      }
    
  }
 }
 
