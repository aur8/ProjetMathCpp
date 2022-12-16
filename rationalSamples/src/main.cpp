#include <iostream>
#include "ratio.hpp"

int main() {

    rationalNumber rn1(1,3);
    rationalNumber rn2(1,3);
    rationalNumber rn3 = rn1+rn2;

    std::cout << rn3 << std::endl;

    return 0;
}
