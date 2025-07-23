#include "radio_driver.h"
#include <SPI.h>

RadioDriver::RadioDriver(int cePin, int csnPin, byte address) {
    this->cePin = cePin;
    this->csnPin = csnPin;
    this->address = address;
    this->radio = RF24(this->cePin, this->csnPin);
}

void RadioDriver::begin() {
    bool started = this->radio.begin();
    Serial.print("Radio started: ");
    Serial.println(started);
    this->radio.setPALevel(RF24_PA_LOW);
    this->radio.openReadingPipe(0, this->address);
    this->radio.startListening();
}

void RadioDriver::receiveCommand(DroneCommand& command) {
    if (this->radio.available()) {
        Serial.print("Receiving command...");
        this->radio.read(&command, sizeof(DroneCommand));
    } else {
        Serial.println("Radio not available!");
    }
}