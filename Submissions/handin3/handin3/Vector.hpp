#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <cmath>
#include <iostream>
#include <cassert>
#include <vector>

template<typename T>
class Vector
{
	private:
		//T* mData; // data stored in vector
		int mSize; // size of vector
		std::vector<T> mData;
		bool mDebug = false;
	public:
		
		////////////////////////////////
		// Overridden copy constructor
		// Allocates memory for new vector, and copies
		// entries of other vector into it
		Vector(const Vector<T>& otherVector){
			std::cout << "Enter "<< " *Vector(const Vector<T>& otherVector)* - copyconstructor" << std::endl;

			mSize = otherVector.size();
			
			for (int i=0; i<mSize; i++){
			mData.push_back(otherVector.mData[i]);
			}

		}

		////////////////////////////////
		// Constructor for vector of a given size
		// Allocates memory, and initialises entries
		// to zero
		Vector(int size, bool debug=false){
			mDebug = debug;
			if (mDebug){
				std::cout << "Constructor mDebug: "<< mDebug << std::endl;
				std::cout << "Enter "<< " *Vector(int size)* - constructor" << std::endl;
				std::cout << "size:" << size << std::endl;
			}
			
			assert(size > 0);
	
			mSize = size;
			
	
			mData = std::vector<T>(size, 0.0);
		};

		std::vector<T> const& getStorage(){
			return mData;
		}
		////////////////////////////////
		// Overridden destructor to correctly free memory
/*		
		~Vector(){
			if (mDebug){
				std::cout << "Enter "<< " *~destructor()*" << std::endl;
			}
			
			delete[] mData;
		};
*/
		////////////////////////////////
		// Method to get the size of a vector

		int size() const{
			if (mDebug){
				std::cout << "Enter "<< " *size()*" << std::endl;
			}
				
			return mSize;
		};

		////////////////////////////////
		// zero-based indexing
		// Overloading square brackets
		// Note that this uses `zero-based' indexing,
		// and a check on the validity of the index

		T& operator[](int i){
		
			if (mDebug){
				std::cout << "mDebug: "<< mDebug << std::endl;
				std::cout << "Enter "<< " *Overloading square brackets []*" << std::endl;
			}
			
			assert(i >= 0);
			assert(i < mSize);
		
			return mData[i];
		}

		////////////////////////////////
		// Overloading square brackets
		// Note that this uses `zero-based' indexing,
		// and a check on the validity of the index

		T const& operator[] (int i)const{
		
			if (mDebug){
				std::cout << "mDebug: "<< mDebug << std::endl;
				std::cout << "Enter "<< " *Overloading square brackets []*" << std::endl;
			}
			
			// zero-based indexing
			assert(i >= 0);
			assert(i < mSize);	

			return mData[i];
		}; 

		// assignment
/*
		Vector<T>& operator=(const Vector<T>& otherVector){
			if (mDebug){
				std::cout << "Enter "<< " *Overloading the assignment = operator*" << std::endl;
			}
		
			assert(mSize == otherVector.mSize);
			
			for (int i=0; i<mSize; i++){
				mData[i] = otherVector.mData[i];
			}

			return *this;
		};
*/
		////////////////////////////////
		// Overloading the unary - operator

		Vector<T> operator-() const{
			if (mDebug){
				std::cout << "Enter "<< " *Overloading the unary - operator*" << std::endl;
			}
	
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
			if (mDebug){
				std::cout << "Enter "<< " *Overloading the binary + operator*" << std::endl;
			}
		
			assert(mSize == v1.mSize);
			Vector v(mSize);

			for (int i=0; i<mSize; i++){
				v[i] = mData[i] + v1.mData[i];
			}
			
			return v;
		}; // binary +

		////////////////////////////////		
		// Overloading the binary - operator
		Vector<T> operator-(const Vector<T>& v1) const{
			if (mDebug){
				std::cout << "Enter "<< " *Overloading the binary - operator*" << std::endl;
			}
			
			assert(mSize == v1.mSize);
			Vector v(mSize);
		
			for (int i=0; i<mSize; i++)	{
				v[i] = mData[i] - v1.mData[i];
			}

			return v;
		}; // binary -

		////////////////////////////////		
		// Overloading scalar multiplication
		Vector<T> operator*(T a) const{
			if (mDebug){
				std::cout << "Enter "<< " *Overloading scalar multiplication*" << std::endl;
			}
			
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
		double CalculateNorm(int p=2) const{	
			if (mDebug){
				std::cout << "Enter "<< " *Vector.CalculateNorm(p)*" << std::endl;
				std::cout << "mSize "<< mSize << std::endl;
			}
			
			double norm_val, sum = 0.0;

			for (int i=0; i<mSize; i++){
				sum += pow(fabs(mData[i]), p);
			}

			norm_val = pow(sum, 1.0/((double)(p)));
			
			return norm_val;
		};
};

#endif