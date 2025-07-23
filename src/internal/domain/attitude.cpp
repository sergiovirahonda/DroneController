#include "attitude.h"

Attitude::Attitude(int pitch, int roll) {
    this->pitch = pitch;
    this->roll = roll;
}

int Attitude::getPitch() {
    return this->pitch;
}

int Attitude::getRoll() {
    return this->roll;
}

void Attitude::setPitch(int pitch) {
    this->pitch = pitch;
}

void Attitude::setRoll(int roll) {
    this->roll = roll;
}