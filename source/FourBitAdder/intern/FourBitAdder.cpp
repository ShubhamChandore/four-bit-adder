/**
 * @file FourBitAdder.cpp
 * @author Brad Keith
 * @date 17 June 2020
 * @brief Implementation of the FourBitAdder class.
 * @details This class represents a four-bit adder circuit.
 */

#include "FourBitAdder.h"
/**
 * Constructor for the FourBitAdder class.
 * @details This constructor initializes a four-bit adder circuit.
 */
FourBitAdder::FourBitAdder() : carry_in(0)
{
    for (int i = 0; i < 4; ++i) {
        adders[i] = new FullAdder();
        inputs_a[i] = 0;
        inputs_b[i] = 0;
    }
}

/**
 * Destructor for the FourBitAdder class.
 * @details This destructor frees up the memory allocated for the four-bit adder circuit.
 */
FourBitAdder::~FourBitAdder()
{
    for (int i = 0; i < 4; ++i) {
        delete adders[i];
    }
}

/**
 * Sets the input values for the A input of the four-bit adder circuit.
 * @param a3 The input value for bit 3 of the A input.
 * @param a2 The input value for bit 2 of the A input.
 * @param a1 The input value for bit 1 of the A input.
 * @param a0 The input value for bit 0 of the A input.
 */
void FourBitAdder::set_input_a(const unsigned short int a3, const unsigned short int a2, 
                               const unsigned short int a1, const unsigned short int a0)
{
    inputs_a[3] = a3;
    inputs_a[2] = a2;
    inputs_a[1] = a1;
    inputs_a[0] = a0;
    update();
}

/**
 * Sets the input values for the B input of the four-bit adder circuit.
 * @param b3 The input value for bit 3 of the B input.
 * @param b2 The input value for bit 2 of the B input.
 * @param b1 The input value for bit 1 of the B input.
 * @param b0 The input value for bit 0 of the B input.
 */
void FourBitAdder::set_input_b(const unsigned short int b3, const unsigned short int b2, 
                               const unsigned short int b1, const unsigned short int b0)
{
    inputs_b[3] = b3;
    inputs_b[2] = b2;
    inputs_b[1] = b1;
    inputs_b[0] = b0;
    update();
}

/**
 * Sets the carry-in input value for the four-bit adder circuit.
 * @param cin The carry-in input value.
 */
void FourBitAdder::set_carry_in(const unsigned short int cin)
{
    carry_in = cin;
    update();
}

/**
 * Gets the output value of the four-bit adder circuit at the specified bit position.
 * @param bit_position The bit position of the output to get.
 * @return The output value at the specified bit position.
 */
const unsigned short int FourBitAdder::get_sum(int bit_position) const
{
    if (bit_position >= 0 && bit_position < 4) {
        return adders[bit_position]->get_sum();
    }
    return 0; // Return 0 for invalid bit positions
}

/**
 * Gets the carry-out output value of the four-bit adder circuit.
 * @return The carry-out output value.
 */
const unsigned short int FourBitAdder::get_carry_out() const
{
    return adders[3]->get_cout();
}

/**
 * Updates the four-bit adder circuit by propagating the carry values through the adders.
 * @details This function is called whenever the input values or carry-in value is changed.
 */
void FourBitAdder::update()
{
    unsigned short int carry = carry_in;

    for (int i = 0; i < 4; ++i) {
        adders[i]->set_input_a(inputs_a[i]);
        adders[i]->set_input_b(inputs_b[i]);
        adders[i]->set_input_cin(carry);
        carry = adders[i]->get_cout();
    }
}


