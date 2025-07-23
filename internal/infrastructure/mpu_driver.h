#ifndef MPU_DRIVER_H
#define MPU_DRIVER_H

#include "../domain/attitude.h"
#include <MPU6050_light.h>

class MPUDriver {
    public:
        MPUDriver(int address);
        void begin();
        void update();
        Attitude getAttitude(Attitude& attitude);

    private:
        int address;
        MPU6050 mpu;
        int xAngle, yAngle;
};

#endif