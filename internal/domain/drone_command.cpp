#include "drone_command.h"

DroneCommand::DroneCommand(
    int pitch,
    int roll,
    int yaw,
    int throttle,
    unsigned long timestamp
) {
    this->pitch = pitch;
    this->roll = roll;
    this->yaw = yaw;
    this->throttle = throttle;
    this->timestamp = timestamp;
}

// Setters

void DroneCommand::setPitch(int pitch) {
    this->pitch = pitch;
}

void DroneCommand::setRoll(int roll) {
    this->roll = roll;
}

void DroneCommand::setYaw(int yaw) {
    this->yaw = yaw;
}

void DroneCommand::setThrottle(int throttle) {
    this->throttle = throttle;
}

void DroneCommand::setTimestamp(unsigned long timestamp) {
    this->timestamp = timestamp;
}

void DroneCommand::reset() {
    pitch = 0;
    roll = 0;
    yaw = 0;
    throttle = 0;
    timestamp = 0;
}

// Getters

int DroneCommand::getPitch() {
    return this->pitch;
}

int DroneCommand::getRoll() {
    return this->roll;
}

int DroneCommand::getYaw() {
    return this->yaw;
}

int DroneCommand::getThrottle() {
    return this->throttle;
}

unsigned long DroneCommand::getTimestamp() {
    return this->timestamp;
}