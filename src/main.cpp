// External Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <MPU6050_light.h>
#include <Arduino.h>

// Internal imports
#include "internal/domain/attitude.h"
#include "internal/domain/motor_output.h"
#include "internal/domain/drone_command.h"
#include "internal/infrastructure/radio_driver.h"
#include "internal/infrastructure/mpu_driver.h"
#include "internal/infrastructure/motor_driver.h"
#include "internal/application/flight_service.h"

// Radio address
byte address[6] = "00001";

// MPU setup
MPU6050 mpu(Wire);

// Global variables
// Define radio CE & CSN pins
int cePin =  9;
int csnPin = 10;

// Motor pin assignments
#define MOTOR1_PIN 3
#define MOTOR2_PIN 5
#define MOTOR3_PIN 6
#define MOTOR4_PIN 9

Attitude attitude(0, 0);
DroneCommand command(0, 0, 0, 0, millis());

RadioDriver radio(cePin, csnPin, &address);
MPUDriver mpuDriver(&mpu);
MotorDriver motorDriver(MOTOR1_PIN, MOTOR2_PIN, MOTOR3_PIN, MOTOR4_PIN);
FlightService flightService(0.1, 0.0, 0.0);

void setup() {
    Serial.begin(9600);
    Serial.println("Setting up drone controller...");
    radio.begin();
    mpuDriver.begin();
}

void loop() {
    radio.receiveCommand(command);
    mpuDriver.getAttitude(attitude);
    MotorOutput motorOutput = flightService.computeMotorOutput(command, attitude);
    motorDriver.setMotorSpeeds(motorOutput);
    delay(50);
}