
#include "ComplexNumber.hpp"
#include "CalculateExponential.hpp"
#include "Matrix2x2.hpp"

#include <string>

void assignment_6_1_1(){

/*
    ComplexNumber z1(4.0, 3.0);
    std::cout << "z1 = " << z1 << "\n"<< std::endl;
    std::cout << "Modulus z1 = " << z1.CalculateModulus() << "\n"<< std::endl;
    std::cout << "Argument z1 = " << z1.CalculateArgument() << "\n"<< std::endl;

    ComplexNumber z2;

    z2 = z1.CalculatePower(3);

    std::cout << "z2 = z1*z1*z1 = " << z2 << "\n" << std::endl;

    ComplexNumber z3;
    z3 = -z2;

    std::cout << "z3 = -z2 = " << z3 << "\n"<< std::endl;

    ComplexNumber z4;
    z4 = z1 + z2;
    std::cout << "z1 + z2 = " << z4 << "\n"<< std::endl;

    ComplexNumber zs[2];
    zs[0] = z1;
    zs[1] = z2;

    std::cout << "Second element of zs = " << zs[1] << "\n"<< std::endl;
*/
    ComplexNumber z1(4.0, 3.0);
    std::cout << "Real = " << z1.GetRealPart() << "\n"<< std::endl;
    std::cout << "Im   = " << z1.GetImaginaryPart() << "\n"<< std::endl;

}

void assignment_6_1_2(){
    /*Friend functions RealPart and ImaginaryPart so one may either write
    z.GetImaginaryPart() or ImaginaryPart(z).*/

    std::cout << "Problem 6.1.2" << std::endl;

    ComplexNumber z1(4.0, 3.0);
    std::cout << "Real = " << RealPart(z1) << std::endl;
    std::cout << "Im   = " << ImaginaryPart(z1) << std::endl;
}

void assignment_6_1_3(){
    /*An overridden copy constructor*/
}

void assignment_6_1_4(){
    /*A constructor that allows us to specify a real number in complex form through
    a constructor that accepts one double precision floating point variable as input,
    sets the real part of the complex number to the input variable, and the imaginary
    part to zero*/
    std::cout << "Problem 6.1.4" << std::endl;
    double re = 4;
    ComplexNumber z1(re);
    std::cout << "Real = " << z1.GetRealPart() << std::endl;
    std::cout << "Im   = " << z1.GetImaginaryPart() << std::endl;
}

void assignment_6_1_5(){
    /*A const method CalculateConjugate which returns the complex conju-
    gate x - iy of a complex number x + iy.*/
    std::cout << "Problem 6.1.5" << std::endl;

    ComplexNumber z1(5.0, 2.0);
    ComplexNumber z2 = z1.CalculateConjugate();

    std::cout << "Real = " << z2.GetRealPart() << std::endl;
    std::cout << "Im   = " << z2.GetImaginaryPart() << std::endl;
}

void assignment_6_1_6(){
    /*A method SetToConjugate which has a void return type and sets the complex
    number x + iy to its complex conjugate x - iy.*/
    std::cout << "Problem 6.1.6" << std::endl;

    ComplexNumber z1(5.0, 2.0);
    z1.SetConjugate();

    std::cout << "Real = " << z1.GetRealPart() << std::endl;
    std::cout << "Im   = " << z1.GetImaginaryPart() << std::endl;
}

void assignment_6_1_6_extra(){
    ComplexNumber z(1,2), w(2,-1), v;
    v = z*w;
    std::cout << "v Real = " << v.GetRealPart() << std::endl;
    std::cout << "v Im   = " << v.GetImaginaryPart() << std::endl;
}
void assignment_6_1_7(){
    
    ////////////
    // Creation
    int n = 3;
    ComplexNumber** A = new ComplexNumber* [n];
    ComplexNumber** res = new ComplexNumber* [n];
    for (int i=0; i<n; i++){
        A[i] = new ComplexNumber[n]; // used to calc A^n
        res[i] = new ComplexNumber[n];
    }
    
    ////////////
    ////////////

    // Create test matrix A and set res = 0:
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i==j){
                A[i][j] = ComplexNumber((double)4, (double)-j);
            }else{
                A[i][j] = ComplexNumber((double)9, (double)11+j);
            }
            //res[i][j] = ComplexNumber((double)0, (double)0);
        }   
    }
    
    double m = 3;
    //calcPowMatrix(A,m,res);
    
    std::cout << "\nFactorial "<< m << ": " << factorial(m) << std::endl;

    CalculateExponential(A, 80, res);
    std::cout << "\nResult in Main(): Calculate exponential of A. Res:" << ":" << std::endl;
    std::cout << res[0][0] << " " << res[0][1] << " " << res[0][2] << std::endl;
    std::cout << res[1][0] << " " << res[1][1] << " " << res[1][2] << std::endl;
    std::cout << res[2][0] << " " << res[2][1] << " " << res[2][2] << std::endl;
    
    // Deletion
    for (int i=0; i<n; i++)
    {
        delete[] A[i];
        delete[] res[i];
    }

    delete[] A;
    delete[] res;
}   

void assignment_6_2(){

    Matrix2x2 m(1,2,3,4);
    
    std::cout << "m : " << std::endl;
    m.Print();
    std::cout << "Determinant m = " << m.CalcDeterminant() << "\n"<< std::endl;
    
    Matrix2x2 inv = m.CalcInverse();
    std::cout << "inverse m : " << std::endl;
    inv.Print();

    Matrix2x2 m1;
    m1 = m;
    std::cout << "m1 = m: " << std::endl;
    m1.Print();

    Matrix2x2 m2;
    m2 = -m;
    std::cout << "m2 = -m: " << std::endl;
    m2.Print();

    Matrix2x2 m3;
    m3 = m + m;
    std::cout << "m + m = " << std::endl;
    m3.Print();    

    Matrix2x2 m4;
    m4 = m3 - m2;
    std::cout << "m3 - m2 = " << std::endl;
    m4.Print();    


}

void assignment_7_1(){
    
}
int main(int argc, char * argv[])
{   
    //Assignment 6.1-6:
        //assignment_6_1_1();
        //assignment_6_1_2();
        //assignment_6_1_3();
        //assignment_6_1_4();
        //assignment_6_1_5();
        //assignment_6_1_6();
        //assignment_6_1_6_extra();
    
    //Assignment 6.1.7:
        assignment_6_1_7();
    
    //Assignment 6.2:
        //assignment_6_2();
        
return 0;
}