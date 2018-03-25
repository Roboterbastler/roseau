#ifndef DURATION_HPP_
#define DURATION_HPP_

#include "Timestamp.hpp"

namespace motor_controller {

class Duration {
public:
    Duration();
    Duration(const Timestamp& begin, const Timestamp& end);

    const unsigned long& getSeconds() const;
    const unsigned long& getMicros() const;
private:
    unsigned long seconds_;
    unsigned long micros_;
};

Duration operator/(const Duration& duration, unsigned int divisor);

}

#endif /* DURATION_HPP_ */
