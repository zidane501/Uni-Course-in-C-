#include <iostream>
#include <cassert>
#include <math.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include "2_6.h"
#include "3_3.h"
#include "5_4.h"
#include "5_6.h"
#include "5_9.h"
#include "5_10.h"

using namespace std;

//5.10
void P_matrix(double **P, int N, int row1, int row2){ //row1 = k, ,row2 = n
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            if( (i==j && j != row1 && i != row1 && j != row2 && i != row2) || (i == row1 && j == row2) || (j == row1 && k == row2){
                    P[i,j] = 1;
            }else{  P[i,j] = 0;}
        }
    }
};

void guassian_elimination(double **A, double *b, double *u, int n){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            if( (i==j && j != row1 && i != row1 && j != row2 && i != row2) || (i == row1 && j == row2) || (j == row1 && k == row2){
                    P[i,j] = 1;
            }else{  P[i,j] = 0;}
        }
    }

};

// 5.9
void solve3by3(double **A, double *b, double *u){
    double M_i0;
    int n = 3;
    double A_ij;
    double b_i;

    for(int k = 1; k < n; k++){
        for(int i = k; i < n; i++){

            M_i0 = A[i][k-1]/A[k-1][k-1];
//            cout << "M_i0: " << M_i0 << endl;

            for(int j = k-1; j < n; j++){
                A[i][j] = A[i][j] - M_i0 * A[k-1][j];
//                cout << "A_" << i << "," << j << ": " << A[i][j] << endl;
                //A[i][j] = A_ij;
            }
            b[i] = b[i]-M_i0*b[k-1];
            //cout << "b_" << i << ": " << b[i] << endl;
        }
    }
    // Valgrind checks for memory leaks

    double c;
    int k;

    for(int a = 0; a < n; a++){
  //      cout << "hello there mate " << endl;
        k = n-1-a;
        //cout << "k: " << k << endl;
        c = 0;
        for(int i = k; i<n-1; i++){
            c += A[k][i+1]*u[i+1];
   //         cout << "k: " << k << endl;
   //         cout << "i+1 " << i+1 << endl;
        }

        u[k] = (1/A[k][k])*(b[k]-c);
//        cout << "b[k]: " << b[k] << " | c: " << c << endl;
//        cout << "u[k]: " << u[k] << " | k: " << k << endl;
    }
};
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
            //cout << res_ij << " " << res[i][j] << endl;
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

        //cout << "res_i" << " " << res[i] << endl;
    }

};

void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows){
    double res_i;

    assert(ACols == BRows);

    for(int i = 0; i < ACols; i++){

        res_i  = 0;

        for(int k = 0; k < BRows; k++){
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


// 5.4
double calc_mean ( double a[] , int length ){
    double sum = 0;

    for(int i = 0; i<length; i++){
            sum += a[i];
    }
    return sum/length;
} ;

double calc_std ( double a[], int length ){
    double sum2 = 0;
    double mean = calc_mean(a, length);

    for(int i = 0; i<length; i++){
            sum2 += (a[i] - mean)*(a[i] - mean);
    }

    return sqrt(sum2/(length-1));
} ;

// 5.3
void swap_pointer ( double *a, double *b ){

    cout << " a: " << *a <<  "\n b: " << *b << endl;

    double c = *a;
    double d = *b;

    *a = d;
    *b = c;
}

void swap_ref(double &a, double &b){

    cout << " a: " << a <<  "\n b: " << b << endl;

    double c = a;
    double d = b;

    a = d;
    b = c;

};

// 3.3
void implicit_Euler(int n){

    cout.precision(5);
    cout << fixed;
    double h = 1.0/(double)n;
    cout << "h: " << h << endl;

    double x[n];
    double x0 = 0.;
    x[0] = x0;

    double y[n];
    double y0 = 1.;
    y[0] = y0;

    cout << x0 << " , " << y0 << "\n" << endl;

    ofstream outputfile("outputfile.dat");

    outputfile << setprecision(5) << fixed << x[0] << "," << y[0] << endl;


    for(int i=1; i<n; i++){
        x[i] = h*i;
        y[i] = y[i-1]/(1+h);
        cout << x[i] << "," << y[i] << "\n" << endl;
        outputfile << setprecision(5) << fixed << x[i] << "," << y[i] << endl;

    }
    outputfile.close();
}
