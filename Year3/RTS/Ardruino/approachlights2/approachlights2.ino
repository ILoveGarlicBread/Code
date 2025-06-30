
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
#define SWCH1 2
#define SWCH2 3
int potPin = A3;
int potVal = 0;
volatile bool configMode = true;
volatile bool runMode = false;
volatile unsigned long lastDebounceTime1 = 0;
volatile unsigned long lastDebounceTime2 = 0;
const unsigned long debounceDelay = 500;
volatile bool mode = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(SWCH1,INPUT_PULLUP);
  pinMode(SWCH2,INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(SWCH1), config, FALLING);
  attachInterrupt(digitalPinToInterrupt(SWCH2), run, FALLING);
  for(int pin = 5; pin < 13; pin++){
    pinMode(pin,OUTPUT);
    digitalWrite(pin,OFF);
  }
}
void config(){
  unsigned long currentTime = millis();
  if (currentTime - lastDebounceTime1 > debounceDelay) {
     configMode = true; 
     runMode = false;
    lastDebounceTime1 = currentTime;
    Serial.println("configuring...");
  }
}

void run(){
  unsigned long currentTime = millis();
  if (currentTime - lastDebounceTime2 > debounceDelay) {
     configMode = false; 
     runMode = true;
    lastDebounceTime2 = currentTime;
    Serial.println("running...");
  }
}
  // put your main code here, to run repeatedly:
void loop() {
int sequenceLength = map(potVal, 0, 1023, 1, 9);
const int sequenceTime = 500;
int timePerLed = sequenceTime / sequenceLength;
int ledDelay = timePerLed - 2;
  if(runMode){
  for(int pin = 5; pin < 13; pin++){
    pinMode(pin,OUTPUT);
    digitalWrite(pin,OFF);
  }
  for (int i = 0; i<sequenceLength; i++ ){
    int pin = 5+i;
    digitalWrite(pin, ON);
    delay(2);
    digitalWrite(pin, OFF);
    delay(ledDelay );
    
  }

  
  } else{
  potVal = analogRead(potPin);
  int sequenceLength = map(potVal, 0, 1023, 1, 9);
  Serial.println(potVal);


  for (int i = 0; i < 8; i++) {
    int pin = 5 + i;
    if (i < sequenceLength) {
      digitalWrite(pin, ON);  
    } else {
      digitalWrite(pin, OFF);
    }
  }
 }
} 
