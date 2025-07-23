#include <Arduino.h>
#include <unity.h>
#include "src/internal/domain/drone_command.h"

void test_constructor_sets_all_properties() {
    DroneCommand cmd(10, 20, 30, 40, 99999);
    TEST_ASSERT_EQUAL(10, cmd.getPitch());
    TEST_ASSERT_EQUAL(20, cmd.getRoll());
    TEST_ASSERT_EQUAL(30, cmd.getYaw());
    TEST_ASSERT_EQUAL(40, cmd.getThrottle());
    TEST_ASSERT_EQUAL_UINT32(99999, cmd.getTimestamp());
}

void test_setters_update_properties() {
    DroneCommand cmd(0, 0, 0, 0, 0);
    cmd.setPitch(100);
    cmd.setRoll(200);
    cmd.setYaw(300);
    cmd.setThrottle(400);
    cmd.setTimestamp(55555);
    TEST_ASSERT_EQUAL(100, cmd.getPitch());
    TEST_ASSERT_EQUAL(200, cmd.getRoll());
    TEST_ASSERT_EQUAL(300, cmd.getYaw());
    TEST_ASSERT_EQUAL(400, cmd.getThrottle());
    TEST_ASSERT_EQUAL_UINT32(55555, cmd.getTimestamp());
}

void test_reset_sets_all_to_zero() {
    DroneCommand cmd(1, 2, 3, 4, 12345);
    cmd.reset();
    TEST_ASSERT_EQUAL(0, cmd.getPitch());
    TEST_ASSERT_EQUAL(0, cmd.getRoll());
    TEST_ASSERT_EQUAL(0, cmd.getYaw());
    TEST_ASSERT_EQUAL(0, cmd.getThrottle());
    TEST_ASSERT_EQUAL_UINT32(0, cmd.getTimestamp());
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_constructor_sets_all_properties);
    RUN_TEST(test_setters_update_properties);
    RUN_TEST(test_reset_sets_all_to_zero);
    UNITY_END();
}

void loop() {} 