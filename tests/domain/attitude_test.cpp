#include <gtest/gtest.h>
#include "../../internal/domain/attitude.h"

class AttitudeTest : public ::testing::Test {
protected:
    Attitude attitude{0, 0};
};

TEST_F(AttitudeTest, Constructor_ValidValues_SetsAllProperties) {
    Attitude a(10, -5);
    EXPECT_EQ(a.getPitch(), 10);
    EXPECT_EQ(a.getRoll(), -5);
}

TEST_F(AttitudeTest, SetPitch_ValidValue_UpdatesPitch) {
    attitude.setPitch(15);
    EXPECT_EQ(attitude.getPitch(), 15);
}

TEST_F(AttitudeTest, SetRoll_ValidValue_UpdatesRoll) {
    attitude.setRoll(-20);
    EXPECT_EQ(attitude.getRoll(), -20);
} 