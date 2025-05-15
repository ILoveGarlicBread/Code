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

#define LIGHT_ON_TIME 2     // ms
#define BLINK_COUNT    15   // 15 times
#define STEP_DELAY     3    // ms delay between LEDs

void setup() {
  for (int pin = 5; pin <= 12; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, OFF);
  }
}

void loop() {
  for (int pin = 5; pin <= 12; pin++) {
    // blink LED multiple times
    for (int i = 0; i < BLINK_COUNT; i++) {
      digitalWrite(pin, ON);
      delay(LIGHT_ON_TIME);
      digitalWrite(pin, OFF);
      delay(LIGHT_ON_TIME);
    }
    delay(STEP_DELAY); // short delay before next LED
  }
}
