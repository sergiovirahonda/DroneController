// External Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Arduino.h>

// Define radio CE & CSN pins
#define RADIO_CE_PIN  9
#define RADIO_CSN_PIN 10
const byte radioAddress[6] = "00001";

// MPU setup
MPU6050 mpu(Wire);

// Motor pin assignments
#define MOTOR1_PIN 3
#define MOTOR2_PIN 5
#define MOTOR3_PIN 6
#define MOTOR4_PIN 9

// Global variables
Attitude attitude;

RadioDriver radio(RADIO_CE_PIN, RADIO_CSN_PIN, radioAddress);
MPUDriver mpuDriver(address);
MotorDriver motorDriver(MOTOR1_PIN, MOTOR2_PIN, MOTOR3_PIN, MOTOR4_PIN);
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