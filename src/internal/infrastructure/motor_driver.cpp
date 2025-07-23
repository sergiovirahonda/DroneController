#include "motor_driver.h"
#include <Arduino.h>
#include <Servo.h>

MotorDriver::MotorDriver(
    int pin1,
    int pin2,
    int pin3,
    int pin4
) {
    this->m1 = pin1;
    this->m2 = pin2;
    this->m3 = pin3;
    this->m4 = pin4;

    Servo m1Servo;
    Servo m2Servo;
    Servo m3Servo;
    Servo m4Servo;

    this->m1Servo = m1Servo;
    this->m2Servo = m2Servo;
    this->m3Servo = m3Servo;
    this->m4Servo = m4Servo;

    this->m1Servo.attach(this->m1);
    this->m2Servo.attach(this->m2);
    this->m3Servo.attach(this->m3);
    this->m4Servo.attach(this->m4);
}

void MotorDriver::setMotorSpeeds(MotorOutput& output) {
    int sp1 = output.getMotor1Speed();
    int sp2 = output.getMotor2Speed();
    int sp3 = output.getMotor3Speed();
    int sp4 = output.getMotor4Speed();
    this->m1Servo.writeMicroseconds(sp1);
    this->m2Servo.writeMicroseconds(sp2);
    this->m3Servo.writeMicroseconds(sp3);
    this->m4Servo.writeMicroseconds(sp4);
}