cmake_minimum_required(VERSION 3.14)

# Set the path to the installed Google Test
set(GTEST_ROOT "C:/Users/Huzaif/Desktop/OOAD/googletest/build")

# Find the installed Google Test package
find_package(GTest REQUIRED)

# Enable testing
enable_testing()

# Your existing include and source file definitions
set(INC_LOGIC 
    ../../source/FourBitAdder/intern/AbstractGate.h
    ../../source/FourBitAdder/intern/LogicGates.h
)

# Assuming you have a target for your main project
add_library(proj1_FourBitAdder STATIC
    # Add your project source files here
)

# LogicGates Tests
add_executable(LogicGatesGTests_gtests ./GTestLogicGates.cpp ${INC_LOGIC})
target_link_libraries(LogicGatesGTests_gtests PRIVATE proj1_FourBitAdder GTest::GTest GTest::Main)

# FourBitAdder Tests
add_executable(FourBitAdderTests_gtests ./GTestFourBitAdder.cpp ${INC_LOGIC})
target_link_libraries(FourBitAdderTests_gtests PRIVATE proj1_FourBitAdder GTest::GTest GTest::Main)

# FullAdder Tests
add_executable(FullAdderTests_gtests ./GTestFullAdder.cpp ${INC_LOGIC})
target_link_libraries(FullAdderTests_gtests PRIVATE proj1_FourBitAdder GTest::GTest GTest::Main)

# HalfAdder Tests
add_executable(HalfAdderTests_gtests ./GTestHalfAdder.cpp ${INC_LOGIC})
target_link_libraries(HalfAdderTests_gtests PRIVATE proj1_FourBitAdder GTest::GTest GTest::Main)

# Add tests
include(GoogleTest)
gtest_discover_tests(LogicGatesGTests_gtests)
gtest_discover_tests(FourBitAdderTests_gtests)
gtest_discover_tests(FullAdderTests_gtests)
gtest_discover_tests(HalfAdderTests_gtests)