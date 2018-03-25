#include "Duration.hpp"

#include <limits.h>

namespace motor_controller {

Duration::Duration() :
    seconds_(0),
    micros_(0) {

}

Duration::Duration(const Timestamp& begin, const Timestamp& end) {
    if(begin.getSeconds() <= end.getSeconds()) {
        seconds_ = end.getSeconds() - begin.getSeconds();
    } else { /* overflow happened */
        seconds_ = end.getSeconds() + (ULONG_MAX - begin.getSeconds()) + 1;
    }

    if(begin.getMicros() <= end.getMicros()) {
        micros_ = end.getMicros() - begin.getMicros();
    } else { /* overflow happened */
        micros_ = end.getMicros() + (1000000UL - begin.getMicros()) + 1;
    }
}

const unsigned long& Duration::getSeconds() const {
    return seconds_;
}

const unsigned long& Duration::getMicros() const {
    return micros_;
}

}
