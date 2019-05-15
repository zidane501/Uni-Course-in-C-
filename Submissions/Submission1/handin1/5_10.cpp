// #include <iostream>
#include <cassert>
// #include <math.h>
// #include <vector>
// #include <iomanip>
// #include <fstream>
// #include "2_6.h"
// #include "3_3.h"
// #include "5_4.h"
#include "5_6.h"
// #include "5_9.h"
// #include <string>
#include "5_10.h"



////////////////////////////////////////////////////////////////////////////////////////////
//5.10
/*void matrixPrintOut(double **M, int n, std::string name){
    // Prints out n*n matrix
    
    // // cout << name << ": " << endl;

    if(n==2){
        // cout << M[0][0] << " " << M[0][1] << endl;
        // cout << M[1][0] << " " << M[1][1] << endl;
        
    }

    if(n==3){
        // cout << M[0][0] << " " << M[0][1] << " " << M[0][2] << endl;
        // cout << M[1][0] << " " << M[1][1] << " " << M[1][2] << endl;
        // cout << M[2][0] << " " << M[2][1] << " " << M[2][2] << endl;
    }
    
    if(n==4){
        // cout << M[0][0] << " " << M[0][1] << " " << M[0][2] << M[0][3] << endl;
        // cout << M[1][0] << " " << M[1][1] << " " << M[1][2] << M[1][3] <<  endl;
        // cout << M[2][0] << " " << M[2][1] << " " << M[2][2] << M[2][3] << endl;
        // cout << M[3][0] << " " << M[3][1] << " " << M[3][2] << M[3][3] << endl;
    }
};*/

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
            //// cout << res_ij << " " << res[i][j] << endl;
    }

};*/

void P_matrix(double **P, int n, int row1, int row2){ 
    //row1 = k, ,row2 = n

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bool a = (i==j && j != row1 && i != row1 && j != row2 && i != row2);
            bool b = (i == row1 && j == row2);

            // // cout << "i,j: " << i << "," << j << " | Row1 " << row1 << " Row2 " << row2 << endl;

            if( (i==j && (i != row1 && i != row2)) || (i == row1 && j == row2) || (j == row1 && i == row2)){
                //// cout << "(i==j && (i != row1 && i != row2))                        : " << (i==j && (i != row1 && i != row2)) << endl;
                //// cout << "(i == row1 && j == row2)                                  : " << (i == row1 && j == row2) << endl;
                //// cout << "(j == row1 && i == row2)                                  : " << (j == row1 && i == row2) << endl;

                P[i][j] = 1;
                //// cout << "P[i,j]: " << P[i][j] << " " << 1 << endl;
            }else{
                //// cout << "(i==j && (i != row1 && i != row2))                        : " << (i==j && (i != row1 && i != row2)) << endl;
                //// cout << "(i == row1 && j == row2)                                  : " << (i == row1 && j == row2) << endl;
                //// cout << "(j == row1 && i == row2)                                  : " << (j == row1 && i == row2) << endl;  
                P[i][j] = 0;
                //// cout << "P[i,j]: " << P[i][j] << " " << 0 << endl;
                

            }
        }
    }
    // matrixPrintOut(P, n, "P");
    
    //Multiply(res,P,B,n,n,n,n);
    //// matrixPrintOut(B, n, "res");

    
};

void guassian_elimination(double **A, double *b, double *u, int n){
    

    /////////////////////////////////////////////////
    double M_i0;
    double A_ij;
    double b_i;
    int matrixSize; // used for switching rows 
    int row2; // used for switching rows
    double A_ik_max = 0;

    // matrixPrintOut(A, n, "A");

    for(int k = 1; k < n; k++){
        // Check for zero index and switch rows
        if(A[k-1][k-1]==0){
            matrixSize = n-k; // // cout << "matrixSize: " << matrixSize  << endl;
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
            // find row2 to switch with row0
            for (int i = 0; i < matrixSize; i++)
            {
                if (A[i][k-1]*A[i][k-1]>A_ik_max*A_ik_max)
                {
                    row2 = i;
                    A_ik_max = A[i][k-1];
                }
                
            }
            
            
            // Create new matrix to multiply with P-matrix
            for (int a = k-1; a < matrixSize; a++)
            {
                
                for (int b = k-1; b < matrixSize; b++)
                {
                    //// cout << "a: " << a << " b: " << b << endl;
                    //// cout << "a-(k-1): " << a-(k-1) << " b-(k-1): " << b-(k-1) << endl;

                    newA[a][b] = A[a-(k-1)][b-(k-1)];
                    
                    //// cout << "DB" << endl;
                }    
            }

            // Create P-matrix
            P_matrix(P, matrixSize, 0, row2);
            // Multiply P with newA
            // matrixPrintOut(newA, matrixSize, "newA");
            Multiply(newAafter, P, newA, matrixSize, matrixSize, matrixSize, matrixSize);
            // matrixPrintOut(newAafter, matrixSize, "newA");
            //// cout << "Debugger 1" << endl;
            
            // return newA to A
            for (int a = k-1; a < matrixSize; a++)
            {
                for (int b = k-1; b < matrixSize; b++)
                {
                    A[a][b] = newAafter[a-(k-1)][b-(k-1)];
                }
            }
            // matrixPrintOut(A,3,"A");

            // // cout << "Debugger 2" << endl;
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
        for(int i = k; i < n; i++){

            M_i0 = A[i][k-1]/A[k-1][k-1];
//            // cout << "M_i0: " << M_i0 << endl;

            for(int j = k-1; j < n; j++){
                A[i][j] = A[i][j] - M_i0 * A[k-1][j];
//                // cout << "A_" << i << "," << j << ": " << A[i][j] << endl;
                //A[i][j] = A_ij;
            }
            b[i] = b[i]-M_i0*b[k-1];
            //// cout << "b_" << i << ": " << b[i] << endl;
        }
    }
    // Valgrind checks for memory leaks

    double c;
    int k;

    for(int a = 0; a < n; a++){
  //      // cout << "hello there mate " << endl;
        k = n-1-a;
        //// cout << "k: " << k << endl;
        c = 0;
        for(int i = k; i<n-1; i++){
            c += A[k][i+1]*u[i+1];
   //         // cout << "k: " << k << endl;
   //         // cout << "i+1 " << i+1 << endl;
        }

        u[k] = (1/A[k][k])*(b[k]-c);
//        // cout << "b[k]: " << b[k] << " | c: " << c << endl;
        // cout << "u[k]: " << u[k] << " | k: " << k << endl;
    }
///////////////////////////////////////////////////////////////////
};