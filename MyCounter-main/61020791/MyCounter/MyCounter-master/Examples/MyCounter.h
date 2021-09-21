#ifndef _MYCOUNTER_H_
#define _MYCOUNTER_H_

#include <Arduino.h>

#define DEFAULT_ACTIVE LOW

class MyCounter {
  private: // private data
    int btnPin;
    int ledPin;
    int timeSecond;
    bool btnPinActive;
    bool ledPinActive;
    bool blink;
    uint32_t _next;
  public:
    MyCounter(const int btnPin,
              const int ledPin,
              const int timeSecond = 10,
              const bool btnPinActive = LOW,
              const bool ledPinActive = LOW);
    ~MyCounter();

    void setTimeSecond(const int timeSecond);

    void setBlink(bool blink); // true: blink, false: turn off

    void loop();
    
};

#endif
