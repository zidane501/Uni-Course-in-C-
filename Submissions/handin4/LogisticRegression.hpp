/*
#include "armadillo.hpp"
#include "ReadFile.hpp"

class LogisticRegression: ReadFile
{
private:
    arma::colvec y(double);
    arma::colvec wT = arma::zeros<arma::colvec>(34);
    arma::mat x;
    arma::mat f(double);

public:
    LogisticRegression(arma::mat x, arma::colvec y, arma::rowvec wT){

        y = y;
        x = x;
        wT = wT;

        fillMatrix(y, "dataY.dat");
        fillMatrix(x, "dataX.dat");
        
    };

    void f(int row, arma::mat f){
        f = wT*x.row(row);

    }
        
    ~LogisticRegression();
};

 */