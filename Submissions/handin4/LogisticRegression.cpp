#include "armadillo.hpp"
#include "ReadFile.hpp"

double signF(double f){
    return (double)( f < 0 ? -1:+1 );
}

void logisticRegression(){
    int cols        = 34;
    int nRowsX      = 200;
    int nRowsXtest  = 151;
    int guess       = 0;

    double f, y, expF;
    double limitE = 1;
    

    ReadFile Read;
    
    arma::mat    labelsY(nRowsX,1);
    arma::mat    x(nRowsX,cols);
    arma::mat    xTest(nRowsXtest,cols);
    
    arma::mat    dLw(1, cols), wT(1, cols);
    
    std::vector<int> labels;

    wT.zeros();

    Read.fillMatrix(x, "dataX.dat");
    Read.fillMatrix(xTest, "dataXtest.dat");    
    Read.fillMatrix(labelsY, "dataY.dat");
    
    int j = 0;
    
    double alpha = 0.3;

    while (limitE>(1.0/10000000.0))
    {
        // Compute sum:
        for(int i = 0; i < nRowsX; i++)
        {   

            f = dot(wT, x.row(i));
            
            y = labelsY(i);
            
            expF = 1 + exp(y*f);
            
            dLw += y*(1.0/expF)*x.row(i);
            j++;
        }

        dLw = (-1.0/34.0)*dLw;
        limitE = norm(dLw);

        wT += -alpha*dLw;

        dLw.zeros();
        
    }
    
    std::cout << "number of loops, j: " << j/200.0 << " | Total: " << j << std::endl;

    for (int i = 0; i < 151; i++)
    {   
        f = dot(wT, xTest.row(i));
        y = signF(f);
        labels.push_back((int)y);

        //std::cout << y << std::endl;
    }    
    Read.writeToFile(labels, "LogReg.dat");
}
