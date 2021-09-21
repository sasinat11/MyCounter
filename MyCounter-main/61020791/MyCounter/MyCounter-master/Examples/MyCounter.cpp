#include "MyCounter.h"

MyCounter::MyCounter(const int btnPin,
                     const int ledPin,
                     const int timeSecond,
                     const bool btnPinActive,
                     const bool ledPinActive) {

  this->btnPin = btnPin;
  this->ledPin = ledPin;
  this->btnPinActive = btnPinActive;
  this->ledPinActive = ledPinActive;

  setTimeSecond(timeSecond);
  setBlink(true);


  pinMode(this->ledPin, OUTPUT);

}

MyCounter::~MyCounter()
{
  // do nothing
}

void MyCounter::setTimeSecond(const int timeSecond) {
  this->timeSecond = timeSecond;
}
void MyCounter::setBlink(bool blink) {
  this->blink = blink;
  if (this->blink)
    _next = millis() + 500;
}
void MyCounter::loop()
{
  uint32_t cur = millis();
  int countDown = timeSecond;
  if (blink) {
    while (cur <= (timeSecond + 1) * 1000)
    {
      if (cur >= _next) {
        digitalWrite(ledPin, !digitalRead(ledPin));
        _next = cur + 500;
        if (digitalRead(btnPin) == this->btnPinActive) {
          if (digitalRead(ledPin) == this->ledPinActive) {

            if ( countDown == 0) {
              Serial.println("Time Up!!!");
            } else {
              Serial.print("Counter remian ");
              Serial.print(countDown--) ;
              Serial.println(" seconds");
            }
          }
        }
      }
      cur = millis();
    }
  } else {
    // turn off led
    digitalWrite(ledPin, this->ledPinActive == LOW ? HIGH : LOW);
    Serial.print("status");
    Serial.println(digitalRead(ledPin)) ;
  }
}
