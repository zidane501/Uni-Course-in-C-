/*
#include "originalVector.hpp"
#include "originalMatrix.hpp"
#include "originalSparseVector.hpp"
*/
#include "Vector.hpp"
#include "Matrix.hpp"
//#include "SparseVector.hpp"

#include <cassert>
#include <iostream>

template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}


void unit_tests(){

    int n = 3;
    double m = 3;
    Matrix<double> mat(3,3);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            std::cout << "something" << std::endl;
            std::cout << "matrixNew(i,j): " << mat(i,j) << std::endl;
        }   
    }
}

int main() {
    
    /*int i=5, j=6, k;
    long l=10, m=5, n;
    k=GetMax<int>(i,j);
    n=GetMax<long>(l,m);
    std::cout << "k " << k << std::endl;
    std::cout << "n " << n << std::endl;
    */
    
    unit_tests();
    
    return 0;
}