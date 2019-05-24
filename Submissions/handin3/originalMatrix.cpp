#include <cmath>
#include <cassert>
#include "Matrix.hpp"
#include "Vector.hpp"


// Overwritten copy constructor
// Allocate memory for new matrix, and copy
// entries into this matrix
Matrix::Matrix(const Matrix& otherMatrix)
{
	mNumRows = otherMatrix.mNumRows;
	mNumCols = otherMatrix.mNumCols;
	mData = new double* [mNumRows];
	for (int i=0; i<mNumRows; i++)
	{
		mData[i] = new double [mNumCols];
	}
	for (int i=0; i<mNumRows; i++)
	{
		for (int j=0; j<mNumCols; j++)
		{
			mData[i][j] = otherMatrix.mData[i][j];
		}
	}
}

// Constructor for vector of a given length
// Allocates memory, and initialises entries
// to zero
Matrix::Matrix(int numRows, int numCols)
{
	assert(numRows > 0);
	assert(numCols > 0);
	mNumRows = numRows;
	mNumCols = numCols;
	mData = new double* [mNumRows];
	for (int i=0; i<mNumRows; i++)
	{
		mData[i] = new double [mNumCols];
	}
	for (int i=0; i<mNumRows; i++)
	{
		for (int j=0; j<mNumCols; j++)
		{
			mData[i][j] = 0.0;
		}
	}
}

// Overwritten destructor to correctly free memory
Matrix::~Matrix()
{
	for (int i=0; i<mNumRows; i++)
	{
		delete[] mData[i];
	}
	delete[] mData;
}

// Method to get number of rows of matrix
int Matrix::GetNumberOfRows() const
{
	return mNumRows;
}

// Method to get number of columns of matrix
int Matrix::GetNumberOfColumns() const
{
	return mNumCols;
}

// Overloading the round brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
double& Matrix::operator()(int i, int j)
{
	assert(i >= 0);
	assert(i < mNumRows);
	assert(j >= 0);
	assert(j < mNumCols);
	return mData[i][j];
}

double const& Matrix::operator()(int i, int j)const
{
	assert(i >= 0);
	assert(i < mNumRows);
	assert(j >= 0);
	assert(j < mNumCols);
	return mData[i][j];
}

// Overloading the assignment operator
Matrix& Matrix::operator=(const Matrix& otherMatrix)
{
	assert(mNumRows = otherMatrix.mNumRows);
	assert(mNumCols = otherMatrix.mNumCols);

	for (int i=0; i<mNumRows; i++)
	{
		for (int j=0; j<mNumCols; j++)
		{
			mData[i][j] = otherMatrix.mData[i][j];
		}
	}
	return *this;
}

// Overloading the unary - operator
Matrix Matrix::operator-() const
{
	Matrix mat(mNumRows, mNumCols);
	for (int i=0; i<mNumRows; i++)
	{
		for (int j=0; j<mNumCols; j++)
		{
			mat(i,j) = -mData[i][j];
		}
	}
	return mat;
}

// Overloading the binary + operator
Matrix Matrix::operator+(const Matrix& m1) const
{
	assert(mNumRows == m1.mNumRows);
	assert(mNumCols == m1.mNumCols);
	Matrix mat(mNumRows, mNumCols);
	for (int i=0; i<mNumRows; i++)
	{
		for (int j=0; j<mNumCols; j++)
		{
			mat(i,j) = mData[i][j] + m1.mData[i][j];
		}
	}
	return mat;
}

// Overloading the binary - operator
Matrix Matrix::operator-(const Matrix& m1) const
{
   assert(mNumRows == m1.mNumRows);
   assert(mNumCols == m1.mNumCols);
   Matrix mat(mNumRows, mNumCols);
   for (int i=0; i<mNumRows; i++)
   {
      for (int j=0; j<mNumCols; j++)
      {
         mat(i,j) = mData[i][j] - m1.mData[i][j];
      }
   }
   return mat;
}

// Overloading scalar multiplication
Matrix Matrix::operator*(double a) const
{
   Matrix mat(mNumRows, mNumCols);
   for (int i=0; i<mNumRows; i++)
   {
      for (int j=0; j<mNumCols; j++)
      {
         mat(i,j) = a*mData[i][j];
      }
   }
   return mat;
}

// Overloading matrix multiplied by a vector
Vector operator*(const Matrix& m, const Vector& v)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfColumns() == original_vector_size);
	int new_vector_length = m.GetNumberOfRows();
	Vector new_vector(new_vector_length);

	for (int i=0; i<new_vector_length; i++)
	{
		for (int j=0; j<original_vector_size; j++)
		{
			new_vector[i] += m(i,j)*v[j];
		}
	}

	return new_vector;
}

// Overloading vector multiplied by a matrix
Vector operator*(const Vector& v, const Matrix& m)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfRows() == original_vector_size);
	int new_vector_length = m.GetNumberOfColumns();
	Vector new_vector(new_vector_length);

	for (int i=0; i<new_vector_length; i++)
	{
		for (int j=0; j<original_vector_size; j++)
		{
			new_vector[i] += v[j]*m(j,i);
		}
	}

	return new_vector;
}
