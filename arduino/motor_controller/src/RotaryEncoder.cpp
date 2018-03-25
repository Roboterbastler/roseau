#include "RotaryEncoder.hpp"

#include <ArduinoHardware.h>
#include <limits.h>

#define MIN_VELOCITY 1.0

namespace motor_controller {

RotaryEncoder::RotaryEncoder(uint8_t pin) {
    ticks = 0;
    lastAvgTickDuration = ULONG_MAX;
    pinMode(pin, INPUT);
}

void RotaryEncoder::tick() {
    ticks++;
    lastTickTime = micros();
}

RotaryEncoderSample RotaryEncoder::sample() {
    noInterrupts();

    unsigned long now = micros();

    // get and reset ticks
    uint8_t ticksCopy = ticks;
    ticks = 0;

    // get timestamp of last tick
    unsigned long lastTickTimeCopy = lastTickTime;

    interrupts();

    RotaryEncoderSample sample;
    sample.ticks = ticksCopy;

    unsigned long avgTickDuration;
    double currentVelocity;

    if(sample.ticks > 0) {
        avgTickDuration = duration(lastSampleTickTime, lastTickTimeCopy) / sample.ticks;
        lastAvgTickDuration = avgTickDuration;
        lastSampleTickTime = lastTickTimeCopy;
    } else {
        avgTickDuration = max(duration(lastSampleTickTime, now), lastAvgTickDuration);
    }

    currentVelocity = 1000000. / (double) avgTickDuration;

    if(currentVelocity < MIN_VELOCITY) {
        currentVelocity = 0.0;
    }

    sample.velocity = currentVelocity;

    return sample;
}

unsigned long duration(const unsigned long& begin, const unsigned long& end) {
    unsigned long duration;

    if(begin <= end) {
        duration = end - begin;
    } else { /* overflow happened */
        duration = end + (ULONG_MAX - begin) + 1;
    }

    return duration;
}

}
