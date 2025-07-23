#include "flight_service.h"
#include "internal/domain/motor_output.h"
#include "internal/domain/drone_command.h"

#include <Arduino.h>

FlightService::FlightService(float Kp, float Ki, float Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->pitchIntegral = 0;
    this->rollIntegral = 0;
    this->pitchPrevError = 0;
    this->rollPrevError = 0;
}

MotorOutput FlightService::computeMotorOutput(DroneCommand& command, Attitude& attitude) {
    MotorOutput motorOutput;

    float pitchCorrection = PID(command.getPitch(), attitude.getPitch());
    float rollCorrection = PID(command.getRoll(), attitude.getRoll());

    int throttlePWM = map(command.getThrottle(), 0, 100, 1000, 2000);
    int motor1Speed = throttlePWM + pitchCorrection + rollCorrection;
    int motor2Speed = throttlePWM + pitchCorrection - rollCorrection;
    int motor3Speed = throttlePWM - pitchCorrection + rollCorrection;
    int motor4Speed = throttlePWM - pitchCorrection - rollCorrection;
    motor1Speed = constrain(motor1Speed, 1000, 2000);
    motor2Speed = constrain(motor2Speed, 1000, 2000);
    motor3Speed = constrain(motor3Speed, 1000, 2000);
    motor4Speed = constrain(motor4Speed, 1000, 2000);

    motorOutput.setMotor1Speed(motor1Speed);
    motorOutput.setMotor2Speed(motor2Speed);
    motorOutput.setMotor3Speed(motor3Speed);
    motorOutput.setMotor4Speed(motor4Speed);

    return motorOutput;
}

float FlightService::PID(float target, float current) {
    float error = target - current;
    this->pitchIntegral += error;
    float derivative = error - this->pitchPrevError;
    this->pitchPrevError = error;
    return this->Kp * error + this->Ki * this->pitchIntegral + this->Kd * derivative;
}
