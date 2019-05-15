#include <iostream>
#include "2_6.h"
#include "3_3.h"
#include "5_3.h"
#include "5_4.h"
#include "5_6.h"
#include "5_9.h"
#include "5_10.h"

using namespace std;

int main()
{
//////////////////////////////////////////////////////////////////////////

    //newton_Raphson(0.0, 0.0000000000000000001);           // 2.6

//////////////////////////////////////////////////////////////////////////

    //implicit_Euler(1000);                                 // 3.3

    /*
    double x = 1;
    double y = 2;

    double* a = &x;
    double* b = &y;

    swap_pointer(a, b);                //5.3

    cout << " x: " << x <<  "\n y: " << y << endl;

    swap_ref(x, y);

    cout << " x: " << x <<  "\n y: " << y << endl;
    */
//////////////////////////////////////////////////////////////////////////
    //5.4
    /*double a[] = {1,2,3,4,5,6,7,8,9};
    double mean = calc_mean( a , 9 );
    double stddev = calc_std( a , 9 );

    cout << "mean: " << mean << endl;
    cout << "\nstddev: " << stddev << endl;
    */
//////////////////////////////////////////////////////////////////////////
    //5.6


    int ARows = 3; int ACols = 3;
    int BRows = 3; int BCols = 2;
    int n = 2;

    double* u = new double [ACols];
    double* v = new double [ACols];

    double** A = new double* [ARows];
    double** B = new double* [BRows];
    double** res = new double* [BRows];

    for (int i=0; i<ARows; i++){
        A[i] = new double [ACols];
        B[i] = new double [BCols];
        res[i] = new double [BCols];
    }


    /*A[0][0] = 1; A[0][1] = 2; A[0][2] = -3;
    A[1][0] = 2; A[1][1] = -1; A[1][2] = 4;
    A[2][0] = 1;A[2][1] = -1; A[2][2] = 1;
    v[0] = 6; v[1] = 1; v[2] = 3;*/

    A[0][0] = 1; A[0][1] = 1; A[0][2] = 1;
    A[1][0] = 0; A[1][1] = 2; A[1][2] = 5;
    A[2][0] = 2; A[2][1] = 5; A[2][2] = -1;

    v[0] = 6; v[1] = -4; v[2] = 27;

    B[0][0] = 0; B[0][1] = 0; B[0][2] = 0;
    B[1][0] = 1; B[1][1] = 0; B[1][2] = 0;
    B[2][0] = 2; B[2][1] = 2; B[2][2] = 1;


    //cout << 1 << endl;

    // matrix multiplication
    //Multiply(res, A, B, ARows , ACols , BRows , BCols);

    /*for(int a = 0; a < ARows; a++){
        for(int b = 0; b < BCols; b++){
            cout << "res " << a << "," << b << " : " << res[a][b] << endl;
        }
    }*/

    // Vector*Matrix multiplication
    /*int uRows = 3;
    double* u = new double [uRows];
    double* v = new double [uRows];

    u[0] = 2; u[1] = 2; u[2] = 2;

    Multiply(v, B, u, BRows , BCols, uRows);
    cout << "v " << 0 << " : " << v[0] << endl;
    cout << "v " << 1 << " : " << v[1] << endl;*/

    // Vector*Matrix multiplication
    /*int uRows = 2;
    double* u = new double [uRows];
    double* v = new double [BCols];

    u[0] = 2; u[1] = 2;

    Multiply(v, B, u, BRows , BCols, uRows);
    cout << "v " << 0 << " : " << v[0] << endl;
    cout << "v " << 1 << " : " << v[1] << endl;
    cout << "v " << 2 << " : " << v[2] << endl;*/

    // Scalar*Matrix multiplication
    /*double scalar = 3;

    Multiply(res, B, scalar, BRows, BCols);

    for(int a = 0; a < BRows; a++){
        for(int b = 0; b < BCols; b++){
            cout << "res " << a << "," << b << " : " << res[a][b] << endl;
        }
    }
    // Deletion:
    for (int i=0; i<ARows; i++)
    {
        delete[] A[i];
        delete[] res[i];
    }
    for (int i=0; i<BRows; i++){delete[] B[i];}

    delete[] A;
    delete[] B;
    delete[] res;


    delete[] u;
    delete[] v;*/
//////////////////////////////////////////////////////////////////////////
    // 5.9
    /*solve3by3(A, v, u); // v = b; A*u = b; x1=17/15(1.133);x2=-7/5(1.4);x3=-9/5(1.8);

    cout << "u " << 0 << " : " << u[0] << " " << "17/15" << endl;
    cout << "u " << 1 << " : " << u[1] << " " <<  "-7/5" << endl;
    cout << "u " << 2 << " : " << u[2] << " " <<  "-9/5" << endl;

    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 3; b++){
            cout << "A " << a << "," << b << " : " << A[a][b] << endl;
        }
    }*/
//////////////////////////////////////////////////////////////////
    // 5.10
    int N = 3;
    P_matrix(B, N, 0, 2);
    for (int i=0; i<N; i++){
        for (int j=0; i<N; i++){
            cout << "P_" << i << "," << j << ": " << A[i][j] << endl;
        }
    }

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
    // Deletion:
    for (int i=0; i<ARows; i++)
    {
        delete[] A[i];
        delete[] res[i];
    }
    for (int i=0; i<BRows; i++){delete[] B[i];}

    delete[] A;
    delete[] B;
    delete[] res;


    delete[] u;
    delete[] v;

    return 0;
}
