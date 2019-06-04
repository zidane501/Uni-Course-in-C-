
#include "Vector.hpp"
#include "Matrix.hpp"

#include <cassert>
#include <iostream>

#include <stdlib.h>  // rand()

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

/////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////
/*void assertMatrices(Matrix<double> A, originalMatrix Ao){
    for (int i = 0; i < 3; i++){
        for (int j  = 0; j < 3; j++){
            assert(A(i,j)==A(i,j));
        }
    }
    
}
*/
void unit_tests(){

    int ni = 3;
    int nj = 3;
    
    Matrix mat(ni,nj);

    std::cout << "mat.GetNumberOfColumns(): " << mat.GetNumberOfColumns() << std::endl;
    std::cout << "mat.GetNumberOfRows(): "    << mat.GetNumberOfRows() << std::endl;
    
    /////////////////////////////////////////////////
    // Overloading of assignment operator
    Matrix A(ni,nj);
    A = mat;
    
    // Overloading the unary - operator
    std::cout << "Overloading the unary - operator: " <<  std::endl;
    Matrix B(ni,nj);
    B = -A;
    printMatrix(B,ni,nj, "B = -A");

    // v1 = rand() % 100;  // generate random number
    // Overloading the binary + operator
    Matrix C(ni,nj);
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
    int k = 3;
    C = B*k;
    printMatrix(C,ni,nj, "C = B*3");

    // Overloading matrix multiplied by a vector
    //matrix-vector multiplications
    Vector v(nj), v2(ni);
     
    printVector(v2,nj,"v");


    for (int i = 0; i < nj; i++){
        v[i] = rand() % 11;
        std::cout << "v[i] = rand() % 11 = " << v[i] << std::endl;
    }
    
    printMatrix(B,ni,nj, "B");
    printVector(v,nj,"v");

    // Overloading matrix multiplied by a vector
    //matrix-vector multiplications
    v2 = B*v;

    printVector(v2,ni,"v2 = B*v");

    //vector-matrix multiplications
    v2 = v*B;

    printVector(v2,ni,"v2 = v*B");

}

int main() {
    
    unit_tests();
    
    return 0;
}