#ifndef ESCMOTORCONTROLLER_HPP_
#define ESCMOTORCONTROLLER_HPP_

#include <ros.h>
#include <Servo.h>
#include <PID_v1.h>
#include "RotaryEncoder.hpp"
#include "QuadEncoder.hpp"

namespace motor_controller {

class EscMotorController {
public:
    static EscMotorController& instance();

    RotaryEncoder _leftRearEncoder;
    RotaryEncoder _rightRearEncoder;
    QuadEncoder _motorEncoder;

    void update();
    void setPoint(double rpm);
    double getRpm() const;

protected:
    // This is a singleton
    EscMotorController();

    double _pidInput;
    double _pidOutput;
    double _pidSetPoint;
    double _pidKp;
    double _pidKi;
    double _pidKd;

    PID _motorPid;

    Servo _esc;

    unsigned long tLastEncoderSample;
};

}

#endif /* ESCMOTORCONTROLLER_HPP_ */
