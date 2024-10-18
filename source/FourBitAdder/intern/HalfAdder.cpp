#include "HalfAdder.h"
// Constructor for the HalfAdder class
// Initializes the logic gates (AND, OR, NAND, XOR)

HalfAdder::HalfAdder()
{
    and_gate = new AND(1);
    or_gate = new OR(2);
    nand_gate = new NAND(3);
    xor_gate = new AND(4);
}
// Destructor for the HalfAdder class
// Cleans up dynamically allocated gates
HalfAdder::~HalfAdder()
{
    delete and_gate;
    delete or_gate;
    delete nand_gate;
    delete xor_gate;
}
// Destructor for the HalfAdder class
// Cleans up dynamically allocated gates
void HalfAdder::set_input_a(const unsigned short int val)
{
    and_gate->set_in1(val);
    or_gate->set_in1(val);
    nand_gate->set_in1(val);
    update();
}

void HalfAdder::set_input_b(const unsigned short int val)
{
    and_gate->set_in2(val);
    or_gate->set_in2(val);
    nand_gate->set_in2(val);
    update();
}

const unsigned short int HalfAdder::get_sum() const
{
    return xor_gate->out();
}

const unsigned short int HalfAdder::get_carry() const
{
    return and_gate->out();
}

void HalfAdder::update()
{
    // XOR = (A NAND B) AND (A OR B)
    xor_gate->set_in1(nand_gate->out());
    xor_gate->set_in2(or_gate->out());
}
