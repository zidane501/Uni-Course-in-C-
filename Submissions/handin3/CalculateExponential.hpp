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

double factorial(double n_i);

#endif

/* Codechecker wont accept my code but I get the right result after atleast 80 runs (n=80) for 3 different matrices:
(4 + 0i) (9 + 12i) (9 + 13i)
(9 + 11i) (4 - 1i) (9 + 13i)
(9 + 11i) (9 + 12i) (4 - 2i)

(2 + 2i) (2 + 2i) (2 + 2i)
(2 + 2i) (2 + 2i) (2 + 2i)
(2 + 2i) (2 + 2i) (2 + 2i)

(1 + 1i) (1 + 1i) (1 + 1i)
(1 + 1i) (1 + 1i) (1 + 1i)
(1 + 1i) (1 + 1i) (1 + 1i)

The results have been checked with online calculators of Matrix Exponentials.
*/ 