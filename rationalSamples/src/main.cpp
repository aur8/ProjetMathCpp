#include <iostream>
#include "ratio.hpp"

int main() {

    rationalNumber rn1(1,3);
    rationalNumber rn2(1,3);
    rationalNumber rn3 = rn1+rn2;
    rn3.display();
    rationalNumber rn4 = rn1*rn2;
    rn4.display();
    rationalNumber rn5 = rn1/rn2;
    rn5.display();
    rationalNumber rn6 = rn1-rn2;
    rn6.display();

    return 0;
}
