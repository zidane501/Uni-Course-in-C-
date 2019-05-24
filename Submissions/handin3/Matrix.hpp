#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include "Vector.hpp"

template<typename T>
class Matrix
{
private:
	double** mData; // entries of matrix
	int mNumRows, mNumCols; // dimensions
public:
	Matrix(const Matrix& otherMatrix);
	Matrix(int numRows, int numCols);
	~Matrix();
	T GetNumberOfRows() const;
	T GetNumberOfColumns() const;
	T& operator()(int i, int j);
	T const& operator()(int i, int j)const;
	//overloaded assignment operator
	Matrix& operator=(const Matrix& otherMatrix);
	Matrix operator-() const; // unary -
	Matrix operator+(const Matrix& m1) const; // binary +
	Matrix operator-(const Matrix& m1) const; // binary -
	// scalar multiplication
	Matrix operator*(double a) const;
};
//matrix-vector multiplications
Vector operator*(const Matrix& m, const Vector& v);
Vector operator*(const Vector& v, const Matrix& m);

#endif
