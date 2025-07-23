#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "../domain/motor_output.h"

class MotorDriver {
    public:
        MotorDriver(int pin1, int pin2, int pin3, int pin4);
        void setMotorSpeeds(const MotorOutput& output);

    private:
        int m1;
        int m2;
        int m3;
        int m4;
};

#endif