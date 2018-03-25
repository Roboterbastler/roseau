#ifndef TIMESTAMP_HPP_
#define TIMESTAMP_HPP_

namespace motor_controller {

class Timestamp {
public:
    Timestamp();

    static Timestamp now();

    const unsigned long& getSeconds() const;
    const unsigned long& getMicros() const;
private:
    Timestamp(unsigned long seconds, unsigned long micros);

    unsigned long seconds_;
    unsigned long micros_;
};

}

#endif /* TIMESTAMP_HPP_ */
