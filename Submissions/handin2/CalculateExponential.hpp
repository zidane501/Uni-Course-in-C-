#ifndef _CALCULATEEXPONENTIAL_
#define _CALCULATEEXPONENTIAL_

#include "ComplexNumber.hpp"

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res);

//non mandatory
void printMatrix(ComplexNumber **A, int rows, int cols, std::string name); // change before codechecker!!!
//void printMatrix(ComplexNumber **A, std::string name); // change before codechecker!!!

void matrixComplAdd(ComplexNumber **A, ComplexNumber  **B, int n, ComplexNumber **res);

void multiplyCompl( ComplexNumber **A, ComplexNumber z, int n, ComplexNumber **res);

void calcPowMatrix(ComplexNumber **A, int n_i, ComplexNumber **res);

#endif
