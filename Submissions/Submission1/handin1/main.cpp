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

/*
    int ARows = 3; int ACols = 3;
    int BRows = 3; int BCols = 2;
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
*/

/*
    A[0][0] = 1; A[0][1] = 2; A[0][2] = -3;
    A[1][0] = 2; A[1][1] = -1; A[1][2] = 4;
    A[2][0] = 1;A[2][1] = -1; A[2][2] = 1;
    v[0] = 6; v[1] = 1; v[2] = 3;
*/
    
    //v[0] = 1; v[1] = 2; v[2] = 3;

/*  
    A[0][0] = 1; A[0][1] = 1; A[0][2] = 1;
    A[1][0] = 0; A[1][1] = 2; A[1][2] = 5;
    A[2][0] = 2; A[2][1] = 5; A[2][2] = -1;
*/

    //v[0] = 6; v[1] = -4; v[2] = 27;

/*  B[0][0] = 1; B[0][1] = 1; B[0][2] = 1;
    B[1][0] = 2; B[1][1] = 2; B[1][2] = 2;
    B[2][0] = 3; B[2][1] = 3; B[2][2] = 3;
*/
    
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

/*  for(int a = 0; a < ARows; a++){
        for(int b = 0; b < BCols; b++){
            std::cout << "res " << a << "," << b << " : " << res[a][b] << std::endl;
        }
    }
*/

    // Vector*Matrix multiplication
/*  int uRows = 3;
    double* u = new double [uRows];
    double* v = new double [uRows];

    u[0] = 2; u[1] = 2; u[2] = 2;

    Multiply(v, B, u, BRows , BCols, uRows);
    std::cout << "v " << 0 << " : " << v[0] << std::endl;
    std::cout << "v " << 1 << " : " << v[1] << std::endl;
*/
   
    // Matrix*Vector multiplication
/*
    int uRows = 2;
    double* u = new double [BCols];
    double* v = new double [BRows];
*/
    /*B[0][0] = 5; B[0][1] = 1; B[0][2] = 1;
    B[1][0] = 2; B[1][1] = 2; B[1][2] = 2;
    B[2][0] = 3; B[2][1] = 3; B[2][2] = 2;*/
/*    
    B[0][0] = 5; B[0][1] = 1; 
    B[1][0] = 2; B[1][1] = 2; 
    B[2][0] = 3; B[2][1] = 3; 

    u[0] = 1; u[1] = 2; //u[2] = 3;

    Multiply(v, B, u, BRows , BCols, BCols);

    std::cout << "v " << 0 << " : " << v[0] << std::endl;
    std::cout << "v " << 1 << " : " << v[1] << std::endl;
    std::cout << "v " << 2 << " : " << v[2] << std::endl;
*/
/*
    // Scalar*Matrix multiplication
    double scalar = 3;

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
    delete[] v;
*/

//////////////////////////////////////////////////////////////////////////
    // 5.9
    int n = 4;
    double* u = new double [n];
    double* v = new double [n];
    double** A = new double* [n];
    

    for (int j=0; j<n; j++){
        A[j] = new double [n];
    }
/*
    A[0][0] = 1; A[0][1] = 2; A[0][2] = -3;
    A[1][0] = 2; A[1][1] = -1; A[1][2] = 4;
    A[2][0] = 1;A[2][1] = -1; A[2][2] = 1;
    v[0] = 6; v[1] = 1; v[2] = 3;
*/
    // v = b; A*u = b; 
    //x1 = 17/15 (1.133); x2 = -7/5 (1.4); x3 = -9/5 (1.8);

/*
    A[0][0] = 8;  A[0][1] = 1;  A[0][2] = -2;
    A[1][0] = 2;  A[1][1] = 8;  A[1][2] = 4;
    A[2][0] = 30; A[2][1] = 12; A[2][2] = -4;
    v[0] = 6; 
    v[1] = 12; 
    v[2] = 5;
    //v = b; A*u = b; 
    //u1=-2; u2 = 6; u3 = -3;
*/

     
    //solve3by3(A, v, u);
/*
    std::cout << A[0][0] << " " << A[0][1] << " " << A[0][2] << std::endl;
    std::cout << A[1][0] << " " << A[1][1] << " " << A[1][2] << std::endl;
    std::cout << A[2][0] << " " << A[2][1] << " " << A[2][2] << std::endl;

    std::cout << "u " << 0 << " : " << u[0] << " " << "17/15" << std::endl;
    std::cout << "u " << 1 << " : " << u[1] << " " <<  "-7/5" << std::endl;
    std::cout << "u " << 2 << " : " << u[2] << " " <<  "-9/5" << std::endl;
*/
/*    
    for (int i=0; i<3; i++)
    {
        delete[] A[i];

    }

    delete[] A;

    delete[] u; 
    delete[] v;
*/
//////////////////////////////////////////////////////////////////
    // 5.10
/*
    A[0][0] = 4;  A[0][1] = 2;  A[0][2] = -2; 
    A[1][0] = 2;  A[1][1] = 8;  A[1][2] = 4;
    A[2][0] = 30; A[2][1] = 12; A[2][2] = -4;
*/
    
    A[0][0] = 0;  A[0][1] =  1;  A[0][2] =  1; A[0][3] = -2; 
    A[1][0] = 1;  A[1][1] =  2;  A[1][2] = -1; A[1][3] =  0;
    A[2][0] = 2;  A[2][1] =  4;  A[2][2] =  1; A[2][3] = -3;
    A[3][0] = 1;  A[3][1] = -4;  A[3][2] = -7; A[3][3] = -1;

    v[0] =  -3; 
    v[1] =   2; 
    v[2] =  -2;
    v[3] = -19;
    // Sol: [x, y, z, t] =[-1, 2, 1, 3]
    // int N = 3;

/*
    A[0][0] = 1; A[0][1] = 2; A[0][2] = -3;
    A[1][0] = 2; A[1][1] = -1; A[1][2] = 4;
    A[2][0] = 1;A[2][1] = -1; A[2][2] = 1;
    v[0] = 6; v[1] = 1; v[2] = 3;
    // v = b; A*u = b; 
    //x1 = 17/15 (1.133); x2 = -7/5 (1.4); x3 = -9/5 (1.8);
*/
/*
    B[0][0] = 0; B[0][1] = 1; B[0][2] = 1;
    B[1][0] = 2; B[1][1] = 2; B[1][2] = 2;
    B[2][0] = 3; B[2][1] = 3; B[2][2] = 3;
*/
/*
    A[0][0] = 2;  A[0][1] =  -1;  A[0][2] =  3; A[0][3] =  4; 
    A[1][0] = 1;  A[1][1] =   0;  A[1][2] = -2; A[1][3] =  7;
    A[2][0] = 3;  A[2][1] =  -3;  A[2][2] =  1; A[2][3] =  5;
    A[3][0] = 2;  A[3][1] =   1;  A[3][2] =  4; A[3][3] =  4;

    v[0] =   9; 
    v[1] =  11; 
    v[2] =   8;
    v[3] =  10;
*/
    guassian_elimination(A, v, u, 4);
    
    std::cout << "A (main): " << std::endl;
    std::cout << A[0][0] << " " << A[0][1] << " " << A[0][2] << " " << A[0][3] << std::endl;
    std::cout << A[1][0] << " " << A[1][1] << " " << A[1][2] << " " << A[1][3] << std::endl;
    std::cout << A[2][0] << " " << A[2][1] << " " << A[2][2] << " " << A[2][3] << std::endl;
    std::cout << A[3][0] << " " << A[3][1] << " " << A[3][2] << " " << A[3][3] << std::endl;

    std::cout << "u " << 0 << " : " << u[0] << " " << ""  << std::endl;
    std::cout << "u " << 1 << " : " << u[1] << " " <<  "" << std::endl;
    std::cout << "u " << 2 << " : " << u[2] << " " <<  "" << std::endl;
    std::cout << "u " << 3 << " : " << u[3] << " " <<  "" << std::endl;
    
    for (int i=0; i<n; i++)
    {
        delete[] A[i];

    }

    delete[] A;

    delete[] u; 
    delete[] v;
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/*
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
*/
/////////////////////////////////////////////////////////////////////////////

    return 0;
}
