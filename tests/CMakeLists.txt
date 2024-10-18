add_subdirectory(gtests)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add your test executable
add_executable(AdderAndLogicTests 
    gtests/GTestFourBitAdder.cpp
    gtests/GTestFullAdder.cpp
    gtests/GTestHalfAdder.cpp
    gtests/GTestLogicGates.cpp
)

target_link_libraries(AdderAndLogicTests ${GTEST_LIBRARIES} pthread)