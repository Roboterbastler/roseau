#include "QuadEncoder.hpp"

#include <ArduinoHardware.h>

namespace motor_controller {

QuadEncoder::QuadEncoder(uint8_t pinA, uint8_t pinB) : 
    _pinA(pinA), 
    _pinB(pinB)
{
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);

    prevVal = readEncoder();
    steps = 0;
}

void QuadEncoder::change() {
    uint8_t val = readEncoder();
    uint8_t change = (prevVal << 2) | val;
    prevVal = val;

    steps++;
    return;

    switch(change) {
        // No change
        case 0b0000:
        case 0b0101:
        case 0b1010:
        case 0b1111:
        break;

        // Forwards
        case 0b0001:
        case 0b0111:
        case 0b1110:
        case 0b1000:
        steps++;
        break;

        // Backwards
        case 0b0010:
        case 0b1011:
        case 0b1101:
        case 0b0100:
        steps--;
        break;

        // Invalid
        case 0b0011:
        case 0b0110:
        case 0b1001:
        case 0b1100:
        break;
    }
}

uint8_t QuadEncoder::readEncoder() const {
     return digitalRead(_pinA) | (digitalRead(_pinB) << 1);
}

int QuadEncoder::readSteps() {
    noInterrupts();
    int tmp = steps;
    steps = 0;
    interrupts();
    return tmp;
}

int QuadEncoder::peekSteps() const {
    return steps;
}

}