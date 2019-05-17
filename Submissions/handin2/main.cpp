
#include "ComplexNumber.hpp"


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

int main(int argc, char * argv[])
{
    //assignment_6_1_1();
    //assignment_6_1_2();
    //assignment_6_1_3();
    //assignment_6_1_4();
    //assignment_6_1_5();
    //assignment_6_1_6();



return 0;
}