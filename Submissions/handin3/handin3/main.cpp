
#include "Vector.hpp"
#include "Matrix.hpp"
#include "SparseVector.hpp"

#include "originalVector.hpp"
#include "originalMatrix.hpp"

#include <cassert>
#include <iostream>
#include <stdlib.h>  // rand()

template<typename T>
void printMatrix(const T& A, int rows, int cols, std::string name){

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

};

/////////////////////////////////////////////////////////////
template<typename T>
void printVector(const T& A, int indices, std::string name){
    // Vectors

    std::cout << "\n" << name << ":" << std::endl;   
    
    for (int i = 0; i < indices; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << "" << std::endl;
        
}

/////////////////////////////////////////////////////////////

void assertMatrices(Matrix<double>& A,  originalMatrix& AO, std::string name){
    for (int i = 0; i < A.GetNumberOfRows(); i++){
        for (int j  = 0; j < A.GetNumberOfColumns(); j++){
            
            try
            {
                assert(A(i,j)==AO(i,j));
            }
            catch(const std::exception& e){
                std::cout << "Assert error:" << std::endl;
                printMatrix(A,3,3, "A");
                printMatrix(AO,3,3, "AO");
                std::cerr << e.what() << '\n';
            }
        }
    }
    std::cout << name << ": asserting finished\n" << std::endl;
}

/////////////////////////////////////////////////////////////
void assertVectors(Vector<double>& v,  originalVector& vO, std::string name){
    
    for (int i = 0; i < v.size(); i++)
    {
        assert(v[i]==vO[i]);
    }
    std::cout << name << ": asserting finished\n" << std::endl;
}

/////////////////////////////////////////////////////////////
template<typename T>
void matrixCreation_UnitTest(Matrix<T>& mat, originalMatrix& matO, std::string name){
    
    assertMatrices(mat, matO, name);
    std::cout << "mat.GetNumberOfColumns(): " << mat.GetNumberOfColumns() << std::endl;
    std::cout << "mat.GetNumberOfRows(): "    << mat.GetNumberOfRows() << std::endl;

    std::cout << "mat.GetNumberOfColumns(): " << matO.GetNumberOfColumns() << std::endl;
    std::cout << "mat.GetNumberOfRows(): "    << matO.GetNumberOfRows() << std::endl;
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

void unit_tests(){

    int ni = 3;
    int nj = 3;
    
    Matrix<double> mat(ni,nj);
    originalMatrix matO(ni,nj);

    assertMatrices( mat, matO, "Matrix Creation: mat, matO");
    /////////////////////////////////////////////////
    // Overloading of assignment operator
    Matrix<double> A(ni,nj);
    A = mat;

    printMatrix(A,ni,nj, "Overloading of assignment operator--A=mat");
    originalMatrix AO(ni,nj);
    AO = matO;

    assertMatrices(A, AO, "A=AO");

    // Overloading the unary - operator
    std::cout << "Overloading the unary - operator: " <<  std::endl;
    
    Matrix<double> B(ni,nj);
    originalMatrix BO(ni,nj);

    B = -A;
    BO = -AO;


    
    printMatrix(BO,ni,nj, "BO = -AO");
    printMatrix(B,ni,nj, "B = -A");
    assertMatrices(B, BO, "B = -A");
    
    // v1 = rand() % 100;  // generate random number
    // Overloading the binary + operator
    Matrix<double> C(ni,nj);
    originalMatrix CO(ni,nj);
    
    for (int i = 0; i < ni; i++){
        for (int j = 0; j < ni; j++){
            B(i,j) = rand() % 10+1;
            BO(i,j) = B(i,j);
        }   
    }

    printMatrix(B,ni,nj, "B");
    printMatrix(BO,ni,nj, "B");
    // Overloading the binary + operator
    C = B + B;
    CO = BO + BO;
    
    //printMatrix(C,ni,nj, "C = B + B");

    assertMatrices(C,  CO, "C = B + B");

    // Overloading the binary - operator
    C = B - C;
    CO = BO - CO;
    
    //printMatrix(C,ni,nj, "C = B - C");
    assertMatrices(C,  CO, "C = B + B");
    
    // Overloading scalar multiplication
    int k = 3;
    C = B*k;
    CO = BO*k;

    printMatrix(C,ni,nj, "C = B*3");
    assertMatrices(C,  CO, "C = B + B");
    
    // Overloading matrix multiplied by a vector
    //matrix-vector multiplications
    Vector<double> v(nj), v2(ni);
    originalVector vO(nj), v2O(ni);
    
    printVector(v2,nj,"v");


    for (int i = 0; i < nj; i++){
        v[i] = rand() % 11;
        vO[i] = v[i];
        std::cout << "vO[i] = rand() % 11 = " << vO[i] << std::endl;
    }
    
    printMatrix(B,ni,nj, "B");
    printVector(v,nj,"v");
    
    // Overloading matrix multiplied by a vector
    //matrix-vector multiplications
    v2 = B*v;
    v2O = BO*vO;

    printVector(v2,ni,"v2 = B*v");
    printVector(v2,ni,"v2 = B*v");
    assertVectors(v2,  v2O, "v2 = B*v");

    //vector-matrix multiplications
    v2 = v*B;
    v2O = vO*BO;

    printVector(v2,ni,"v2 = v*B");
    assertVectors(v2,  v2O, "v2O = BO*vO");

    
}

void sparsevector(){

    int n = 4;

    // Creation
    SparseVector<double> sparse(n), sparse1(n), sparse2(n);
    std::cout << "sparse.size(): " << sparse.size() << std::endl;
    
    
    // Set Value
    sparse.setValue(3,1);
    //sparse.setValue(4,1);
    //sparse.setValue(9,1);
    sparse1.setValue(1,1.0);

    std::cout << "sparse after setting value:" << std::endl;
    for (int i = 0; i < sparse.size(); i++)
    {
        std::cout << "sparse[i] " << sparse.getValue(i) << std::endl;
    }
    
    //sparse += sparse1; 
/*
    for (int i = 0; i < sparse.size(); i++)
    {
        std::cout << "sparse[" << i <<"]: " << sparse.getValue(i) << std::endl;
    }
*/

    /////////////////////////////////
    sparse = sparse1+sparse;

    std::cout << "sparse = sparse1+sparse:" << std::endl;

    for (int i = 0; i < sparse.size(); i++)
    {
        std::cout << "sparse[" << i <<"]: " << sparse.getValue(i) << std::endl;
    }

    
    /////////////////////////////////
    // Matrix sparse-vector multiplication dv=M*sv:
    Vector<double> vec(n);
    vec[0] = 1;
    vec[2] = 3;
    
    Matrix<double> mat(n,n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
       {
            mat(i,j) = rand() % 10;
            std::cout << "mat(" << i << "," << j << "): " <<  mat(i,j) << ", ";
        }
        
    }
    
    vec = sparse*mat;

    std::cout << "vec = sparse*mat:" << std::endl;
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << "vec[" << i << "]: " << vec[i] << std::endl;
    }
}

int main() {
    
    //unit_tests();
    
    sparsevector();
    
    return 0;
}