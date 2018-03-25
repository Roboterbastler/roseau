#ifndef QUADENCODER_HPP_
#define QUADENCODER_HPP_

#include <Arduino.h>

namespace motor_controller {

class QuadEncoder {
public:
    QuadEncoder(uint8_t pinA, uint8_t pinB);

    void change();

    int readSteps();
    int peekSteps() const;

private:
    uint8_t readEncoder() const;

private:
    uint8_t _pinA;
    uint8_t _pinB;

    uint8_t prevVal;
    int steps;
};


}

#endif /* QUADENCODER_HPP_ */
