#include <cmath>
#include <cassert>
#include "Matrix.hpp"
#include "Vector.hpp"


// Overwritten copy constructor
// Allocate memory for new matrix, and copy
// entries into this matrix
template<typename T>
 Matrix<T>::Matrix(const Matrix<T>& otherMatrix){
	
	mNumRows = otherMatrix.mNumRows;
	mNumCols = otherMatrix.mNumCols;
	
	mData = new T* [mNumRows];
	
	for(int i=0; i<mNumRows; i++){
		mData[i] = new T [mNumCols];
	}
}

// Constructor for vector of a given length
// Allocates memory, and initialises entries
// to zero
template<typename T>
Matrix<T>::Matrix(int numRows, int numCols){
	
	assert(numRows > 0);
	assert(numCols > 0);
	
	mNumRows = numRows;
	mNumCols = numCols;
	
	mData = new T* [mNumRows*numCols];
	
	for (int i=0; i<mNumRows*numCols; i++){
		mData[i] = 0.0;
	}
	
}

// Overwritten destructor to correctly free memory
template<typename T>
Matrix<T>::~Matrix(){
	
	delete[] mData;
}

template<typename T>
int Matrix<T>::GetMatrixIndex(int i, int j) const {
	return i*GetNumberOfRows()+GetNumberOfColumns();
}
// Method to get number of rows of matrix
template<typename T>
int Matrix<T>::GetNumberOfRows() const{
	return mNumRows;
}

// Method to get number of columns of matrix
template<typename T>
int Matrix<T>::GetNumberOfColumns() const{
	return mNumCols;
}

// Overloading the round brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
template<typename T>
T& Matrix<T>::operator()(int i, int j){ // What is the difference between "T& Matrix<T>" and "T const& Matrix<T>"

	assert(i >= 0);
	assert(i < mNumRows);
	assert(j >= 0);
	assert(j < mNumCols);

	return mData[GetMatrixIndex(i,j)];
}

template<typename T>
T const& Matrix<T>::operator()(int i, int j)const{

	assert(i >= 0);
	assert(i < mNumRows);
	assert(j >= 0);
	assert(j < mNumCols);

	return mData[GetMatrixIndex(i,j)];
}

// Overloading the assignment operator
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& otherMatrix){
	
	assert(mNumRows = otherMatrix.mNumRows);
	assert(mNumCols = otherMatrix.mNumCols);

	for (int i=0; i<mNumRows*mNumCols; i++)
	{
			mData[i] = otherMatrix.mData[i];
	}
	return *this;
}

// Overloading the unary - operator
template<typename T>
Matrix<T> Matrix<T>::operator-() const{
	
	Matrix<T> mat(mNumRows, mNumCols);
	for (int i=0; i<mNumRows*mNumCols; i++){
		
		mat.mData[i] = -mData[i];
		
	}
	return mat;
}

// Overloading the binary + operator
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m1) const{

	assert(mNumRows == m1.mNumRows);
	assert(mNumCols == m1.mNumCols);

	Matrix<T> mat(mNumRows, mNumCols);
	
	for (int i=0; i<mNumRows*mNumCols; i++)	{	
		mat.mData[i] = mData[i] + m1.mData[i];
	}
	return mat;
}

// Overloading the binary - operator
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m1) const{

   assert(mNumRows == m1.mNumRows);
   assert(mNumCols == m1.mNumCols);
   Matrix<T> mat(mNumRows, mNumCols);
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
template<typename T>
Matrix<T> Matrix<T>::operator*(double a) const{
	
   Matrix<T> mat(mNumRows, mNumCols);
   
   for (int i=0; i<mNumRows; i++){
      for (int j=0; j<mNumCols; j++){
         mat(i,j) = a*mData[i][j];
      }
   }
   return mat;
}

// Overloading matrix multiplied by a vector
template<typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v){
	
	int original_vector_size = v.size();
	assert(m.GetNumberOfColumns() == original_vector_size);
	int new_vector_length = m.GetNumberOfRows();
	Vector<T> new_vector(new_vector_length);

	for (int i=0; i<new_vector_length; i++){
		for (int j=0; j<original_vector_size; j++){
			new_vector[i] += m(i,j)*v[j];
		}
	}

	return new_vector;
}

// Overloading vector multiplied by a matrix
template<typename T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m){
	
	int original_vector_size = v.size();
	
	assert(m.GetNumberOfRows() == original_vector_size);
	
	int new_vector_length = m.GetNumberOfColumns();
	
	Vector<T> new_vector(new_vector_length);

	for (int i=0; i<new_vector_length; i++){
		for (int j=0; j<original_vector_size; j++){
			new_vector[i] += v[j]*m(j,i);
		}
	}

	return new_vector;
}
