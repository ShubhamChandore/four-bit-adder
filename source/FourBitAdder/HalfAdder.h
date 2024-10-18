#ifndef HALFADDER_H
#define HALFADDER_H

#include "LogicGates.h"

/**
 * @class HalfAdder
 * @brief Implements a half adder circuit.
 *
 * @details A half adder circuit adds two single-bit binary numbers and produces
 *          a two-bit output consisting of the sum and carry of the inputs.
 */
class HalfAdder
{
public:
    /**
     * Constructor for the HalfAdder class.
     * @details This constructor initializes a half adder circuit.
     */
    HalfAdder();

    /**
     * Destructor for the HalfAdder class.
     * @details This destructor releases any memory allocated by the half adder circuit.
     */
    ~HalfAdder();

    /**
     * Sets the input value for the A input of the half adder circuit.
     * @param val The input value for the A input.
     */
    void set_input_a(const unsigned short int val);

    /**
     * Sets the input value for the B input of the half adder circuit.
     * @param val The input value for the B input.
     */
    void set_input_b(const unsigned short int val);

    /**
     * Gets the output value of the half adder circuit for the sum.
     * @return The output value of the half adder circuit for the sum.
     */
    const unsigned short int get_sum() const;

    /**
     * Gets the output value of the half adder circuit for the carry.
     * @return The output value of the half adder circuit for the carry.
     */
    const unsigned short int get_carry() const;

private:
    AND* and_gate;
    OR* or_gate;
    NAND* nand_gate;
    AND* xor_gate;

    /**
     * Updates the half adder circuit by propagating the input values through the
     * gates.
     * @details This function is called whenever the input values are changed.
     */
    void update();
};

#endif /* HALFADDER_H */