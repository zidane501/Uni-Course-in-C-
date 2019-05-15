#include <iostream>
#include "2_6.h"
#include "3_3.h"
#include "5_3.h"
#include "5_4.h"
#include "5_6.h"
#include "5_9.h"
#include "5_10.h"

//using namespace std;

// HOW TO COMPILE:
//
// clang++ -std=c++11 main.cpp -o main 2_6.cpp 3_3.cpp 5_3.cpp 5_4.cpp 5_6.cpp 5_9.cpp 5_10.cpp

void test2_6()
{
    double initialGuess = 0.0, epsilon = 10e-6;
    double result = newton_Raphson(initialGuess, epsilon);
    std::cout << "Newton-Raphson(" << initialGuess << ", " << epsilon
              << ") = " << result << std::endl;
}

void test_5_4()
{
//5.4
    double a[] = {1,2,3,4,5,6,7,8,9};
    double mean = calc_mean( a , 9 );
    double stddev = calc_std( a , 9 );

    std::cout << "mean: " << mean << std::endl;
    std::cout << "\nstddev: " << stddev << std::endl;
    
}
    
/*void test_5_6(double *res, double **A, double *B, int ARows, int ACols, int BRows)
{
    Multiply(*res, **A, *B, ARows, ACols, BRows);
}
*/
//void generating_matrices_and_vectors(){
//}


int main()
{
    //test2_6();
    
    //test3_3();

    //test_5_4();
    //test_5_6();
    // ...


    //implicit_Euler(1000);                                 // 3.3

    /*
    double x = 1;
    double y = 2;

    double* a = &x;
    double* b = &y;

    swap_pointer(a, b);                //5.3

    std::cout << " x: " << x <<  "\n y: " << y << std::endl;

    swap_ref(x, y);

    std::cout << " x: " << x <<  "\n y: " << y << std::endl;
    */
//////////////////////////////////////////////////////////////////////////
    //5.4
    /*double a[] = {1,2,3,4,5,6,7,8,9};
    double mean = calc_mean( a , 9 );
    double stddev = calc_std( a , 9 );

    std::cout << "mean: " << mean << std::endl;
    std::cout << "\nstddev: " << stddev << std::endl;
    */
//////////////////////////////////////////////////////////////////////////
    //5.6


    int ARows = 3; int ACols = 3;
    int BRows = 3; int BCols = 3;
    int n = 3;

    //double* u = new double [ACols];
    //double* v = new double [ACols];

    double** A = new double* [ARows];
    double** B = new double* [BRows];
    double** res = new double* [BRows];

    for (int j=0; j<ARows; j++){
        A[j] = new double [ACols];
        B[j] = new double [BCols];
        res[j] = new double [ACols];
    }


    /*A[0][0] = 1; A[0][1] = 2; A[0][2] = -3;
    A[1][0] = 2; A[1][1] = -1; A[1][2] = 4;
    A[2][0] = 1;A[2][1] = -1; A[2][2] = 1;
    v[0] = 6; v[1] = 1; v[2] = 3;*/
    
    //v[0] = 1; v[1] = 2; v[2] = 3;

    /*A[0][0] = 1; A[0][1] = 1; A[0][2] = 1;
    A[1][0] = 0; A[1][1] = 2; A[1][2] = 5;
    A[2][0] = 2; A[2][1] = 5; A[2][2] = -1;*/

    //v[0] = 6; v[1] = -4; v[2] = 27;

    /*B[0][0] = 1; B[0][1] = 1; B[0][2] = 1;
    B[1][0] = 2; B[1][1] = 2; B[1][2] = 2;
    B[2][0] = 3; B[2][1] = 3; B[2][2] = 3;*/
    
    ////////////
    // Create and Delete Matrix recipe
    /*double** P = new double* [n];
    for (int i=0; i<n; i++){
        P[i] = new double [n];
    }
    // Deletion:
    for (int i=0; i<n; i++)
    {
        delete[] P[i];
    }
    delete[] A;*/

    //std::cout << 1 << std::endl;

    // matrix multiplication
    //Multiply(res, A, B, ARows , ACols , BRows , BCols);

    /*for(int a = 0; a < ARows; a++){
        for(int b = 0; b < BCols; b++){
            std::cout << "res " << a << "," << b << " : " << res[a][b] << std::endl;
        }
    }*/

    // Vector*Matrix multiplication
    /*int uRows = 3;
    double* u = new double [uRows];
    double* v = new double [uRows];

    u[0] = 2; u[1] = 2; u[2] = 2;

    Multiply(v, B, u, BRows , BCols, uRows);
    std::cout << "v " << 0 << " : " << v[0] << std::endl;
    std::cout << "v " << 1 << " : " << v[1] << std::endl;*/
   
    // Matrix*Vector multiplication
    int uRows = 2;
    double* u = new double [BCols];
    double* v = new double [BCols];

    B[0][0] = 5; B[0][1] = 1; B[0][2] = 1;
    B[1][0] = 2; B[1][1] = 2; B[1][2] = 2;
    B[2][0] = 3; B[2][1] = 3; B[2][2] = 2;
    
    u[0] = 1; u[1] = 2; u[2] = 3;

    Multiply(v, B, u, BRows , BCols, BRows);

    std::cout << "v " << 0 << " : " << v[0] << std::endl;
    std::cout << "v " << 1 << " : " << v[1] << std::endl;
    std::cout << "v " << 2 << " : " << v[2] << std::endl;

/*
    // Scalar*Matrix multiplication
    /*double scalar = 3;

    Multiply(res, B, scalar, BRows, BCols);

    for(int a = 0; a < BRows; a++){
        for(int b = 0; b < BCols; b++){
            std::cout << "res " << a << "," << b << " : " << res[a][b] << std::endl;
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

    std::cout << "u " << 0 << " : " << u[0] << " " << "17/15" << std::endl;
    std::cout << "u " << 1 << " : " << u[1] << " " <<  "-7/5" << std::endl;
    std::cout << "u " << 2 << " : " << u[2] << " " <<  "-9/5" << std::endl;

    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 3; b++){
            std::cout << "A " << a << "," << b << " : " << A[a][b] << std::endl;
        }
    }*/

//////////////////////////////////////////////////////////////////
    // 5.10
    
    // int N = 3;
  /*B[0][0] = 0; B[0][1] = 1; B[0][2] = 1;
    B[1][0] = 2; B[1][1] = 2; B[1][2] = 2;
    B[2][0] = 3; B[2][1] = 3; B[2][2] = 3;*/

    //guassian_elimination(B, v, u, 3);

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
    // Deletion:
    for (int i=0; i<ARows; i++)
    {
        delete[] A[i];
        delete[] B[i];
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
