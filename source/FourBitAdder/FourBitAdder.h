/* add your code */

// Note that you will need intermediate classes as well
// for the half-adder and full-adder circuits.
#ifndef FOURBITADDER_H
#define FOURBITADDER_H

#include "FullAdder.h"

/**
 * @class FourBitAdder
 * @brief Implements a four-bit adder circuit.
 *
 * @details This class represents a four-bit adder circuit that uses four full adders.
 *          It provides methods to set input values and retrieve the sum and carry-out values.
 */
class FourBitAdder
{
public:
    /**
     * @brief Constructor for the FourBitAdder class.
     * @details Initializes a four-bit adder circuit.
     */
    FourBitAdder();

    /**
     * @brief Destructor for the FourBitAdder class.
     * @details Frees up the memory allocated for the four-bit adder circuit.
     */
    ~FourBitAdder();

    /**
     * @brief Sets the input values for the A input of the four-bit adder circuit.
     * @param a3 The input value for bit 3 of the A input.
     * @param a2 The input value for bit 2 of the A input.
     * @param a1 The input value for bit 1 of the A input.
     * @param a0 The input value for bit 0 of the A input.
     */
    void set_input_a(const unsigned short int a3, const unsigned short int a2, 
                     const unsigned short int a1, const unsigned short int a0);

    /**
     * @brief Sets the input values for the B input of the four-bit adder circuit.
     * @param b3 The input value for bit 3 of the B input.
     * @param b2 The input value for bit 2 of the B input.
     * @param b1 The input value for bit 1 of the B input.
     * @param b0 The input value for bit 0 of the B input.
     */
    void set_input_b(const unsigned short int b3, const unsigned short int b2, 
                     const unsigned short int b1, const unsigned short int b0);

    /**
     * @brief Sets the carry-in input value for the four-bit adder circuit.
     * @param cin The carry-in input value.
     */
    void set_carry_in(const unsigned short int cin);

    /**
     * @brief Gets the output value of the four-bit adder circuit at the specified bit position.
     * @param bit_position The bit position of the output to get.
     * @return The output value at the specified bit position.
     */
    const unsigned short int get_sum(int bit_position) const;

    /**
     * @brief Gets the carry-out output value of the four-bit adder circuit.
     * @return The carry-out output value.
     */
    const unsigned short int get_carry_out() const;

private:
    /**
     * @brief Array of full adders used in the four-bit adder circuit.
     */
    FullAdder* adders[4];

    /**
     * @brief Input values for the A input of the four-bit adder circuit.
     */
    unsigned short int inputs_a[4];

    /**
     * @brief Input values for the B input of the four-bit adder circuit.
     */
    unsigned short int inputs_b[4];

    /**
     * @brief Carry-in input value for the four-bit adder circuit.
     */
    unsigned short int carry_in;

    /**
     * @brief Updates the four-bit adder circuit by propagating the carry values through the adders.
     * @details This function is called whenever the input values or carry-in value is changed.
     */
    void update();
};

#endif /* FOURBITADDER_H */