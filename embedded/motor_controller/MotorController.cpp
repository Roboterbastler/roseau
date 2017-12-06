#include "MotorController.h"

#include <ArduinoHardware.h>
#include <Servo.h>
#include <PID_v1.h>

#define LEFT_ENCODER_PIN 2
#define RIGHT_ENCODER_PIN 3

//#define TICKS_PER_REVOLUTION 128.0
//#define WHEEL_CIRCUMFERENCE_M 0.208

#define PID_KP 0.0
#define PID_KI 0.0
#define PID_KD 0.0

#define ESC_NEUTRAL 127

#define PID_SAMPLE_TIME_MS 10
#define ENCODER_SAMPLE_TIME_MS 10

namespace motor {

// The ESC motor controller
static Servo motorController;

static volatile byte left_ticks;
static volatile byte right_ticks;
static byte left_ticks_acc;
static byte right_ticks_acc;

static bool forwards;

// measured ticks per second
static double tps_input;

// PWM value
static double pwm_output;

// setpoint ticks per second
static double tps_setpoint;

static PID motorPID(&tps_input, &pwm_output, &tps_setpoint, PID_KP, PID_KI, PID_KD, DIRECT);

static void left_encoder_cb() {
  left_ticks++;
}

static void right_encoder_cb() {
  right_ticks++;
}

void init() {
  // setup ESC motor controller
  motorController.attach(10);
  motorController.write(90);

  // setup encoder
  pinMode(LEFT_ENCODER_PIN, INPUT);
  pinMode(RIGHT_ENCODER_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), left_encoder_cb, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), right_encoder_cb, RISING);

  left_ticks = 0;
  right_ticks = 0;
  left_ticks_acc = 0;
  right_ticks_acc = 0;
  
  tps_setpoint = 0.0;
  tps_input = 0.0;
  pwm_output = 0.0;
  
  forwards = true;

  motorPID.SetMode(AUTOMATIC);
  motorPID.SetSampleTime(PID_SAMPLE_TIME_MS);
}

static void getTicks(byte *left, byte *right) {
  noInterrupts();
  *left = left_ticks;
  *right = right_ticks;
  left_ticks = 0;
  right_ticks = 0;
  interrupts();
}

void update() {
  static unsigned long lastEncoderSampleTime = 0;

  unsigned long now = millis();
  unsigned long lastEncoderDur = now - lastEncoderSampleTime;
  if(lastEncoderDur >= ENCODER_SAMPLE_TIME_MS) {
    // sample encoders
    byte lt, rt;
    getTicks(&lt, &rt);
    left_ticks_acc += lt;
    right_ticks_acc += rt;
    double ticks = (double)(lt + rt) / 2.0;
    tps_input = ticks * (1000. / (double)lastEncoderDur);
    
    lastEncoderSampleTime = now;
  }

  motorPID.Compute();

  // TODO: update ESC PWM from PID output
}

void setVelocity(double tps) {
  tps_setpoint = tps;
}

byte getLeftOdom() {
  byte t = left_ticks_acc;
  left_ticks_acc = 0;
  return t;
}

byte getRightOdom() {
  byte t = right_ticks_acc;
  right_ticks_acc = 0;
  return t;
}

}

