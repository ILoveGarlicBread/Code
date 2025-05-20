#define OFF HIGH
#define ON LOW

#define SWCH1 2
#define SWCH2 3
unsigned long time1;
unsigned long time2;
float timediff;
void setup() {
  // put your setup code here, to run once:
  pinMode(SWCH1,INPUT_PULLUP);
  pinMode(SWCH2,INPUT_PULLUP);
  Serial.begin(9600);
  delay(1000);
  Serial.println("Hello this is a reaction Test of Lam");
}
void loop() {
  while(digitalRead(SWCH1) == OFF){
    delay(10);
  }
  Serial.println("Switch 1 activated");
  time1 = micros();
  while(digitalRead(SWCH2) == OFF){
    delay(10);
    }
  Serial.println("Switch 2 activated");
  time2 = micros();
  timediff = ((float)time2 - (float)time1)/1000000;
  Serial.print("Time1: ");
  Serial.println(time1);
  Serial.print("Time2: ");
  Serial.println(time2);
  Serial.print("Timediff: ");
  Serial.println(timediff,6);
  Serial.println();

}
