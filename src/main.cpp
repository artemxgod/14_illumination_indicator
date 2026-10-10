#include <Arduino.h>

const int leds[] = {3, 4, 5, 6};
const int LIGHT = A0;       // фоторезистор на A0
const int MIN_LIGHT = 200;  // нижний порог освещённости
const int MAX_LIGHT = 900;  // верхний порог освещённости
int illuminationLevel = 0;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
 }
}

void loop() {
  illuminationLevel = analogRead(LIGHT);
  illuminationLevel = map(illuminationLevel, MIN_LIGHT, MAX_LIGHT, 4, 0);
  illuminationLevel = constrain(illuminationLevel, 0, 4);

  for (int i = 0; i < 4; i++) {
    if (i >= illuminationLevel)
      digitalWrite(leds[i], HIGH);
    else 
      digitalWrite(leds[i], LOW);    
  }
  delay(1000);
}
