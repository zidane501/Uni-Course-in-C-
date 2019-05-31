#ifndef ORIGINALMATRIXHEADERDEF
#define ORIGINALMATRIXHEADERDEF
#include "originalVector.hpp"

class originalMatrix
{
private:
	double** mData; // entries of originalMatrix
	int mNumRows, mNumCols; // dimensions
public:
	originalMatrix(const originalMatrix& otherOriginalMatrix){
		mNumRows = otherOriginalMatrix.mNumRows;
		mNumCols = otherOriginalMatrix.mNumCols;
		mData = new double* [mNumRows];
		for (int i=0; i<mNumRows; i++)
		{
			mData[i] = new double [mNumCols];
		}
		for (int i=0; i<mNumRows; i++)
		{
			for (int j=0; j<mNumCols; j++)
			{
				mData[i][j] = otherOriginalMatrix.mData[i][j];
			}
		}
	};

	originalMatrix(int numRows, int numCols){
		
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
	};

	~originalMatrix(){
		for (int i=0; i<mNumRows; i++){
			delete[] mData[i];
		}
		delete[] mData;
	};
	
	int GetNumberOfRows() const{
		return mNumRows;
	};
	
	int GetNumberOfColumns() const{
		return mNumCols;
	};

	double& operator()(int i, int j){
		assert(i >= 0);
		assert(i < mNumRows);
		assert(j >= 0);
		assert(j < mNumCols);
		return mData[i][j];
	};

	double const& operator()(int i, int j)const{
		assert(i >= 0);
		assert(i < mNumRows);
		assert(j >= 0);
		assert(j < mNumCols);
		return mData[i][j];
	};
	
	//overloaded assignment operator
	originalMatrix& operator=(const originalMatrix& otherOriginalMatrix){
		assert(mNumRows = otherOriginalMatrix.mNumRows);
		assert(mNumCols = otherOriginalMatrix.mNumCols);

		for (int i=0; i<mNumRows; i++)
		{
			for (int j=0; j<mNumCols; j++)
			{
				mData[i][j] = otherOriginalMatrix.mData[i][j];
			}
		}
		return *this;
	};

	// unary -
	originalMatrix operator-() const{
		originalMatrix mat(mNumRows, mNumCols);
		for (int i=0; i<mNumRows; i++)
		{
			for (int j=0; j<mNumCols; j++)
			{
				mat(i,j) = -mData[i][j];
			}
		}
		return mat;
	}; 

	// binary +
	originalMatrix operator+(const originalMatrix& m1) const{
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
	}; 

	// Overloading the binary - operator
	originalMatrix operator-(const originalMatrix& m1) const{
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
	}; // binary -
	
	// scalar multiplication
	originalMatrix operator*(double a) const{
		originalMatrix mat(mNumRows, mNumCols);
		for (int i=0; i<mNumRows; i++)
		{
			for (int j=0; j<mNumCols; j++)
			{
				mat(i,j) = a*mData[i][j];
			}
		}
		return mat;
	};

};

//originalMatrix-vector multiplications
originalVector operator*(const originalMatrix& m, const originalVector& v){
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
};

// Overloading vector multiplied by a originalMatrix
originalVector operator*(const originalVector& v, const originalMatrix& m){
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
};


#endif
