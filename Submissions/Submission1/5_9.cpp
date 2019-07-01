// #include <iostream>
// #include <cassert>
// #include <math.h>
// #include <vector>
// #include <iomanip>
// #include <fstream>
// #include "2_6.h"
// #include "3_3.h"
// #include "5_4.h"
// #include "5_6.h"
#include "5_9.h"
// #include "5_10.h"

// using namespace std;

// 5.9
void solve3by3(double **A, double *b, double *u){
    double M_i0;
    int n = 3;
    double A_ij;
    double b_i;
    //A[0][0] = 0;

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
