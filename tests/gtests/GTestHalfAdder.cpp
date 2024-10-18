#include <gtest/gtest.h>
#include "HalfAdder.h"

class HalfAdderTest : public ::testing::Test {
protected:
    HalfAdder* half_adder;

    void SetUp() override {
        half_adder = new HalfAdder();
    }

    void TearDown() override {
        delete half_adder;
    }
};

TEST_F(HalfAdderTest, ZeroPlusZero) {
    half_adder->set_input_a(0);
    half_adder->set_input_b(0);
    EXPECT_EQ(0, half_adder->get_sum());
    EXPECT_EQ(0, half_adder->get_carry());
}

TEST_F(HalfAdderTest, ZeroPlusOne) {
    half_adder->set_input_a(0);
    half_adder->set_input_b(1);
    EXPECT_EQ(1, half_adder->get_sum());
    EXPECT_EQ(0, half_adder->get_carry());
}

TEST_F(HalfAdderTest, OnePlusZero) {
    half_adder->set_input_a(1);
    half_adder->set_input_b(0);
    EXPECT_EQ(1, half_adder->get_sum());
    EXPECT_EQ(0, half_adder->get_carry());
}

TEST_F(HalfAdderTest, OnePlusOne) {
    half_adder->set_input_a(1);
    half_adder->set_input_b(1);
    EXPECT_EQ(0, half_adder->get_sum());
    EXPECT_EQ(1, half_adder->get_carry());
}

TEST_F(HalfAdderTest, ChangeInputs) {
    half_adder->set_input_a(0);
    half_adder->set_input_b(0);
    EXPECT_EQ(0, half_adder->get_sum());
    EXPECT_EQ(0, half_adder->get_carry());

    half_adder->set_input_a(1);
    EXPECT_EQ(1, half_adder->get_sum());
    EXPECT_EQ(0, half_adder->get_carry());

    half_adder->set_input_b(1);
    EXPECT_EQ(0, half_adder->get_sum());
    EXPECT_EQ(1, half_adder->get_carry());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}