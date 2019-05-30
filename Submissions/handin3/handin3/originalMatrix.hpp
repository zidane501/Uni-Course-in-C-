#ifndef ORIGINALMATRIXHEADERDEF
#define ORIGINALMATRIXHEADERDEF
#include "originalVector.hpp"

class originalMatrix
{
private:
	double** mData; // entries of originalMatrix
	int mNumRows, mNumCols; // dimensions
public:
	originalMatrix(const originalMatrix& otherOriginalMatrix);
	originalMatrix(int numRows, int numCols);
	~originalMatrix();
	int GetNumberOfRows() const;
	int GetNumberOfColumns() const;
	double& operator()(int i, int j);
	double const& operator()(int i, int j)const;
	
	//overloaded assignment operator
	originalMatrix& operator=(const originalMatrix& otherOriginalMatrix);
	originalMatrix operator-() const; // unary -
	originalMatrix operator+(const originalMatrix& m1) const; // binary +
	originalMatrix operator-(const originalMatrix& m1) const; // binary -
	
	// scalar multiplication
	originalMatrix operator*(double a) const;
};
//originalMatrix-vector multiplications
originalVector operator*(const originalMatrix& m, const originalVector& v);
originalVector operator*(const originalVector& v, const originalMatrix& m);

#endif
