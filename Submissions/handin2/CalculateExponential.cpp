#include "ComplexNumber.hpp"
#include <string>

void matrixComplAdd( ComplexNumber **A, ComplexNumber  **B, int n, ComplexNumber **res){

    for (int i = 0; i < 3n; i++){
        for (int j = 0; j < n; j++){
            
            res[i,j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyCompl( ComplexNumber **A, ComplexNumber **B, int n, ComplexNumber **res){
    ////////////
    // Creation


    ////////////
    ComplexNumber res_ij;
    for(int i = 0; i < n; i++){ // i = row;
        for(int j = 0; j < n; j++){ // j = col;
            res_ij  = 0;
            
            // Multiply row * col (k = col)
            for(int k = 0; k < n; k++){
                res_ij = res_ij + A[i][k]*B[k][j];
            }

            // Create intermediate matrix to "save" values of A^n
            res[i][j] = res_ij; 
            //// cout << res_ij << " " << res[i][j] << std::endl;
        }
    }
    
};

int factorial(int n){
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

void multiplyCompl( ComplexNumber **A, ComplexNumber z, int n, ComplexNumber **res){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            
            res[i,j] = A[i][j]*z;
        }
    }
}

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res){

    ComplexNumber res_ij;
    int n = 3;
    double factorial_n = 1;

    ////////////
    // Creation
    ComplexNumber** newRes = new ComplexNumber* [n];
    ComplexNumber** resN = new ComplexNumber* [n];
    for (int i=0; i<n; i++){
        newRes[i] = new ComplexNumber[n]; // used to calc A^n
        resN[i] = new ComplexNumber[n];
    }

    ////////////
    for (int n_i = 1; n_i < nMax; n_i++){ // for each led in the sum
        
        for (int mp_i = 1; mp_i < n_i; mp_i++){ // mp A*A*A*A... to create each led
            
            multiplyCompl(A, newRes, n, resN); 
            
            // Put values back into newRes
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    newRes[i][j] = resN[i][j]; 
                }
            }

        }
        multiplyCompl(newRes,factorial(n_i), n, newRes);
        matrixComplAdd(res,newRes, n, res);
    }
    ////////////
    // Deletion
    for (int i=0; i<n; i++)
    {
        delete[] newRes[i];
        delete[] resN[i];
    }

    delete[] newRes;
    delete[] resN;
    
    };


void printMatrix(ComplexNumber **A, int rows, int cols, std::string name){
        std::cout << name << ":" << std::endl;
        std::cout << A[0][0] << " " << A[0][1] << " " << A[0][2] << std::endl;
        std::cout << A[1][0] << " " << A[1][1] << " " << A[1][2] << std::endl;
        std::cout << A[2][0] << " " << A[2][1] << " " << A[2][2] << std::endl;
};
