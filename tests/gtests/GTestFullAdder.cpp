#include <gtest/gtest.h>
#include "FullAdder.h"

class FullAdderTest : public ::testing::Test {
protected:
    FullAdder* full_adder;

    void SetUp() override {
        full_adder = new FullAdder();
    }

    void TearDown() override {
        delete full_adder;
    }
};

TEST_F(FullAdderTest, ZeroZeroZero) {
    full_adder->set_input_a(0);
    full_adder->set_input_b(0);
    full_adder->set_input_cin(0);
    EXPECT_EQ(0, full_adder->get_sum());
    EXPECT_EQ(0, full_adder->get_cout());
}

TEST_F(FullAdderTest, ZeroZeroOne) {
    full_adder->set_input_a(0);
    full_adder->set_input_b(0);
    full_adder->set_input_cin(1);
    EXPECT_EQ(1, full_adder->get_sum());
    EXPECT_EQ(0, full_adder->get_cout());
}

TEST_F(FullAdderTest, ZeroOneZero) {
    full_adder->set_input_a(0);
    full_adder->set_input_b(1);
    full_adder->set_input_cin(0);
    EXPECT_EQ(1, full_adder->get_sum());
    EXPECT_EQ(0, full_adder->get_cout());
}

TEST_F(FullAdderTest, ZeroOneOne) {
    full_adder->set_input_a(0);
    full_adder->set_input_b(1);
    full_adder->set_input_cin(1);
    EXPECT_EQ(0, full_adder->get_sum());
    EXPECT_EQ(1, full_adder->get_cout());
}

TEST_F(FullAdderTest, OneZeroZero) {
    full_adder->set_input_a(1);
    full_adder->set_input_b(0);
    full_adder->set_input_cin(0);
    EXPECT_EQ(1, full_adder->get_sum());
    EXPECT_EQ(0, full_adder->get_cout());
}

TEST_F(FullAdderTest, OneZeroOne) {
    full_adder->set_input_a(1);
    full_adder->set_input_b(0);
    full_adder->set_input_cin(1);
    EXPECT_EQ(0, full_adder->get_sum());
    EXPECT_EQ(1, full_adder->get_cout());
}

TEST_F(FullAdderTest, OneOneZero) {
    full_adder->set_input_a(1);
    full_adder->set_input_b(1);
    full_adder->set_input_cin(0);
    EXPECT_EQ(0, full_adder->get_sum());
    EXPECT_EQ(1, full_adder->get_cout());
}

TEST_F(FullAdderTest, OneOneOne) {
    full_adder->set_input_a(1);
    full_adder->set_input_b(1);
    full_adder->set_input_cin(1);
    EXPECT_EQ(1, full_adder->get_sum());
    EXPECT_EQ(1, full_adder->get_cout());
}

TEST_F(FullAdderTest, ChangeInputs) {
    full_adder->set_input_a(0);
    full_adder->set_input_b(0);
    full_adder->set_input_cin(0);
    EXPECT_EQ(0, full_adder->get_sum());
    EXPECT_EQ(0, full_adder->get_cout());

    full_adder->set_input_a(1);
    EXPECT_EQ(1, full_adder->get_sum());
    EXPECT_EQ(0, full_adder->get_cout());

    full_adder->set_input_b(1);
    EXPECT_EQ(0, full_adder->get_sum());
    EXPECT_EQ(1, full_adder->get_cout());

    full_adder->set_input_cin(1);
    EXPECT_EQ(1, full_adder->get_sum());
    EXPECT_EQ(1, full_adder->get_cout());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}