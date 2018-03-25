#include "Timestamp.hpp"

#include <Arduino.h>

namespace motor_controller {

Timestamp::Timestamp() : 
    seconds_(0), 
    micros_(0) {
}

Timestamp::Timestamp(unsigned long seconds, unsigned long micros) : 
    seconds_(seconds), 
    micros_(micros) {
}

Timestamp Timestamp::now() {
    noInterrupts();
    /* FIXME: What if overflow happens in between? */
    unsigned long s = millis();
    unsigned long m = micros();
    interrupts();

    s = s / 1000UL;
    m = m % 1000000UL;
    return Timestamp(s, m);
}

const unsigned long& Timestamp::getSeconds() const {
    return seconds_;
}

const unsigned long& Timestamp::getMicros() const {
    return micros_;
}

}
