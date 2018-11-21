#ifndef __HEART_BEAT__
#define __HEART_BEAT__

#include "Arduino.h"

class HeartBeat {
  private:
    int heartBeatPin = 0;
    unsigned int period = 1000;

  public:
    HeartBeat(int pin);
    void run();
};


#endif
