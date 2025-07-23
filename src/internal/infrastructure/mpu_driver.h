#ifndef MPU_DRIVER_H
#define MPU_DRIVER_H

#include "internal/domain/attitude.h"
#include <MPU6050_light.h>
#include <Wire.h>

class MPUDriver {
    public:
        MPUDriver(MPU6050 *mpu);
        void begin();
        void update();
        Attitude getAttitude(Attitude& attitude);

    private:
        MPU6050 *mpu;
        int xAngle, yAngle;
};

#endif