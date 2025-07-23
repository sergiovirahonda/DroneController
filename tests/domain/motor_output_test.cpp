#include <gtest/gtest.h>
#include "../../internal/domain/motor_output.h"

class MotorOutputTest : public ::testing::Test {
protected:
    MotorOutput motor{0, 0, 0, 0};
};

TEST_F(MotorOutputTest, Constructor_ValidValues_SetsAllProperties) {
    MotorOutput m(10, 20, 30, 40);
    EXPECT_EQ(m.getMotor1Speed(), 10);
    EXPECT_EQ(m.getMotor2Speed(), 20);
    EXPECT_EQ(m.getMotor3Speed(), 30);
    EXPECT_EQ(m.getMotor4Speed(), 40);
}

TEST_F(MotorOutputTest, SetMotor1Speed_ValidValue_UpdatesMotor1Speed) {
    motor.setMotor1Speed(55);
    EXPECT_EQ(motor.getMotor1Speed(), 55);
}

TEST_F(MotorOutputTest, SetMotor2Speed_ValidValue_UpdatesMotor2Speed) {
    motor.setMotor2Speed(66);
    EXPECT_EQ(motor.getMotor2Speed(), 66);
}

TEST_F(MotorOutputTest, SetMotor3Speed_ValidValue_UpdatesMotor3Speed) {
    motor.setMotor3Speed(77);
    EXPECT_EQ(motor.getMotor3Speed(), 77);
}

TEST_F(MotorOutputTest, SetMotor4Speed_ValidValue_UpdatesMotor4Speed) {
    motor.setMotor4Speed(88);
    EXPECT_EQ(motor.getMotor4Speed(), 88);
} 