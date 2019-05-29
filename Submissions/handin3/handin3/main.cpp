
#include "Vector.hpp"
#include "Matrix.hpp"

#include <cassert>
#include <iostream>

#include <stdlib.h>  // rand()

template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}

template<typename T>
void printMatrix(const T A, int rows, int cols, std::string name){

    if ((rows == 3) & (cols == 3)){
        std::cout << "\n" << name << ":" << std::endl;
        
        std::cout << A(0,0) << " " << A(0,1) << " " << A(0,2) << std::endl;
        std::cout << A(1,0) << " " << A(1,1) << " " << A(1,2) << std::endl;
        std::cout << A(2,0) << " " << A(2,1) << " " << A(2,2) << std::endl;
        
        std::cout << "" << std::endl;
    }

    if ((rows == 3) & (cols == 2)){
        std::cout << "\n" << name << ":" << std::endl;
        
        std::cout << A(0,0) << " " << A(0,1) << std::endl;
        std::cout << A(1,0) << " " << A(1,1) << std::endl;
        std::cout << A(2,0) << " " << A(2,1) << std::endl;
        
        std::cout << "" << std::endl;
    }

    if ((rows == 2) & (cols == 3)){
        std::cout << "\n" << name << ":" << std::endl;
        
        std::cout << A(0,0) << " " << A(0,1) << " " << A(0,2) << std::endl;
        std::cout << A(1,0) << " " << A(1,1) << " " << A(1,2) << std::endl;
        
        std::cout << "" << std::endl;
    }
/*
    // Vectors
    if ((rows == 2) & (cols == 0)){
        std::cout << "\n" << name << ":" << std::endl;
        
        std::cout << A[0] << std::endl;
        std::cout << A[1] << std::endl;
        
        std::cout << "" << std::endl;
    }

    if ((rows == 3) & (cols == 0)){
        std::cout << "\n" << name << ":" << std::endl;
        
        std::cout << A[0] << std::endl;
        std::cout << A[1] << std::endl;
        std::cout << A[2] << std::endl;        
        std::cout << "" << std::endl;
    }
*/
};

template<typename T>
void printVector(const T A, int indices, std::string name){
        // Vectors
    if (indices == 2){
        std::cout << "\n" << name << ":" << std::endl;
        
        std::cout << A[0] << std::endl;
        std::cout << A[1] << std::endl;
        
        std::cout << "" << std::endl;
    }

    if (indices == 3){
        std::cout << "\n" << name << ":" << std::endl;
        
        std::cout << A[0] << std::endl;
        std::cout << A[1] << std::endl;
        std::cout << A[2] << std::endl;        
        std::cout << "" << std::endl;
    }
}

void unit_tests(){

    int ni = 3;
    int nj = 3;
    
    Matrix<double> mat(ni,nj);

    printMatrix(mat,ni,nj, "Overloading of ()-operator -- mat");
    //std::cout << "mat.GetMatrixIndex(2,3): " << mat.GetMatrixIndex(2,3) << std::endl;
    std::cout << "mat.GetNumberOfColumns(): " << mat.GetNumberOfColumns() << std::endl;
    std::cout << "mat.GetNumberOfRows(): " << mat.GetNumberOfRows() << std::endl;

    // Overloading of assignment operator
    Matrix<double> A(ni,nj);
    A = mat;
    printMatrix(A,ni,nj, "Overloading of assignment operator--A=mat");
    

    // Overloading the unary - operator
    std::cout << "Overloading the unary - operator: " <<  std::endl;
    Matrix<double> B(ni,nj);
    B = -A;
    printMatrix(B,ni,nj, "B = -A");

    // v1 = rand() % 100;  // generate random number
    // Overloading the binary + operator
    Matrix<double> C(ni,nj);
    for (int i = 0; i < ni; i++){
        for (int j = 0; j < ni; j++){
            B(i,j) = rand() % 10+1; 
        }   
    }
    printMatrix(B,ni,nj, "B");

    // Overloading the binary + operator
    C = B + B;
    printMatrix(C,ni,nj, "C = B + B");

    // Overloading the binary - operator
    C = B - C;
    printMatrix(C,ni,nj, "C = B - C");

    // Overloading scalar multiplication
    double k = 3;
    C = B*k;
    printMatrix(C,ni,nj, "C = B*3");

    // Overloading matrix multiplied by a vector
    //matrix-vector multiplications
    Vector<double> v(nj), v2(ni);
    std::cout << v[0] << std::endl;
     
    //printVector(v2,nj,"v");

/*
    for (int i = 0; i < nj; i++){
        v[i] = rand() % 11;
    }
    printVector(v2,nj,"v");


    v2 = B*v;

    printVector(v2,ni,"v2 = B*v");
*/
}

int main() {
    
    unit_tests();
    
    return 0;
}