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
volatile unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 500;
volatile bool mode = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(SWCH,INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(SWCH), switchMode, FALLING);
  for(int pin = 5; pin < 13; pin++){
    pinMode(pin,OUTPUT);
    digitalWrite(pin,OFF);
  }
}
void switchMode(){
  unsigned long currentTime = millis();
  if (currentTime - lastDebounceTime > debounceDelay) {
    mode = !mode;
    lastDebounceTime = currentTime;
  if (mode){
    Serial.println("running...");
  }
  else{
    Serial.println("idle...");
  }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mode){
    digitalWrite(LED1, OFF);
    digitalWrite(LED8, OFF);
  for (int pin = 5; pin < 13; pin ++){
    for(int i = 0; i < 15; i++){
      digitalWrite(pin, ON);
      delay(2);
      digitalWrite(pin, OFF);
      delay(2);
    }
  delayMicroseconds(2500);
    }
  } else{
    for (int pin = 6; pin < 12; pin ++ ){
      digitalWrite(pin, OFF);
    }
    digitalWrite(LED1, ON);
    digitalWrite(LED8, ON);
  }
 }
 
