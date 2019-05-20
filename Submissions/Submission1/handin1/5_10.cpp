#include <iostream>
#include <cassert>
#include <limits>
// #include <math.h>
// #include <vector>
// #include <iomanip>
// #include <fstream>
// #include "2_6.h"
// #include "3_3.h"
// #include "5_4.h"
// #include "5_6.h"
// #include "5_9.h"
#include <string>
#include "5_10.h"



////////////////////////////////////////////////////////////////////////////////////////////
//5.10
void matrixPrintOut(double **M, int n, std::string name){
    // Prints out n*n matrix
    
    // std::cout << name << ": " << std::endl;

    if(n==2){
        // std::cout << M[0][0] << " " << M[0][1] << std::endl;
        // std::cout << M[1][0] << " " << M[1][1] << std::endl;
        
    }

    if(n==3){
        // std::cout << M[0][0] << " " << M[0][1] << " " << M[0][2] << std::endl;
        // std::cout << M[1][0] << " " << M[1][1] << " " << M[1][2] << std::endl;
        // std::cout << M[2][0] << " " << M[2][1] << " " << M[2][2] << std::endl;
    }
    
    if(n==4){
        // std::cout << M[0][0] << " " << M[0][1] << " " << M[0][2] << " " << M[0][3] << std::endl;
        // std::cout << M[1][0] << " " << M[1][1] << " " << M[1][2] << " " << M[1][3] << std::endl;
        // std::cout << M[2][0] << " " << M[2][1] << " " << M[2][2] << " " << M[2][3] << std::endl;
        // std::cout << M[3][0] << " " << M[3][1] << " " << M[3][2] << " " << M[3][3] << std::endl;
    }
};

/*void Multiply( double **res , double **A, double **B,
              int ARows , int ACols , int BRows , int BCols )
{

    double res_ij;

    assert(ACols == BRows);

    for(int i = 0; i < ARows; i++)
        for(int j = 0; j < BCols; j++){
            res_ij  = 0;
            for(int k = 0; k < ACols; k++){
                res_ij += A[i][k]*B[k][j];
            }
            res[i][j] = res_ij;
            //// cout << res_ij << " " << res[i][j] << std::endl;
    }

};*/
void Multiply1( double **res , double **A, double **B,
              int ARows , int ACols , int BRows , int BCols )
{

    double res_ij;

    assert(ACols == BRows);

    for(int i = 0; i < ARows; i++)
        for(int j = 0; j < BCols; j++){
            res_ij  = 0;
            for(int k = 0; k < ACols; k++){
                res_ij += A[i][k]*B[k][j];
            }
            res[i][j] = res_ij;
            //// cout << res_ij << " " << res[i][j] << std::endl;
    }

};

void P_matrix(double **P, int n, int row1, int row2){ 
    //row1 = k, ,row2 = n

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bool a = (i==j && j != row1 && i != row1 && j != row2 && i != row2);
            bool b = (i == row1 && j == row2);

            // // cout << "i,j: " << i << "," << j << " | Row1 " << row1 << " Row2 " << row2 << std::endl;

            if( (i==j && (i != row1 && i != row2)) || (i == row1 && j == row2) || (j == row1 && i == row2)){
                //// cout << "(i==j && (i != row1 && i != row2))                        : " << (i==j && (i != row1 && i != row2)) << std::endl;
                //// cout << "(i == row1 && j == row2)                                  : " << (i == row1 && j == row2) << std::endl;
                //// cout << "(j == row1 && i == row2)                                  : " << (j == row1 && i == row2) << std::endl;

                P[i][j] = 1;
                //// cout << "P[i,j]: " << P[i][j] << " " << 1 << std::endl;
            }else{
                //// cout << "(i==j && (i != row1 && i != row2))                        : " << (i==j && (i != row1 && i != row2)) << std::endl;
                //// cout << "(i == row1 && j == row2)                                  : " << (i == row1 && j == row2) << std::endl;
                //// cout << "(j == row1 && i == row2)                                  : " << (j == row1 && i == row2) << std::endl;  
                P[i][j] = 0;
                //// cout << "P[i,j]: " << P[i][j] << " " << 0 << std::endl;
                

            }
        }
    }
    // matrixPrintOut(P, n, "P");
    
    //Multiply(res,P,B,n,n,n,n);
    //// matrixPrintOut(B, n, "res");

    
};

void guassian_elimination(double **A, double *b, double *u, int n){
/* 
    A[0][0] = 0;  A[0][1] =  1;  A[0][2] =  1; A[0][3] = -2; 
    A[1][0] = 1;  A[1][1] =  2;  A[1][2] = -1; A[1][3] =  0;
    A[2][0] = 2;  A[2][1] =  4;  A[2][2] =  1; A[2][3] = -3;
    A[3][0] = 1;  A[3][1] = -4;  A[3][2] = -7; A[3][3] = -1;

    v[0] =  -3; 
    v[1] =   2; 
    v[2] =  -2;
    v[3] = -19;
*/

    /////////////////////////////////////////////////
    double M_i0;
    double A_ij;
    double b_i;
    int matrixSize; // used for switching rows 
    int row2; // used for switching rows
    double A_ik_max;

    matrixPrintOut(A, n, "A");

    for(int k = 1; k < n; k++){
        // Check for zero index and switch rows
        // std::cout << "New Round: k-1: " << k-1 << std::endl;
        // std::cout << "A[k-1][k-1]: " << A[k-1][k-1] << std::endl;
        
        if(A[k-1][k-1]==0){
            A_ik_max = -std::numeric_limits<double>::max();

            matrixSize = n-k+1;
            
            // std::cout << "matrixSize: " << matrixSize  << std::endl;

            // Creation:
            double** P = new double* [matrixSize];
            double** newA = new double* [matrixSize];
            double** newAafter = new double* [matrixSize];

            for (int i=0; i<matrixSize; i++){
                P[i] = new double [matrixSize];
                newA[i] = new double [matrixSize];
                newAafter[i] = new double [matrixSize];
            }//
            //////////////////////
            
            // Create new matrix to multiply with P-matrix
            for (int a = 0; a < matrixSize; a++)
            {
                
                for (int b = 0; b < matrixSize; b++)
                {
                    //// cout << "a: " << a << " b: " << b << std::endl;
                    //// cout << "a-(k-1): " << a-(k-1) << " b-(k-1): " << b-(k-1) << std::endl;

                    newA[a][b] = A[a+(k-1)][b+(k-1)];
                    
                    //// cout << "DB" << std::endl;
                }    
            }

            // find row2 to switch with row0
            for (int i = 0; i < matrixSize; i++)
            {
                if (newA[i][0]*newA[i][0]>A_ik_max)
                {
                    row2 = i+k;
                    A_ik_max = newA[i][0];


                }
                
            }
            // std::cout << "Row2: " << row2  << std::endl;
            // Switch rows in b-vector
            double b1 = b[k-1];
            double b2 = b[row2];
            
            matrixPrintOut(newA, matrixSize, "newA");
            // Create P-matrix
            P_matrix(P, matrixSize, 0, row2);
            // Multiply P with newA
            Multiply1(newAafter, P, newA, matrixSize, matrixSize, matrixSize, matrixSize);
            matrixPrintOut(newAafter, matrixSize, "newAafter");
            //// cout << "Debugger 1" << std::endl;
            
            // return newA to A
            for (int a = k-1; a < n; a++)
            {
                for (int b = k-1; b < n; b++)
                {
                    A[a][b] = newAafter[a-(k-1)][b-(k-1)];
                }
            }

            matrixPrintOut(A,n,"newAfter returned to A");

            // std::cout << "Switch b[i]. Before: "  << std::endl;
            // std::cout << "b[0]: " << b[0]  << std::endl;
            // std::cout << "b[1]: " << b[1]  << std::endl;
            // std::cout << "b[2]: " << b[2]  << std::endl;
            // std::cout << "b[3]: " << b[3]  << std::endl;
            b[row2] = b1;
            b[k-1] = b2;
            // std::cout << "Switch b[i]. After: "  << std::endl;
            // std::cout << "b[0]: " << b[0]  << std::endl;
            // std::cout << "b[1]: " << b[1]  << std::endl;
            // std::cout << "b[2]: " << b[2]  << std::endl;
            // std::cout << "b[3]: " << b[3]  << std::endl;

            // // cout << "Debugger 2" << std::endl;
            //////////////////////
            // Deletion:
            for(int i=0; i<matrixSize; i++)
            {
                delete[] P[i];
                delete[] newA[i];
                delete[] newAafter[i];
            }
            delete[] newA;
            delete[] newAafter;
            delete[] P; //

        }
        // Continue with finding matrix solutions
        // std::cout << "Continue with finding matrix solutions (creating zeros under index ii):" << std::endl;
        
        matrixPrintOut(A, n, "A before:");
        
        // std::cout << "b[0]: " << b[0]  << std::endl;
        // std::cout << "b[1]: " << b[1]  << std::endl;
        // std::cout << "b[2]: " << b[2]  << std::endl;
        // std::cout << "b[3]: " << b[3]  << std::endl;

        
        double A00 = A[k-1][k-1];
                for (int j = k-1; j < n; j++)
        {
            // // std::cout << "A[k-1][j] before: " << A[k-1][j] << std::endl;
            A[k-1][j] = A[k-1][j]/A00;
            // // std::cout << "A[k-1][j] after:" << A[k-1][j] << std::endl;  
        }
        
        b[k-1] = b[k-1]/A00;
        
        matrixPrintOut(A, n, "A normalized:");
        // std::cout << "b[k-1] " << b[k-1] << std::endl;

        for(int i = k; i < n; i++){

            M_i0 = A[i][k-1]/A[k-1][k-1];
            // std::cout << "M_i0: " << M_i0 << std::endl;

            for(int j = k-1; j < n; j++){
                A[i][j] = A[i][j] - M_i0 * A[k-1][j]; // Line[i] - M_ij*Line[k-1] (k-1 being the first line in the remaining matrix)
                // Puts zero everywhere under the first column.
                // std::cout << "A_" << i << "," << j << ": " << A[i][j] << std::endl;
                //A[i][j] = A_ij;
            }
            b[i] = b[i]-M_i0*b[k-1];
            // std::cout << "b_" << i << ": " << b[i] << std::endl;
        }
        matrixPrintOut(A, n, "A");
        
        // std::cout << "b[0]: " << b[0]  << std::endl;
        // std::cout << "b[1]: " << b[1]  << std::endl;
        // std::cout << "b[2]: " << b[2]  << std::endl;
        // std::cout << "b[3]: " << b[3]  << std::endl;

    }
    // Valgrind checks for memory leaks

    double c;
    int k;

    for(int a = 0; a < n; a++){
  //      // cout << "hello there mate " << std::endl;
        k = n-1-a;
        //// cout << "k: " << k << std::endl;
        c = 0;
        for(int i = k; i<n-1; i++){
            c += A[k][i+1]*u[i+1];
   //         // cout << "k: " << k << std::endl;
   //         // cout << "i+1 " << i+1 << std::endl;
        }

        u[k] = (1/A[k][k])*(b[k]-c);
//        // cout << "b[k]: " << b[k] << " | c: " << c << std::endl;
        // cout << "u[k]: " << u[k] << " | k: " << k << std::endl;
    }
///////////////////////////////////////////////////////////////////
};