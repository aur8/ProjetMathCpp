#include <iostream>
#include "ratio.hpp"

int main() {

    int a = 9;
    std::cout << a << std::endl;

    rationalNumber rn1(1,3);
    rationalNumber rn2(1,3);
    rationalNumber rn3 = rn1+rn2;
    rn3.display();



    return 0;
}
