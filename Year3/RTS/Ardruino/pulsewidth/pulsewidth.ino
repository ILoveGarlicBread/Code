

#define LED1 10
#define LED2 11
int potPin = A3;
int potVal = 0;
void setup() {
  pinMode(LED1, OUTPUT);  
  pinMode(LED2, OUTPUT);
  Serial.begin(2000000);

}
  // put your main code here, to run repeatedly:
void loop() {
  potVal = analogRead(potPin);
  // potVal = map(potVal, 0, 1023, -137, 255);
  analogWrite(LED1, HIGH);      
  analogWrite(LED2, LOW); 
  int val = digitalRead(potPin);
  Serial.println(val, DEC);

} 
