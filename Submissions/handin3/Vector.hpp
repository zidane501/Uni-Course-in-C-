#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

template<typename T>
class Vector
{
private:
	double* mData; // data stored in vector
	int mSize; // size of vector
public:
	Vector(const Vector<T>& otherVector);
	Vector(int size);
	~Vector();
	int size() const;
	Vector<T>& operator[](int i); // zero-based indexing
	Vector<T> const& operator[] (int i)const; // zero-based indexing
	
	// assignment
	Vector<T>& operator=(const Vector<T>& otherVector);
	Vector<T> operator-() const; // unary -
	Vector<T> operator+(const Vector<T>& v1) const; // binary +
	Vector<T> operator-(const Vector<T>& v1) const; // binary -
	
	// scalar multiplication
	template<typename T>
	Vector<T> operator*(double a) const; // QUESTION: HOW TO MAKE THE ARGUMENTS TEMPLATES???
	
	// p-norm method
	Vector<T> CalculateNorm(int p=2) const;
};

#endif