#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <cmath>
#include <iostream>
#include <cassert>

template<typename T>
class Vector
{
	private:
		double* mData; // data stored in vector
		int mSize; // size of vector

	public:
		
		////////////////////////////////
		// Overridden copy constructor
		// Allocates memory for new vector, and copies
		// entries of other vector into it
		Vector(const Vector<T>& otherVector){
			std::cout << "Enter "<< " *Vector Constructor*" << std::endl;

			mSize = otherVector.size();
			mData = new double [mSize];

			for (int i=0; i<mSize; i++){
				mData[i] = otherVector.mData[i];
			}
			std::cout << "Leaving "<< " *Vector Constructor*" << std::endl;
		}

		////////////////////////////////
		// Constructor for vector of a given size
		// Allocates memory, and initialises entries
		// to zero
		Vector(int size){
	
			std::cout << "Enter "<< " *Vector Constructor*" << std::endl;
			assert(size > 0);
	
			mSize = size;
			mData = new double [mSize];
	
			for (int i=0; i<mSize; i++){
				mData[i] = 0.0;
			}
		};
		////////////////////////////////
		// Overridden destructor to correctly free memory
		~Vector(){
			std::cout << "Enter "<< " *Vector Destructor*" << std::endl;
			delete[] mData;
		};

		////////////////////////////////
		// Method to get the size of a vector
		int size() const{	
			std::cout << "Enter "<< " *Vector.size()*" << std::endl;
			return mSize;
		};

		////////////////////////////////
		// zero-based indexing
		// Overloading square brackets
		// Note that this uses `zero-based' indexing,
		// and a check on the validity of the index
		Vector<T>& operator[](int i){
			assert(i >= 0);
			assert(i < mSize);
			return mData[i];
		}

		////////////////////////////////
		// Overloading square brackets
		// Note that this uses `zero-based' indexing,
		// and a check on the validity of the index
		Vector<T> const& operator[] (int i)const{
			// zero-based indexing
			assert(i >= 0);
			assert(i < mSize);

			return mData[i];
		}; 

		// assignment
		Vector<T>& operator=(const Vector<T>& otherVector){
			
			assert(mSize == otherVector.mSize);
			
			for (int i=0; i<mSize; i++){
				mData[i] = otherVector.mData[i];
			}

			return *this;
		};

		////////////////////////////////
		// Overloading the unary - operator
		Vector<T> operator-() const{
			Vector v(mSize);
			for (int i=0; i<mSize; i++)
			{
				v[i] = -mData[i];
			}
			return v;
		}; 

		////////////////////////////////		
		// Overloading the binary + operator
		Vector<T> operator+(const Vector<T>& v1) const{

			assert(mSize == v1.mSize);
			Vector v(mSize);

			for (int i=0; i<mSize; i++){
				v[i] = mData[i] + v1.mData[i];
			}
			
			return v;
		}; // binary +

		////////////////////////////////		
		// Overloading the binary + operator
		Vector<T> operator-(const Vector<T>& v1) const{
		
			assert(mSize == v1.mSize);
			Vector v(mSize);
		
			for (int i=0; i<mSize; i++)	{
				v[i] = mData[i] - v1.mData[i];
			}

			return v;
		}; // binary -

		////////////////////////////////		
		// Overloading scalar multiplication
		Vector<T> operator*(double a) const{

			Vector v(mSize);
			
			for (int i=0; i<mSize; i++){
				v[i] = a*mData[i];
			}

			return v;
		}; // QUESTION: HOW TO MAKE THE ARGUMENTS TEMPLATES???

		////////////////////////////////		
		// p-norm method
		// Method to calculate norm (with default value p=2)
		// corresponding to the Euclidean norm
		Vector<T> CalculateNorm(int p=2) const{	
			std::cout << "Enter "<< " *Vector.CalculateNorm(p)*" << std::endl;

			double norm_val, sum = 0.0;

			for (int i=0; i<mSize; i++){
				sum += pow(fabs(mData[i]), p);
			}

			norm_val = pow(sum, 1.0/((double)(p)));
			
			return norm_val;
		};
};

#endif