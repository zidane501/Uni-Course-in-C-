#ifndef ORIGINALVECTORHEADERDEF
#define ORIGINALVECTORHEADERDEF

class originalVector
{
private:
	double* mData; // data stored in originalVector
	int mSize; // size of originalVector
public:
	originalVector(const originalVector& otheroriginalVector);
	originalVector(int size);
	~originalVector();
	int size() const;
	double& operator[](int i); // zero-based indexing
	double const& operator[] (int i)const; // zero-based indexing
	// assignment
	originalVector& operator=(const originalVector& otheroriginalVector);
	originalVector operator-() const; // unary -
	originalVector operator+(const originalVector& v1) const; // binary +
	originalVector operator-(const originalVector& v1) const; // binary -
	// scalar multiplication
	originalVector operator*(double a) const;
	// p-norm method
	double CalculateNorm(int p=2) const;
};

#endif