#include <cmath>
#include <cassert>
#include "originalMatrix.hpp"
#include "originalVector.hpp"


// Overwritten copy constructor
// Allocate memory for new matrix, and copy
// entries into this matrix
originalMatrix::originalMatrix(const originalMatrix& otherMatrix)
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
originalMatrix::originalMatrix(int numRows, int numCols)
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
originalMatrix::~originalMatrix()
{
	for (int i=0; i<mNumRows; i++)
	{
		delete[] mData[i];
	}
	delete[] mData;
}

// Method to get number of rows of matrix
int originalMatrix::GetNumberOfRows() const
{
	return mNumRows;
}

// Method to get number of columns of matrix
int originalMatrix::GetNumberOfColumns() const
{
	return mNumCols;
}

// Overloading the round brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
double& originalMatrix::operator()(int i, int j)
{
	assert(i >= 0);
	assert(i < mNumRows);
	assert(j >= 0);
	assert(j < mNumCols);
	return mData[i][j];
}

double const& originalMatrix::operator()(int i, int j)const
{
	assert(i >= 0);
	assert(i < mNumRows);
	assert(j >= 0);
	assert(j < mNumCols);
	return mData[i][j];
}

// Overloading the assignment operator
originalMatrix& originalMatrix::operator=(const originalMatrix& otherMatrix)
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
originalMatrix originalMatrix::operator-() const
{
	originalMatrix mat(mNumRows, mNumCols);
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
originalMatrix originalMatrix::operator+(const originalMatrix& m1) const
{
	assert(mNumRows == m1.mNumRows);
	assert(mNumCols == m1.mNumCols);
	originalMatrix mat(mNumRows, mNumCols);
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
originalMatrix originalMatrix::operator-(const originalMatrix& m1) const
{
   assert(mNumRows == m1.mNumRows);
   assert(mNumCols == m1.mNumCols);
   originalMatrix mat(mNumRows, mNumCols);
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
originalMatrix originalMatrix::operator*(double a) const
{
   originalMatrix mat(mNumRows, mNumCols);
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
originalVector operator*(const originalMatrix& m, const originalVector& v)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfColumns() == original_vector_size);
	int new_vector_length = m.GetNumberOfRows();
	originalVector new_vector(new_vector_length);

	for (int i=0; i<new_vector_length; i++)
	{
		for (int j=0; j<original_vector_size; j++)
		{
			new_vector[i] += m(i,j)*v[j];
		}
	}

	return new_vector;
}

// Overloading vector multiplied by a originalMatrix
originalVector operator*(const originalVector& v, const originalMatrix& m)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfRows() == original_vector_size);
	int new_vector_length = m.GetNumberOfColumns();
	originalVector new_vector(new_vector_length);

	for (int i=0; i<new_vector_length; i++)
	{
		for (int j=0; j<original_vector_size; j++)
		{
			new_vector[i] += v[j]*m(j,i);
		}
	}

	return new_vector;
}
