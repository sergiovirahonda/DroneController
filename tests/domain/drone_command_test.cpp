#include <gtest/gtest.h>
#include "../../internal/domain/drone_command.h"

class DroneCommandTest : public ::testing::Test {
protected:
    DroneCommand cmd{1, 2, 3, 4, 12345};
};

TEST_F(DroneCommandTest, Constructor_ValidValues_SetsAllProperties) {
    DroneCommand c(10, 20, 30, 40, 99999);
    EXPECT_EQ(c.getPitch(), 10);
    EXPECT_EQ(c.getRoll(), 20);
    EXPECT_EQ(c.getYaw(), 30);
    EXPECT_EQ(c.getThrottle(), 40);
    EXPECT_EQ(c.getTimestamp(), 99999u);
}

TEST_F(DroneCommandTest, SetPitch_ValidValue_UpdatesPitch) {
    cmd.setPitch(100);
    EXPECT_EQ(cmd.getPitch(), 100);
}

TEST_F(DroneCommandTest, SetRoll_ValidValue_UpdatesRoll) {
    cmd.setRoll(200);
    EXPECT_EQ(cmd.getRoll(), 200);
}

TEST_F(DroneCommandTest, SetYaw_ValidValue_UpdatesYaw) {
    cmd.setYaw(300);
    EXPECT_EQ(cmd.getYaw(), 300);
}

TEST_F(DroneCommandTest, SetThrottle_ValidValue_UpdatesThrottle) {
    cmd.setThrottle(400);
    EXPECT_EQ(cmd.getThrottle(), 400);
}

TEST_F(DroneCommandTest, SetTimestamp_ValidValue_UpdatesTimestamp) {
    cmd.setTimestamp(55555);
    EXPECT_EQ(cmd.getTimestamp(), 55555u);
}

TEST_F(DroneCommandTest, Reset_ResetsAllValuesToZero) {
    cmd.reset();
    EXPECT_EQ(cmd.getPitch(), 0);
    EXPECT_EQ(cmd.getRoll(), 0);
    EXPECT_EQ(cmd.getYaw(), 0);
    EXPECT_EQ(cmd.getThrottle(), 0);
    EXPECT_EQ(cmd.getTimestamp(), 0u);
} 