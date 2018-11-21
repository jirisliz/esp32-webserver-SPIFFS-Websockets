#include "heartBeat.h"

HeartBeat::HeartBeat(int pin)
{
    heartBeatPin = pin;
}

void HeartBeat::setup()
{
    pinMode(heartBeatPin, OUTPUT);
    digitalWrite(heartBeatPin, true);
}

void HeartBeat::run()
{
    const int periodMs = period;
    static unsigned long previousMs = millis();
    static bool ledState = false;

    unsigned long currentMs = millis();
    unsigned long difMs = currentMs - previousMs;

    if(difMs == 7*periodMs/10)
    {
    digitalWrite(heartBeatPin, true);
    }
    if(difMs == 8*periodMs/10)
    {
    digitalWrite(heartBeatPin, false);
    }
    if(difMs == 9*periodMs/10)
    {
    digitalWrite(heartBeatPin, true);
    }
    if(difMs >= periodMs)
    {
    previousMs = currentMs;
    digitalWrite(heartBeatPin, false);
    }
}
