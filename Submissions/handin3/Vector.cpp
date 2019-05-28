#include <cmath>
#include <iostream>
#include <cassert>
#include "Vector.hpp"

// Overridden copy constructor
// Allocates memory for new vector, and copies
// entries of other vector into it
template<typename T>
Vector<T>::Vector(const Vector<T>& otherVector)
{
	std::cout << "Enter "<< " *Vector Constructor*" << std::endl;
	
	mSize = otherVector.size();
	mData = new double [mSize];
	
	for (int i=0; i<mSize; i++){
		mData[i] = otherVector.mData[i];
	}
	std::cout << "Leaving "<< " *Vector Constructor*" << std::endl;
}

// Constructor for vector of a given size
// Allocates memory, and initialises entries
// to zero
template<typename T>
Vector<T>::Vector(int size)
{
	std::cout << "Enter "<< " *Vector Constructor*" << std::endl;
	assert(size > 0);
	mSize = size;
	mData = new double [mSize];
	for (int i=0; i<mSize; i++)
	{
		mData[i] = 0.0;
	}
}

// Overridden destructor to correctly free memory
template<typename T>
Vector<T>::~Vector()
{
	std::cout << "Enter "<< " *Vector Destructor*" << std::endl;
	delete[] mData;
}

// Method to get the size of a vector
template<typename T>
int Vector<T>::size() const
{	
	std::cout << "Enter "<< " *Vector.size()*" << std::endl;
	return mSize;
}

// Overloading square brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
template<typename T>
Vector<T>& Vector<T>::operator[](int i)
{
	assert(i >= 0);
	assert(i < mSize);
	return mData[i];
}

// Overloading square brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
template<typename T>
Vector<T> const& Vector<T>::operator[](int i)const{
	assert(i >= 0);
	assert(i < mSize);

	return mData[i];
}

// Overloading the assignment operator
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& otherVector){
	assert(mSize == otherVector.mSize);
	for (int i=0; i<mSize; i++)
	{
		mData[i] = otherVector.mData[i];
	}
	return *this;
}

// Overloading the unary - operator
template<typename T>
Vector<T> Vector<T>::operator-() const
{
	Vector v(mSize);
	for (int i=0; i<mSize; i++)
	{
		v[i] = -mData[i];
	}
	return v;
}

// Overloading the binary + operator
template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& v1) const{

	assert(mSize == v1.mSize);
	Vector v(mSize);
	for (int i=0; i<mSize; i++)
	{
		v[i] = mData[i] + v1.mData[i];
	}
	return v;
}

// Overloading the binary - operator
template<typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& v1) const
{
	assert(mSize == v1.mSize);
	Vector v(mSize);
	for (int i=0; i<mSize; i++)
	{
		v[i] = mData[i] - v1.mData[i];
	}
	return v;
}

// Overloading scalar multiplication
template<typename T>
Vector<T> Vector<T>::operator*(double a) const{

	Vector v(mSize);
	for (int i=0; i<mSize; i++)
	{
		v[i] = a*mData[i];
	}
	return v;
}

// Method to calculate norm (with default value p=2)
// corresponding to the Euclidean norm
template<typename T>
Vector<T> Vector<T>::CalculateNorm(int p) const
{	
	std::cout << "Enter "<< " *Vector.CalculateNorm(p)*" << std::endl;

	double norm_val, sum = 0.0;
	for (int i=0; i<mSize; i++)
	{
		sum += pow(fabs(mData[i]), p);
	}
	norm_val = pow(sum, 1.0/((double)(p)));
	return norm_val;
}

template class Vector<int>;
template class Vector<double>;