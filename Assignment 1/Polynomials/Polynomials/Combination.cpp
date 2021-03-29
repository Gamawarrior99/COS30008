#include "Combination.h"

Combination::Combination(unsigned int aN, unsigned int aK)
{
	fN = aN;
	fK = aK;
}

unsigned int Combination::getN() const 
{
	return fN;
}

unsigned int Combination::getK() const 
{
	return fK;
}

unsigned long long Combination::operator()() const 
{
	// added safety checks
	if (fK > fN) return 0;
	if (fK == fN) return 1;

	unsigned long long lTotal = 1;
	for (int lk = 1; lk <= fK; lk++) //while local k is <= value of k(user/automate)
	{
		lTotal *= ((unsigned long long)fN - lk + 1);
		lTotal /= lk;
		//formula as given
	}
	return lTotal;
}