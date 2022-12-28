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

/*
//fonctionne pas je sais pas pourquoi
TEST (rationalNumberConstructor, defaultConstructor){
  rationalNumber rn;
  ASSERT_EQ (rn.m_numerator, 0);
  ASSERT_EQ (rn.m_denominator, 1);
}
*/
/*
//je comprend pas comment on peut comparer les resultats de notre addition
//avec autre chose de manière aléatoire
TEST (rationalNumberArtihmetic, plus) {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> uniformIntDistribution(1,10);
  

  for(int run=0; run<100; ++run){
    int x1 = uniformIntDistribution(generator);
    unsigned int y1 = uniformIntDistribution(generator);
    int x2 = uniformIntDistribution(generator);
    unsigned int y2 = uniformIntDistribution(generator);

    //generate random data
    std::ratio<1,2> ratio1;
    std::ratio<int> ratio2(x2,y2);

    //build the corresponding rationalNumber
    rationalNumber rn1(x1,y1), rn2(x2,y2), rn3;
    rn3 = rn1 + rn2;

  }
}
*/

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

/*
//autre test 
//ne fonctionne pas ca compare pas les rationalNumber et les ratio ensemble
TEST (rationalNumberArtihmetic2, plus) {
  rationalNumber rn1(3,4);
  rationalNumber rn2(2,3);
  rationalNumber rnSum = rn1 + rn2;

  typedef std::ratio<3,4> ratio1;
  typedef std::ratio<2,3> ratio2;
  std::ratio_add<ratio1,ratio2> ratioSum;

  ASSERT_EQ(rnSum,ratioSum);
}
*/

TEST (rationalNumberArtihmetic1, minus) {

  for(int run=0; run<100; ++run){
  //generate data
  rationalNumber rn1(3,4);
  rationalNumber rn2(2,3);
  rationalNumber rn3 = rn1 - rn2;
  rationalNumber sum = (1,12);
  ASSERT_EQ(rn3, sum);
}
}

TEST (rationalNumberArtihmetic1, product) {
  for(int run=0; run<100; ++run){
  //generate data
  rationalNumber rn1(3,4);
  rationalNumber rn2(2,3);
  rationalNumber rn3 = rn1 * rn2;
  rationalNumber sum = (1,2);
  ASSERT_EQ(rn3, sum);
}
}

TEST (rationalNumberArtihmetic1, quotient) {
  for(int run=0; run<100; ++run){
  //generate data
  rationalNumber rn1(3,4);
  rationalNumber rn2(2,3);
  rationalNumber rn3 = rn1 / rn2;
  rationalNumber sum = (8,9);
  ASSERT_EQ(rn3, sum);
}
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

