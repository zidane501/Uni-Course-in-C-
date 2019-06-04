#include "armadillo.hpp"
#include <iostream>


//using namespace arma;

int main(int argc, char const *argv[])
{
    arma::mat A = arma::randu<arma::mat>(4,5);
    arma::mat B = arma::randu<arma::mat>(4,5);
  
    std::cout << A*B.t() << std::endl;

    return 0;
}
