#include "ComplexNumber.hpp"
#include "CalculateExponential.hpp"
#include <string>

void matrixComplAdd( ComplexNumber **A, ComplexNumber  **B, int n, ComplexNumber **res){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            
            res[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyCompl( ComplexNumber **A, ComplexNumber **B, int n, ComplexNumber **res){
    
    //std::cout << "Multiply!!!" << " "  << std::endl;
    
    ComplexNumber res_ij;
    for(int i = 0; i < n; i++){ // i = row;
        for(int j = 0; j < n; j++){ // j = col;
            res_ij  = 0;
            
            // Multiply row * col (k = col)
            for(int k = 0; k < n; k++){
                res_ij = res_ij + A[i][k]*B[k][j];
                //std::cout << "A[i][k]*B[k][j]: " << A[i][k]<< "*" << B[k][j] << std::endl;    
            }

            // Create intermediate matrix to "save" values of A^n
            res[i][j] = res_ij; 
            //std::cout << res_ij << " " << res[i][j] << std::endl;
            
        }
    }
    //printMatrix(res,3,3, "Name:");
};

//////////////////////////////////////

void multiplyCompl( ComplexNumber **A, ComplexNumber z, int n, ComplexNumber **res){
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            
            res[i][j] = A[i][j]*z;
            //std::cout << "A[i][j]*z: " << A[i][j] << "*" << z << 
            //" = " << A[i][j]*z << std::endl;
        }
    }
}

//////////////////////////////////////////////

void calcPowMatrix(ComplexNumber **A, int n_i, ComplexNumber **res){
    // Calculates A^n

    int n = 3;
    ////////////
    // Creation
    ComplexNumber** resN = new ComplexNumber* [n];
    for (int i=0; i<n; i++){
        resN[i] = new ComplexNumber[n]; // used to calc A^n
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            resN[i][j] = A[i][j]; 
        }
    }
    ////////////

    for (int k = 1; k < n_i; k++){ // mp A*A*A*A... to create each led
            
        //std::cout << "k = " << k << std::endl;
        
        //printMatrix(resN,3,3,"resN:");
        
        multiplyCompl(A, resN, n, res);    
        
        //printMatrix(res,3,3,"pow Res:");
        
        // Put values back into resN
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                resN[i][j] = res[i][j]; 
            }
        }
    }
    ////////////
    // Deletion
    for (int i=0; i<n; i++)
    {
        delete[] resN[i];
    }
    delete[] resN;
}

//////////////////////////////////

double factorial(double n_i){
    //std::cout << "n_i: " << n_i << std::endl;

    return (n_i == 1 || n_i == 0) ? 1 : factorial(n_i - 1) * n_i;

}

///////////////////////////////////////////
///////////////////////////////////////////

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res){
    printMatrix(A,3,3, "Start matrix A:");
    int n = 3;
    
    ////////////
    // Creation
    ComplexNumber** newRes = new ComplexNumber* [n];
    
    for (int i=0; i<n; i++){
        newRes[i] = new ComplexNumber[n]; // used to calc A^n
    }
    
    ////////////

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            newRes[i][j] = A[i][j]; 
        }        
    }

    res[0][0] = res[0][0] + ComplexNumber(1,0);
    res[1][1] = res[1][1] + ComplexNumber(1,0);
    res[2][2] = res[2][2] + ComplexNumber(1,0);
    
    // n = 0;
    //std::cout << "n_i = " << 0 << std::endl;
    //printMatrix(res,n,n, "**res for n = 0:");
    
    matrixComplAdd(res, A, n, res);
    
    // n = 1;
    std::cout << "n_i = " << 0 << std::endl;
    //printMatrix(res,n,n, "**res for n = 1:");

    for (int n_i = 2; n_i < nMax; n_i++){ // for hvert led i summen
        
        calcPowMatrix(A,n_i, newRes);
        //std::cout << "ComplexNumber(1.0/factorial(n_i),0): " << ComplexNumber(1.0/factorial(n_i),0) <<
        //" | factorial(n_i): " << factorial(n_i) << " | n_i: " << n_i << std::endl;

        //printMatrix(newRes,n,n, "newRes before 1/factorial");
        multiplyCompl(newRes,ComplexNumber(1.0/factorial(n_i),0), n, newRes);
        
        //printMatrix(newRes,n,n, "newRes after 1/factorial");

        matrixComplAdd(res,newRes, n, res);

        //std::cout << "**res for n = " << n_i << std::endl;
        //printMatrix(res,n,n, "**res");
    }
    
    
    ////////////
    // Deletion
    for (int i=0; i<n; i++)
    {
        delete[] newRes[i];
    }

    delete[] newRes;
    
};

///////////////////////////////////////////
///////////////////////////////////////////

void printMatrix(ComplexNumber **A, int rows, int cols, std::string name){
        std::cout << name << ":" << std::endl;
        std::cout << A[0][0] << " " << A[0][1] << " " << A[0][2] << std::endl;
        std::cout << A[1][0] << " " << A[1][1] << " " << A[1][2] << std::endl;
        std::cout << A[2][0] << " " << A[2][1] << " " << A[2][2] << std::endl;
};
