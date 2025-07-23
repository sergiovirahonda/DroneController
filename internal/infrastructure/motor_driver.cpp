#include "motor_driver.h"
#include <Arduino.h>

MotorDriver::MotorDriver(
    int pin1,
    int pin2,
    int pin3,
    int pin4
) {
    m1 = pin1;
    m2 = pin2;
    m3 = pin3;
    m4 = pin4;
    Servo m1Servo;
    Servo m2Servo;
    Servo m3Servo;
    Servo m4Servo;

    m1Servo.attach(m1);
    m2Servo.attach(m2);
    m3Servo.attach(m3);
    m4Servo.attach(m4);
}

void MotorDriver::setMotorSpeeds(const MotorOutput& output) {
    m1Servo.writeMicroseconds(output.motor1Speed);
    m2Servo.writeMicroseconds(output.motor2Speed);
    m3Servo.writeMicroseconds(output.motor3Speed);
    m4Servo.writeMicroseconds(output.motor4Speed);
}