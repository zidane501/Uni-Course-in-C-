
#include "ComplexNumber.hpp"


void assignment6_1(){

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
}

int main(int argc, char * argv[])
{
    assignment6_1();

return 0;
}