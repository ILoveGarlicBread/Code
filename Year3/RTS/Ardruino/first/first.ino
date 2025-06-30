// Author: Lam
// Date: 26/6
// Description: First Arduino program


#define OFF HIGH
#define ON LOW
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
void setup() {
  // put your setup code here, to run once:
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
digitalWrite(LED1, OFF);
digitalWrite(LED2, OFF);
digitalWrite(LED3, OFF);
digitalWrite(LED4, OFF);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, ON);
  delay(200);
  digitalWrite(LED2, ON);
  delay(200);
  digitalWrite(LED3, ON);
  delay(200);
  digitalWrite(LED4, ON);
  delay(200);
  digitalWrite(LED2, OFF);
  delay(200);
  digitalWrite(LED4, OFF);
  delay(200);
  digitalWrite(LED3, OFF);
  delay(200);
  digitalWrite(LED1, OFF);
  delay(200);
}
