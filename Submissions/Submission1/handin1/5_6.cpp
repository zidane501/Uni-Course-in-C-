// #include <iostream>
#include <cassert>
//#include <cmath>
//#include <vector>
//#include <iomanip>
//#include <fstream>
// #include "2_6.h"
// #include "3_3.h"
// #include "5_4.h"
#include "5_6.h"
// #include "5_9.h"
// #include "5_10.h"

// l.tirca@di.ku.dk

// using namespace std;

// 5.6
void Multiply( double **res , double **A, double **B,
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

};

void Multiply( double *res , double *A, double **B,
              int ACols , int BRows , int BCols )
{
    double res_i;

    assert(ACols == BRows);

    for(int i = 0; i < BCols; i++){

        res_i  = 0;

        for(int k = 0; k < BRows; k++){
            res_i += A[k]*B[k][i];
        }

        res[i] = res_i;

        //// cout << "res_i" << " " << res[i] << endl;
    }

};

void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows){
    double res_i;

    assert(ACols == BRows);

    for(int i = 0; i < ARows; i++){

        res_i  = 0;

        for(int k = 0; k < ACols; k++){
            res_i += A[i][k]*B[k];
        }
        res[i] = res_i;
    }
};

void Multiply(double **res, double scalar, double **B, int BRows, int BCols){

    for(int i = 0; i < BRows; i++){

        for(int k = 0; k < BCols; k++){
            res[i][k] = B[i][k]*scalar;
        }

    }
};
void Multiply(double **res, double **B, double scalar, int BRows, int BCols){
    for(int i = 0; i < BRows; i++){

        for(int k = 0; k < BCols; k++){
            res[i][k] = B[i][k]*scalar;
        }

    }
};
