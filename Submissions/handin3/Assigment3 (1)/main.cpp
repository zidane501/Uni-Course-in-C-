#include "Matrix.hpp"
#include "Vector.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
    Matrix m(3,3); 

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "m_ij " <<  m(i,j) << std::endl;
        }
        
    }
    
    return 0;
}
