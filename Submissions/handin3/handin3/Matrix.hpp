#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#include <cmath>
#include <cassert>
#include <vector>

#include "Vector.hpp"

template<typename T>
class Matrix{
	private:

		std::vector<T> mData; // entries of matrix
		int mNumRows, mNumCols; // dimensions
		int size;


	public:

		// Overwritten copy constructor
		// Allocate memory for new matrix, and copy
		// entries into this matrix
		Matrix(const Matrix<T>& otherMatrix){
		
			mNumRows = otherMatrix.mNumRows;
			mNumCols = otherMatrix.mNumCols;
			
			size = mNumRows*mNumCols;

			//mData = new std::vector<T>;

			for (int i=0; i<size; i++){
				mData.push_back(otherMatrix.mData[i]);
			}
			
		};

		// Constructor for vector of a given length
		// Allocates memory, and initialises entries
		// to zero
		Matrix(int numRows, int numCols){
			
			assert(numRows > 0);
			assert(numCols > 0);
			
			mNumRows = numRows;
			mNumCols = numCols;
			
			size = mNumRows*mNumCols;

			mData = std::vector<T>(size, 0.0);



			std::cout << "mdata" << mData[0] << std::endl;
						
		};

		// Overwritten destructor to correctly free memory
/*
		~Matrix(){	
			delete[] mData;
		}
*/
		int GetMatrixIndex(int i, int j) const {
			
			assert(i >= 0);
			assert(i < mNumRows);
			assert(j >= 0);
			assert(j < mNumCols);

			return i*GetNumberOfColumns() + j;
		}

		// Method to get number of rows of matrix
		int GetNumberOfRows() const{
			return mNumRows;
		}

		// Method to get number of columns of matrix
		int GetNumberOfColumns() const{
			return mNumCols;
		}

		std::vector<T> const& getStorage(){
			return mData;
		}
		// Overloading the round brackets
		// Note that this uses `zero-based' indexing,
		// and a check on the validity of the index
		T& operator()(int i, int j){ // What is the difference between "T& Matrix<T>" and "T const& Matrix<T>"

			assert(i >= 0);
			assert(i < mNumRows);
			assert(j >= 0);
			assert(j < mNumCols);
			
			return mData[GetMatrixIndex(i,j)];
		}

		T const& operator()(int i, int j)const{
			
			assert(i >= 0);
			assert(i < mNumRows);
			assert(j >= 0);
			assert(j < mNumCols);
			
			return mData[GetMatrixIndex(i,j)];
		}

		// Overloading the assignment operator
/*		Matrix<T>& operator=(const Matrix<T>& otherMatrix){
			
			assert(mNumRows == otherMatrix.mNumRows);
			assert(mNumCols == otherMatrix.mNumCols);

			for (int i=0; i<size; i++){
					mData[i] = otherMatrix.mData[i];
			}

			return *this;
		}
*/
		// Overloading the unary - operator

		Matrix<T> operator-() const{
			
			Matrix<T> mat(mNumRows, mNumCols);
			for (int i=0; i<size; i++){
				
				mat.mData[i] = -mData[i];
				
			}
			return mat;
		}

		// Overloading the binary + operator
		Matrix<T> operator+(const Matrix<T>& m1) const{

			assert(mNumRows == m1.mNumRows);
			assert(mNumCols == m1.mNumCols);

			Matrix<T> mat(mNumRows, mNumCols);
			
			for (int i=0; i<size; i++)	{	
				mat.mData[i] = mData[i] + m1.mData[i];
			}
			return mat;
		}

		// Overloading the binary - operator
		Matrix<T> operator-(const Matrix<T>& m1) const{

			assert(mNumRows == m1.mNumRows);
			assert(mNumCols == m1.mNumCols);

			Matrix<T> mat(mNumRows, mNumCols);
			
			for (int i=0; i<size; i++)	{	
				mat.mData[i] = mData[i] - m1.mData[i];
			}
			return mat;

		}

		// Overloading scalar multiplication
		Matrix<T> operator*(T a) const{
			
			Matrix<T> mat(mNumRows, mNumCols);
			
			for (int i=0; i<size; i++)	{	
				mat.mData[i] = a*mData[i];
			}

			return mat;
		}


};

// Overloading matrix multiplied by a vector
//matrix-vector multiplications
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

#endif
// Explicit template isntantiation

//template class Matrix<int>;
//template class Matrix<double>;
