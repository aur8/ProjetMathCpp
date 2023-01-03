#include <random>
#include <algorithm>
#include <gtest/gtest.h>
#include "ratio.hpp"

/////////////////////////////////////////////////////
// constructors

TEST (rationalConstructor, defaultConstructor) {
    rationalNumber rn;
    ASSERT_EQ(rn.getNumerator(), 0);
    ASSERT_EQ(rn.getDenominator(), 1);
}

TEST (rationalNumberArtihmetic1, plus) {
    const int maxSize = 100;  // max size of numerators and denominators
    std::mt19937 generator(0);
    std::uniform_int_distribution<int> uniformIntDistribution(-maxSize,maxSize);
    std::uniform_int_distribution<int> uniformUnsignedIntDistribution(1,maxSize);
    std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};


    for(int run=0; run<100; ++run){

        // generate random data
        int num1 = uniformIntDistribution(generator);
        unsigned int den1 = uniformUnsignedIntDistribution(generator);
        int num2 = uniformIntDistribution(generator);
        unsigned int den2 = uniformUnsignedIntDistribution(generator);

        //generate data
        rationalNumber rn1(num1,den1);
        rationalNumber rn2(num2,den2);
        rationalNumber rn3 = rn1 + rn2;
        rationalNumber sum(((rn1.getNumerator()*rn2.getDenominator())+(rn1.getDenominator()*rn2.getNumerator())),(rn1.getDenominator()*rn2.getDenominator()));
        ASSERT_GT(rn3.getDenominator(), 0);
        ASSERT_EQ(rn3, sum);
    }
}

TEST (rationalNumberArtihmetic1, minus) {

  const int maxSize = 100;  // max size of numerators and denominators
    std::mt19937 generator(0);
    std::uniform_int_distribution<int> uniformIntDistribution(-maxSize,maxSize);
    std::uniform_int_distribution<int> uniformUnsignedIntDistribution(1,maxSize);
    std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};


    for(int run=0; run<100; ++run){

        // generate random data
        int num1 = uniformIntDistribution(generator);
        unsigned int den1 = uniformUnsignedIntDistribution(generator);
        int num2 = uniformIntDistribution(generator);
        unsigned int den2 = uniformUnsignedIntDistribution(generator);

        //generate data
        rationalNumber rn1(num1,den1);
        rationalNumber rn2(num2,den2);
        rationalNumber rn3 = rn1 - rn2;
        rationalNumber minus(((rn1.getNumerator()*rn2.getDenominator())-(rn1.getDenominator()*rn2.getNumerator())),(rn1.getDenominator()*rn2.getDenominator()));
        ASSERT_GT(rn3.getDenominator(), 0);
        ASSERT_EQ(rn3, minus);
}
}

TEST (rationalNumberArtihmetic1, product) {

    const int maxSize = 100;  // max size of numerators and denominators
    std::mt19937 generator(0);
    std::uniform_int_distribution<int> uniformIntDistribution(-maxSize,maxSize);
    std::uniform_int_distribution<int> uniformUnsignedIntDistribution(1,maxSize);
    std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run=0; run<100; ++run){

        // generate random data
        int num1 = uniformIntDistribution(generator);
        unsigned int den1 = uniformUnsignedIntDistribution(generator);
        int num2 = uniformIntDistribution(generator);
        unsigned int den2 = uniformUnsignedIntDistribution(generator);

        //generate data
        rationalNumber rn1(num1,den1);
        rationalNumber rn2(num2,den2);
        rationalNumber rn3 = rn1 * rn2;
        rationalNumber product((rn1.getNumerator()*rn2.getNumerator()),(rn1.getDenominator()*rn2.getDenominator()));
        ASSERT_GT(rn3.getDenominator(), 0);
        ASSERT_EQ(rn3, product);
}
}

TEST (rationalNumberArtihmetic1, quotient) {

    const int maxSize = 100;  // max size of numerators and denominators
    std::mt19937 generator(0);
    std::uniform_int_distribution<int> uniformIntDistribution(-maxSize,maxSize);
    std::uniform_int_distribution<int> uniformUnsignedIntDistribution(1,maxSize);
    std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run=0; run<100; ++run){

        // generate random data
        int num1 = uniformIntDistribution(generator);
        unsigned int den1 = uniformUnsignedIntDistribution(generator);
        int num2 = uniformIntDistribution(generator);
        unsigned int den2 = uniformUnsignedIntDistribution(generator);

        //generate data
        rationalNumber rn1(num1,den1);
        rationalNumber rn2(num2,den2);
        rationalNumber rn3 = rn1 / rn2;
        rationalNumber quotient((rn1.getNumerator()*rn2.getDenominator()),(rn1.getDenominator()*rn2.getNumerator()));
        ASSERT_EQ(rn3, quotient);
}
}

TEST (rationalNumberArtihmetic1, square) {

    const int maxSize = 100;  // max size of numerators and denominators
    std::mt19937 generator(0);
    std::uniform_int_distribution<int> uniformIntDistribution(-maxSize,maxSize);
    std::uniform_int_distribution<int> uniformUnsignedIntDistribution(1,maxSize);
    std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run=0; run<100; ++run){

        // generate random data
        int num1 = uniformIntDistribution(generator);
        unsigned int den1 = uniformUnsignedIntDistribution(generator);
        int num2 = uniformIntDistribution(generator);
        unsigned int den2 = uniformUnsignedIntDistribution(generator);

        //generate data
        rationalNumber rn1(num1,den1);
        rationalNumber rn2 = rn1.square();
        rationalNumber square((rn1.getNumerator()*rn1.getNumerator()),(rn1.getDenominator()*rn1.getDenominator()));
        ASSERT_GT(rn2.getDenominator(), 0);
        ASSERT_EQ(rn2, square);
}
}

/*TEST (rationalNumberArtihmetic1, logarithm) {

    const int maxSize = 100;  // max size of numerators and denominators
    std::mt19937 generator(0);
    std::uniform_int_distribution<int> uniformIntDistribution(-maxSize,maxSize);
    std::uniform_int_distribution<int> uniformUnsignedIntDistribution(1,maxSize);
    std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run=0; run<100; ++run){

        // generate random data
        int num1 = uniformIntDistribution(generator);
        unsigned int den1 = uniformUnsignedIntDistribution(generator);
        int num2 = uniformIntDistribution(generator);
        unsigned int den2 = uniformUnsignedIntDistribution(generator);

        //generate data
        rationalNumber rn1(num1,den1);
        rationalNumber rn2 = rn1.rnLn();
        rationalNumber logarithm = log(rn1.getNumerator()) - log(rn1.getDenominator());
        ASSERT_GT(rn2.getDenominator(), 0);
        ASSERT_EQ(rn2, logarithm);
    }
}*/

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

