#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "internal/domain/motor_output.h"
#include <Servo.h>

class MotorDriver {
    public:
        MotorDriver(int pin1, int pin2, int pin3, int pin4);
        void setMotorSpeeds(MotorOutput& output);

    private:
        int m1;
        int m2;
        int m3;
        int m4;
        Servo m1Servo;
        Servo m2Servo;
        Servo m3Servo;
        Servo m4Servo;
};

#endif