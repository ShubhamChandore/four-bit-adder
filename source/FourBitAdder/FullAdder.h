#ifndef _FULLADDER_H_
#define _FULLADDER_H_

#include "HalfAdder.h"
#include "LogicGates.h"

class FullAdder
{
public:
    FullAdder();
    ~FullAdder();

    void set_input_a(const unsigned short int val);
    void set_input_b(const unsigned short int val);
    void set_input_cin(const unsigned short int val);
    const unsigned short int get_sum() const;
    const unsigned short int get_cout() const;

private:
    HalfAdder* half_adder1;
    HalfAdder* half_adder2;
    OR* or_gate;

    void update();
};

#endif /* _FULLADDER_H_ */