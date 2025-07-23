#include <Arduino.h>
#include <MPU6050_light.h>
#include "internal/infrastructure/mpu_driver.h"

MPUDriver::MPUDriver(MPU6050 *mpu) {
    this->mpu = mpu;
    this->xAngle = 0;
    this->yAngle = 0;
}

void MPUDriver::begin() {
    byte status = this->mpu->begin();
    while (status != 0) { } // stop if can't connect
    Serial.println(F("Calculating offsets, do not move MPU6050"));
    delay(1000);
    this->mpu->calcOffsets(true, true); // gyro & accel
    Serial.println(F("MPU6050 initialized"));
}

void MPUDriver::update() {
    this->mpu->update();
}

Attitude MPUDriver::getAttitude(Attitude& attitude) {
    this->mpu->update();
    attitude.setPitch(this->mpu->getAngleX());
    attitude.setRoll(this->mpu->getAngleY());
    return attitude;
}