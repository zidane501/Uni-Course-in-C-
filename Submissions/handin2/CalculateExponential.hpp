#ifndef _CALCULATEEXPONENTIAL_
#define _CALCULATEEXPONENTIAL_

#include "ComplexNumber.hpp"

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res);

//non mandatory
void printMatrix(ComplexNumber **A, int rows, int cols, std::string name);

void matrixComplAdd(ComplexNumber **A, ComplexNumber  **B, int n, ComplexNumber **res);

void multiplyCompl( ComplexNumber **A, ComplexNumber z, int n, ComplexNumber **res);

#endif
