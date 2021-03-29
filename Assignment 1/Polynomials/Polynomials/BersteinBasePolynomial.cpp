#include "BernsteinBasePolynomial.h"
#include <math.h>

BernsteinBasePolynomial::BernsteinBasePolynomial() : fFactor(0, 0) {} // Default Constructor initialized which 
                                                                      //initiliazes fFactor as BBP header includes Combintion header

BernsteinBasePolynomial::BernsteinBasePolynomial(unsigned int aV, unsigned int aN) : fFactor(aN, aV) {} //Constructor with parameters which also
                                                                                                        //is used as arguments to initialize fFactor

double BernsteinBasePolynomial::operator()(double aX) const 
{
    unsigned long long lC = fFactor();
    unsigned int lN = fFactor.getN();
    unsigned int lV = fFactor.getK();
    int lT = lN - aV;
    return lC * pow(aX, lV) * pow((1 - aX), lT); //formula as given
}