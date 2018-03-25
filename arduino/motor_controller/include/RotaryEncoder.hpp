#ifndef ROTARYENCODER_HPP_
#define ROTARYENCODER_HPP_

#include <Arduino.h>

namespace motor_controller {

typedef struct {
    uint8_t ticks;
    double velocity;
} RotaryEncoderSample;

class RotaryEncoder {
public:
    RotaryEncoder(uint8_t pin);

    /**
     * Tick interrupt.
     */
    void tick();

    RotaryEncoderSample sample();

private:
    unsigned long lastTickTime;
    unsigned long lastSampleTickTime;
    unsigned long lastAvgTickDuration;

    uint8_t ticks;
    bool stopped;
};

unsigned long duration(const unsigned long& begin, const unsigned long& end);

}

#endif /* ROTARYENCODER_HPP_ */
