#include "radio_driver.h"
#include <SPI.h>

RadioDriver::RadioDriver(int cePin, int csnPin, byte address) {
    this->cePin = cePin;
    this->csnPin = csnPin;
    this->address = address;
    this->radio = RF24(cePin, csnPin);
}

void RadioDriver::begin() {
    this->radio.begin();
    this->radio.setPALevel(RF24_PA_LOW);
    this->radio.openReadingPipe(0, this->address);
    this->radio.startListening();
}

void RadioDriver::receiveCommand(DroneCommand& command) {
    if (this->radio.available()) {
        this->radio.read(&command, sizeof(DroneCommand));
    }
}