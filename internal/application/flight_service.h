#ifndef FLIGHT_SERVICE_H
#define FLIGHT_SERVICE_H

#include "../domain/attitude.h"
#include "../domain/motor_output.h"
#include "../domain/drone_command.h"

class FlightService {
    public:
        FlightService(float Kp, float Ki, float Kd);
        MotorOutput computeMotorOutput(DroneCommand& command, Attitude& attitude);

    private:
        float PID(float target, float current, float& integral, float& previousError);
        float pitchIntegral, rollIntegral;
        float pitchPrevError, rollPrevError;
}

#endif