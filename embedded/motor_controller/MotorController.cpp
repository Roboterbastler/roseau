#include "MotorController.h"

#include <ArduinoHardware.h>
#include <Servo.h>
#include <PID_v1.h>

#define LEFT_ENCODER_PIN 2
#define RIGHT_ENCODER_PIN 3

#define TICKS_PER_REVOLUTION 128.0
#define WHEEL_CIRCUMFERENCE_M 0.208

#define PID_KP 0.0
#define PID_KI 0.0
#define PID_KD 0.0

#define PUBLISH_RATE 10

namespace motor {

// The ESC motor controller
Servo motorController;

volatile byte left_ticks;
volatile byte right_ticks;
unsigned long last_time;

unsigned long last_publish_time;

double rpm_input;
double rpm_output;
double rpm_setpoint;

PID motorPID(&rpm_input, &rpm_output, &rpm_setpoint, PID_KP, PID_KI, PID_KD, DIRECT);

ros::Publisher("", );

void init(ros::NodeHandle &nh) {
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
  rpm_setpoint = 0.0;
  rpm_input = 0.0;
  rpm_output = 0.0;
  last_time = millis();
  last_publish_time = millis();

  motorPID.SetMode(AUTOMATIC);  

  nh.loginfo("Motor controller initialized.");
}

void update() {
  byte left_ticks, right_ticks;
  unsigned long dur;

  getTicks(&left_ticks, &right_ticks, &dur);

  if(dur == 0) {
    dur = 1;
  }

  byte avg_ticks = (left_ticks + right_ticks) / 2;

  // convert to ticks per second and update PID input
  rpm_input = (double)avg_ticks * 1000.0 / (double)dur;

  motorPID.Compute();

  // TODO: update ESC PWM from PID output

  // check if velocity should be published
  unsigned long pubDur = millis() - last_publish_time;
  
  if(pubDur > (1000 / PUBLISH_RATE)) {
    last_publish_time = millis();
    
    // distance in m
    double dLeft = WHEEL_CIRCUMFERENCE_M * (double)left_ticks / TICKS_PER_REVOLUTION;
    double dRight = WHEEL_CIRCUMFERENCE_M * (double)right_ticks / TICKS_PER_REVOLUTION;
  
    // compute velocities in m/s^2
    double d = (double)dur / 1000.0;
    double left = dLeft / d;
    double right = dRight / d;
  }
}

void setVelocity(double vel) {
  
}

void getTicks(byte *left, byte *right, unsigned long *dur) {
  unsigned long now = millis();
  *dur = now - last_time;
  last_time = now;

  *left = left_ticks;
  *right = right_ticks;
  left_ticks = 0;
  right_ticks = 0;
}

void left_encoder_cb() {
  left_ticks++;
}

void right_encoder_cb() {
  right_ticks++;
}

}

