#include <cmath>
#include <iostream>
#include <cassert>
//#include "originalVector.hpp"

// Overridden copy constructor
// Allocates memory for new originalVector, and copies
// entries of other originalVector into it
originalVector::originalVector(const originalVector& otheroriginalVector)
{
	mSize = otheroriginalVector.size();
	mData = new double [mSize];
	for (int i=0; i<mSize; i++)
	{
		mData[i] = otheroriginalVector.mData[i];
	}
}

// Constructor for originalVector of a given size
// Allocates memory, and initialises entries
// to zero
originalVector::originalVector(int size)
{
	assert(size > 0);
	mSize = size;
	mData = new double [mSize];
	for (int i=0; i<mSize; i++)
	{
		mData[i] = 0.0;
	}
}

// Overridden destructor to correctly free memory
originalVector::~originalVector()
{
	delete[] mData;
}

// Method to get the size of a originalVector
int originalVector::size() const
{
	return mSize;
}

// Overloading square brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
double& originalVector::operator[](int i)
{
	assert(i >= 0);
	assert(i < mSize);
	return mData[i];
}

// Overloading square brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
double const& originalVector::operator[](int i)const{
	assert(i >= 0);
	assert(i < mSize);
	return mData[i];
}

// Overloading the assignment operator
originalVector& originalVector::operator=(const originalVector& otheroriginalVector){
	assert(mSize == otheroriginalVector.mSize);
	for (int i=0; i<mSize; i++)
	{
		mData[i] = otheroriginalVector.mData[i];
	}
	return *this;
}

// Overloading the unary - operator
originalVector originalVector::operator-() const
{
	originalVector v(mSize);
	for (int i=0; i<mSize; i++)
	{
		v[i] = -mData[i];
	}
	return v;
}

// Overloading the binary + operator
originalVector originalVector::operator+(const originalVector& v1) const
{
	assert(mSize == v1.mSize);
	originalVector v(mSize);
	for (int i=0; i<mSize; i++)
	{
		v[i] = mData[i] + v1.mData[i];
	}
	return v;
}

// Overloading the binary - operator
originalVector originalVector::operator-(const originalVector& v1) const
{
	assert(mSize == v1.mSize);
	originalVector v(mSize);
	for (int i=0; i<mSize; i++)
	{
		v[i] = mData[i] - v1.mData[i];
	}
	return v;
}

// Overloading scalar multiplication
originalVector originalVector::operator*(double a) const
{
	originalVector v(mSize);
	for (int i=0; i<mSize; i++)
	{
		v[i] = a*mData[i];
	}
	return v;
}

// Method to calculate norm (with default value p=2)
// corresponding to the Euclidean norm
double originalVector::CalculateNorm(int p) const
{
	double norm_val, sum = 0.0;
	for (int i=0; i<mSize; i++)
	{
		sum += pow(fabs(mData[i]), p);
	}
	norm_val = pow(sum, 1.0/((double)(p)));
	return norm_val;
}
