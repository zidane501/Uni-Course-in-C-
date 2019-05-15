#ifndef TEST_5_6
#define TEST_5_6

void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols); // Matrix*Matrix
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols); // vector*Matrix
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows); // Matrix*vector
void Multiply(double **res, double scalar, double **B, int BRows, int BCols) ; // Scalar*Matrix
void Multiply(double **res, double **B, double scalar, int BRows, int BCols) ; // Matrix*Scalar

#endif
