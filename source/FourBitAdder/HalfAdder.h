#ifndef _HALFADDER_H_
#define _HALFADDER_H_

#include "LogicGates.h"

class HalfAdder
{
public:
    HalfAdder();
    ~HalfAdder();

    void set_input_a(const unsigned short int val);
    void set_input_b(const unsigned short int val);
    const unsigned short int get_sum() const;
    const unsigned short int get_carry() const;

private:
    AND* and_gate;
    OR* or_gate;
    NAND* nand_gate;
    AND* xor_gate;

    void update();
};

#endif /* _HALFADDER_H_ */