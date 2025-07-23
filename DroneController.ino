// External Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Arduino.h>

// Define radio CE & CSN pins
#define CE_PIN  9
#define CSN_PIN 10
const byte address[6] = "00001";

// MPU setup
MPU6050 mpu(Wire);

// Motor pin assignments
int motor1Pin = 3;
int motor2Pin = 5;
int motor3Pin = 6;
int motor4Pin = 9;

// Global variables
Attitude attitude;

RadioDriver radio(CE_PIN, CSN_PIN, address);
MPUDriver mpuDriver(address);
MotorDriver motorDriver(motor1Pin, motor2Pin, motor3Pin, motor4Pin);
FlightService flightService(0.1, 0.0, 0.0);

void setup() {
    Serial.begin(115200);
    radio.begin();
    mpuDriver.begin(mpu);
}

void loop() {
    DroneCommand command;
    radio.receiveCommand(command);
    mpuDriver.getAttitude(attitude);
    MotorOutput motorOutput = flightService.computeMotorOutput(command, attitude);
    motorDriver.setMotorSpeeds(motorOutput);
    delay(50);
}