#include "projet.hpp"

int main(){
    return 0;
}

rationalNumber& rationalNumber::operator=(const rationalNumber &rn)
{
	if(&rn == this) return *this;

	m_data = rn.m_data;

	return *this;
}
 