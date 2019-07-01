#include <iostream>
#include <cassert>
#include <string>
#include "5_9.h"






void Multiply1_5_9( double **res , double **A, double **B,
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
    }

};

void P_matrix_5_9(double **P, int n, int row1, int row2){ 
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bool a = (i==j && j != row1 && i != row1 && j != row2 && i != row2);
            bool b = (i == row1 && j == row2);

            if( (i==j && (i != row1 && i != row2)) || (i == row1 && j == row2) || (j == row1 && i == row2)){
                P[i][j] = 1;
            }else{
                P[i][j] = 0;            
            }
        }
    }
    
    
};

void solve3by3(double **A, double *b, double *u){

    /////////////////////////////////////////////////
    double M_i0;
    double A_ij;
    double b_i;
    int matrixSize; // used for switching rows 
    int row2; // used for switching rows
    double A_ik_max;
    int n = 3;

    // matrixPrintOut_5_9(A, n, "A");

    for(int k = 1; k < n; k++){
        // Check for zero index and switch rows
        
        if(A[k-1][k-1]==0){
            A_ik_max = -10000.0;

            matrixSize = n-k+1;
            
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
                    newA[a][b] = A[a+(k-1)][b+(k-1)];
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
            
            // Switch rows in b-vector
            double b1 = b[k-1];
            double b2 = b[row2];
            
            // Create P-matrix
            P_matrix_5_9(P, matrixSize, 0, row2);
            // Multiply P with newA
            Multiply1_5_9(newAafter, P, newA, matrixSize, matrixSize, matrixSize, matrixSize);
            
            // return newA to A
            for (int a = k-1; a < n; a++)
            {
                for (int b = k-1; b < n; b++)
                {
                    A[a][b] = newAafter[a-(k-1)][b-(k-1)];
                }
            }

            b[row2] = b1;
            b[k-1] = b2;
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
        
        
        double A00 = A[k-1][k-1];
                for (int j = k-1; j < n; j++)
        {
            A[k-1][j] = A[k-1][j]/A00;
        }
        
        b[k-1] = b[k-1]/A00;
        

        for(int i = k; i < n; i++){

            M_i0 = A[i][k-1]/A[k-1][k-1];
        
            for(int j = k-1; j < n; j++){
                A[i][j] = A[i][j] - M_i0 * A[k-1][j];            
            }
            b[i] = b[i]-M_i0*b[k-1];
        }
        

    }

    double c;
    int k;

    for(int a = 0; a < n; a++){
        k = n-1-a;
        c = 0;
        for(int i = k; i<n-1; i++){
            c += A[k][i+1]*u[i+1];
        }

        u[k] = (1/A[k][k])*(b[k]-c);
    }
///////////////////////////////////////////////////////////////////
};