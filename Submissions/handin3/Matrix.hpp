#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF

#include "Vector.hpp"

template<typename T>
class Matrix{
private:

	T* mData; // entries of matrix
	int mNumRows, mNumCols; // dimensions

public:

	Matrix(const Matrix& otherMatrix);
	Matrix(int numRows, int numCols);

	~Matrix();

	int GetNumberOfRows() const;
	int GetNumberOfColumns() const;
	int GetMatrixIndex(int i, int j) const ; // Added by me

	T& operator()(int i, int j);
	T const& operator()(int i, int j)const;

	//overloaded assignment operator
	Matrix<T>& operator=(const Matrix<T>& otherMatrix);
	Matrix<T> operator-() const; // unary -
	Matrix<T> operator+(const Matrix<T>& m1) const; // binary +
	Matrix<T> operator-(const Matrix<T>& m1) const; // binary -

	// scalar multiplication
	Matrix<T> operator*(double a) const;


};

//matrix-vector multiplications
template<typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v);

template<typename T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m);

#endif
