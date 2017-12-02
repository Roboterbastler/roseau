#include <Arduino.h>

namespace motor {

void init();

void update();

void setVelocity(double tps);

byte getLeftOdom();
byte getRightOdom();

}

