/* add your code */

// Note that you will need intermediate classes as well
// for the half-adder and full-adder circuits.
#ifndef _FOURBITADDER_H_
#define _FOURBITADDER_H_

#include "FullAdder.h"

class FourBitAdder
{
public:
    FourBitAdder();
    ~FourBitAdder();

    void set_input_a(const unsigned short int a3, const unsigned short int a2, 
                     const unsigned short int a1, const unsigned short int a0);
    void set_input_b(const unsigned short int b3, const unsigned short int b2, 
                     const unsigned short int b1, const unsigned short int b0);
    void set_carry_in(const unsigned short int cin);

    const unsigned short int get_sum(int bit_position) const;
    const unsigned short int get_carry_out() const;

private:
    FullAdder* adders[4];
    unsigned short int inputs_a[4];
    unsigned short int inputs_b[4];
    unsigned short int carry_in;

    void update();
};

#endif /* _FOURBITADDER_H_ */