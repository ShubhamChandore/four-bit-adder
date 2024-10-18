#ifndef FULLADDER_H
#define FULLADDER_H

#include "HalfAdder.h"
#include "LogicGates.h"

/**
 * @brief Class representing a full adder circuit
 *
 * A full adder is a binary adder circuit that takes in two single-bit inputs
 * and a carry-in input and produces a two-bit output (sum and carry-out).
 */
class FullAdder
{
public:
    /**
     * @brief Constructor
     *
     * Initializes the full adder circuit.
     */
    FullAdder();
    /**
     * @brief Destructor
     *
     * Destroys the full adder circuit.
     */
    ~FullAdder();

    /**
     * @brief Sets the A input value
     *
     * @param val The input value for the A input.
     */
    void set_input_a(const unsigned short int val);
    /**
     * @brief Sets the B input value
     *
     * @param val The input value for the B input.
     */
    void set_input_b(const unsigned short int val);
    /**
     * @brief Sets the carry-in input value
     *
     * @param val The input value for the carry-in input.
     */
    void set_input_cin(const unsigned short int val);
    /**
     * @brief Gets the sum output value
     *
     * @return The sum output value.
     */
    const unsigned short int get_sum() const;
    /**
     * @brief Gets the carry-out output value
     *
     * @return The carry-out output value.
     */
    const unsigned short int get_cout() const;

private:
    HalfAdder* half_adder1;
    HalfAdder* half_adder2;
    OR* or_gate;

    /**
     * @brief Updates the full adder circuit
     *
     * This function is called whenever the input values or carry-in value is changed.
     */
    void update();
};

#endif /* FULLADDER_H */