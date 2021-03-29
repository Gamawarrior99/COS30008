#include "Polynomial.h"
#include <math.h>

double Polynomial::operator()(double aX) const 
{
	double lTotal = 0;

	for (int i = fDegree; i >= 0; i--)
	{
		lTotal += fCoeffs[i] * pow(aX, i);
	}
	return lTotal;
}

Polynomial Polynomial::getDifferential() const 
{
	Polynomial lTotal;
	//calcualtion for differential using Differentiation Formula
	for (int i = fDegree; i >= 0; i--) //loops the amount of the maximum degree of the polynomial
	{
		lTotal.fCoeffs[i - 1] = fCoeffs[i] * i; // coeff x i(power)
	}

	//safety checks
	if (fDegree - 1 >= 0)
	{
		lTotal.fDegree = fDegree - 1 <= MAX_POLYNOMIAL ? fDegree - 1 : MAX_POLYNOMIAL; //power - 1
	}
	else
	{
		lTotal.fDegree = 0;
	}

	return lTotal; // result is coeff x i(power) x^ power - 1
}

Polynomial Polynomial::getIndefiniteIntegral() const 
{
	Polynomial lTotal;
	// calculated using integration Formula 

	// added safety checks
	if (fDegree + 1 <= MAX_POLYNOMIAL) 
	{
		lTotal.fDegree = fDegree + 1; //Degree + 1
	}
	else
	{
		lTotal.fDegree = MAX_POLYNOMIAL;
	}

	for (int i = lTotal.fDegree - 1; i >= 0; i--)
	{
		lTotal.fCoeffs[i + 1] = fCoeffs[i] / ((double)i + 1); //coeff/(i(power) + 1)
	}

	return lTotal; //result is coeff/(i(power) + 1) x^ i(power)-1
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const 
{
	Polynomial lA = getIndefiniteIntegral(); //calcualte the inDefiniteIntegral 
	return double(lA(aXHigh) - lA(aXLow)); //return value after solving with upper and lower
}