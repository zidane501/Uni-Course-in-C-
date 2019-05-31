#ifndef ORIGINALVECTORHEADERDEF
#define ORIGINALVECTORHEADERDEF

class originalVector
{
private:
	double* mData; // data stored in originalVector
	int mSize; // size of originalVector
public:
	originalVector(const originalVector& otheroriginalVector){
		mSize = otheroriginalVector.size();
		mData = new double [mSize];
		for (int i=0; i<mSize; i++)
		{
			mData[i] = otheroriginalVector.mData[i];
		}
	};

	originalVector(int size){
		assert(size > 0);
		mSize = size;
		mData = new double [mSize];
		
		for (int i=0; i<mSize; i++)
		{
			mData[i] = 0.0;
		}
	};

	~originalVector(){
		delete[] mData;
	};

	int size() const{
		return mSize;
	};
	double& operator[](int i){
		assert(i >= 0);
		assert(i < mSize);
		return mData[i];
	}; // zero-based indexing

	double const& operator[] (int i)const{
		assert(i >= 0);
		assert(i < mSize);
		return mData[i];
	}; // zero-based indexing
	
	// assignment
	originalVector& operator=(const originalVector& otheroriginalVector){
		assert(mSize == otheroriginalVector.mSize);
		for (int i=0; i<mSize; i++)
		{
			mData[i] = otheroriginalVector.mData[i];
		}
		return *this;
	};

	originalVector operator-() const{
		originalVector v(mSize);
		for (int i=0; i<mSize; i++)
		{
			v[i] = -mData[i];
		}
		return v;
	}; // unary -
	
	originalVector operator+(const originalVector& v1) const{
		assert(mSize == v1.mSize);
		originalVector v(mSize);
		for (int i=0; i<mSize; i++)
		{
			v[i] = mData[i] + v1.mData[i];
		}
		return v;
	}; // binary +
	
	originalVector operator-(const originalVector& v1) const{
		assert(mSize == v1.mSize);
		originalVector v(mSize);
		for (int i=0; i<mSize; i++)
		{
			v[i] = mData[i] - v1.mData[i];
		}
		return v;
	}; // binary -
	
	// scalar multiplication
	originalVector operator*(double a) const{
		originalVector v(mSize);
		for (int i=0; i<mSize; i++)
		{
			v[i] = a*mData[i];
		}
		return v;
	};

	// p-norm method
	double CalculateNorm(int p=2) const{
		double norm_val, sum = 0.0;
		for (int i=0; i<mSize; i++)
		{
			sum += pow(fabs(mData[i]), p);
		}
		norm_val = pow(sum, 1.0/((double)(p)));
		return norm_val;
	};
};

#endif