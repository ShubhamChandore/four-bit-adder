/**
 * @file FullAdder.cpp
 * @author Brad Ekstrand
 * @date June 2020
 * @brief Implementation of the FullAdder class.
 * @details This class implements a full adder circuit using two half adders
 *          and an OR gate.
 */
#include "FullAdder.h"
/**
 * Constructor for the FullAdder class.
 */
FullAdder::FullAdder()
{
    half_adder1 = new HalfAdder();
    half_adder2 = new HalfAdder();
    or_gate = new OR(1);
}

/**
 * Destructor for the FullAdder class.
 */
FullAdder::~FullAdder()
{
    delete half_adder1;
    delete half_adder2;
    delete or_gate;
}

/**
 * Sets the input value for the A input of the full adder circuit.
 * @param val The input value for the A input.
 */
void FullAdder::set_input_a(const unsigned short int val)
{
    half_adder1->set_input_a(val);
    update();
}

/**
 * Sets the input value for the B input of the full adder circuit.
 * @param val The input value for the B input.
 */
void FullAdder::set_input_b(const unsigned short int val)
{
    half_adder1->set_input_b(val);
    update();
}

/**
 * Sets the input value for the carry-in input of the full adder circuit.
 * @param val The input value for the carry-in input.
 */
void FullAdder::set_input_cin(const unsigned short int val)
{
    half_adder2->set_input_a(val);
    update();
}

/**
 * Gets the sum output value of the full adder circuit.
 * @return The sum output value.
 */
const unsigned short int FullAdder::get_sum() const
{
    return half_adder2->get_sum();
}

/**
 * Gets the carry-out output value of the full adder circuit.
 * @return The carry-out output value.
 */
const unsigned short int FullAdder::get_cout() const
{
    return or_gate->out();
}

/**
 * Updates the full adder circuit by propagating the carry values through the
 * adders.
 * @details This function is called whenever the input values or carry-in value
 *          is changed.
 */
void FullAdder::update()
{
    // Connect the sum of the first half adder to the second half adder
    half_adder2->set_input_b(half_adder1->get_sum());

    // Connect the carry outputs of both half adders to the OR gate
    or_gate->set_in1(half_adder1->get_carry());
    or_gate->set_in2(half_adder2->get_carry());
}
