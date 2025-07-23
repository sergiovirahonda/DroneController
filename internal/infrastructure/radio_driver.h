#ifndef RADIO_DRIVER_H
#define RADIO_DRIVER_H

#include <nRF24L01.h>
#include <RF24.h>
#include "../domain/drone_command.h"

class RadioDriver {
    private:
        RF24 radio;
        int cePin;
        int csnPin;
        byte address;
    
    public:
        RadioDriver(int cePin, int csnPin, byte address);
        void begin();
        void receiveCommand(DroneCommand& command);
};

#endif