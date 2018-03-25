#include "EscMotorController.hpp"

#include "PinChangeInterrupt.h"

namespace motor_controller {

#define LEFT_ENCODER_PIN 2
#define RIGHT_ENCODER_PIN 3
#define ESC_PWM_PIN 10
#define MOTOR_ENCODER_A_PIN A0
#define MOTOR_ENCODER_B_PIN A1

#define ESC_NEUTRAL_PWM_USEC 1500
#define PID_MAX_SAMPLE_PERIOD_MS 100
#define PID_MIN_SAMPLE_PERIOD_MS 10
#define STEPS_PER_ROUND 12.0

EscMotorController& EscMotorController::instance() {
    static EscMotorController _instance;

    return _instance;
}

// static void leftRearEncoderIsr() {
//     EscMotorController::instance()._leftRearEncoder.tick();
// }

// static void rightRearEncoderIsr() {
//     EscMotorController::instance()._rightRearEncoder.tick();
// }

static void motorQuadEcoderIsr() {
    EscMotorController::instance()._motorEncoder.change();
}

EscMotorController::EscMotorController() : 
    _leftRearEncoder(LEFT_ENCODER_PIN), 
    _rightRearEncoder(RIGHT_ENCODER_PIN),
    _motorEncoder(MOTOR_ENCODER_A_PIN, MOTOR_ENCODER_B_PIN),
    _pidKp(2.0), _pidKi(0.1), _pidKd(0.0),
    _motorPid(&_pidInput, &_pidOutput, &_pidSetPoint, _pidKp, _pidKi, _pidKd, DIRECT) {

    _esc.attach(ESC_PWM_PIN);
    _esc.writeMicroseconds(ESC_NEUTRAL_PWM_USEC);

    _motorPid.SetMode(AUTOMATIC);
    _motorPid.SetSampleTime(PID_MIN_SAMPLE_PERIOD_MS);
    _motorPid.SetOutputLimits(-500, 500);

    tLastEncoderSample = millis();

    // attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), leftRearEncoderIsr, CHANGE);
    // attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), rightRearEncoderIsr, CHANGE);

    PCattachInterrupt(MOTOR_ENCODER_A_PIN, motorQuadEcoderIsr, CHANGE);
    PCattachInterrupt(MOTOR_ENCODER_B_PIN, motorQuadEcoderIsr, CHANGE);
}

void EscMotorController::update() {
    unsigned long now = millis();
    unsigned long duration = now - tLastEncoderSample;

    if(duration < PID_MIN_SAMPLE_PERIOD_MS) {
        return;
    }

    int steps = _motorEncoder.peekSteps();

    if ((steps != 0) || (duration >= PID_MAX_SAMPLE_PERIOD_MS)) {
        // update PID
        steps = _motorEncoder.readSteps();
        double rpm = ((double)steps / (double)duration) * (1000.0 / STEPS_PER_ROUND);
        _pidInput = rpm;
    }

    // Update PID
    if(_motorPid.Compute()) {
        _esc.writeMicroseconds(ESC_NEUTRAL_PWM_USEC + _pidOutput);
    }
}

void EscMotorController::setPoint(double rpm) {
    _pidSetPoint = rpm;
}

double EscMotorController::getRpm() const {
    return _pidInput;
}

}
