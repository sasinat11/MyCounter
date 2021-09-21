#include "MyCounter.h"

#define PIN_BUTTON 0
#define PIN_LED LED_BUILTIN

MyCounter counter(PIN_BUTTON, PIN_LED);
//MyCounter counter(PIN_LED);
void setup() {
  //Serial setup
  Serial.begin(115200);
  counter.setTimeSecond(5);

}

void loop() {
  // counter event handler
  counter.loop();

}
