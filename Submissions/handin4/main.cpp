#include "ReadFile.hpp"

#include "armadillo.hpp"

#include <iostream>
#include <vector>
#include <string>
//using namespace arma;

void test_ReadFile(){
    ReadFile Read;
    
    arma::mat dataX(200,34);

    

    for (int k = 30; k < 100; k++)
    {
        std::cout << "dataX[ " << 199 << ", " << k << "]: " << dataX[199,k] << std::endl;
    }   
    
}

int main(int argc, char const *argv[])
{
    arma::mat A = arma::randu<arma::mat>(4,5);
    arma::mat B = arma::randu<arma::mat>(4,5);
  
    //std::cout << A*B.t() << std::endl;

    test_ReadFile();
    return 0;
}
