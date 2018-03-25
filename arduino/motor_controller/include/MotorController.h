#include <Arduino.h>

namespace motor {

void init();

void update();

void setVelocity(double tps);
void setDirection(int8_t dir);

byte getLeftOdom();
byte getRightOdom();

double getPidOutput();
uint16_t getPwmUSec();

}

