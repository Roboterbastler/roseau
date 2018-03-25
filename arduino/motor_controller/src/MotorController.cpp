#include "MotorController.h"

#include <ArduinoHardware.h>
#include <Servo.h>
#include <PID_v1.h>
#include <roseau_msgs/MotorSetPoint.h>
#include <ros.h>

#define LEFT_ENCODER_PIN 2
#define RIGHT_ENCODER_PIN 3

//#define TICKS_PER_REVOLUTION 128.0
//#define WHEEL_CIRCUMFERENCE_M 0.208

#define PID_KP 15.0
#define PID_KI 0.0
#define PID_KD 0.0

#define ESC_NEUTRAL_USEC 1500

#define PID_SAMPLE_TIME_MS 10
#define ENCODER_SAMPLE_TIME_MS 10

namespace motor {

// The ESC motor controller
static Servo motorController;

static volatile byte left_ticks;
static volatile byte right_ticks;
static byte left_ticks_acc;
static byte right_ticks_acc;

// forwards=true/backwards=false
static int8_t direction;

// measured ticks per second
static double tps_input;
static double tps_left = 0;
static double tps_right = 0;

// PWM value
static double pwm_output;
static uint16_t pwm_usec = ESC_NEUTRAL_USEC;

// setpoint ticks per second
static double tps_setpoint;

static PID motorPID(&tps_input, &pwm_output, &tps_setpoint, PID_KP, PID_KI, PID_KD, DIRECT);

static void left_encoder_cb() {
  static unsigned long last_tick = 0;
  left_ticks++;

  unsigned long dur = millis() - last_tick;
  tps_left = 1000.0 / (double)dur;
}

static void right_encoder_cb() {
  static unsigned long last_tick = 0;
  right_ticks++;

  unsigned long dur = millis() - last_tick;
  tps_right = 1000.0 / (double)dur;
}

double getPidOutput() {
  return pwm_output;
}

uint16_t getPwmUSec() {
  return pwm_usec;
}

void init() {
  // setup ESC motor controller
  motorController.attach(10);
  motorController.writeMicroseconds(ESC_NEUTRAL_USEC);

  // setup encoder
  pinMode(LEFT_ENCODER_PIN, INPUT);
  pinMode(RIGHT_ENCODER_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), left_encoder_cb, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), right_encoder_cb, CHANGE);

  left_ticks = 0;
  right_ticks = 0;
  left_ticks_acc = 0;
  right_ticks_acc = 0;
  
  tps_setpoint = 0.0;
  tps_input = 0.0;
  pwm_output = 0.0;
  
  direction = roseau_msgs::MotorSetPoint::FORWARDS;

  motorPID.SetMode(AUTOMATIC);
  motorPID.SetSampleTime(PID_SAMPLE_TIME_MS);
  motorPID.SetOutputLimits(0, 500);
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

  // update ESC PWM from PID output
  pwm_usec = ESC_NEUTRAL_USEC;
  switch(direction) {
  case roseau_msgs::MotorSetPoint::FORWARDS:
    pwm_usec = pwm_usec + (uint16_t)pwm_output;
    break;
  case roseau_msgs::MotorSetPoint::BACKWARDS:
    pwm_usec = pwm_usec - (uint16_t)pwm_output;
    break;
  }

  //pwm_usec = min(pwm_usec, 2000);
  //pwm_usec = max(pwm_usec, 1000);

  motorController.writeMicroseconds(pwm_usec);
}

void setDirection(int8_t dir) {
  direction = dir;
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

