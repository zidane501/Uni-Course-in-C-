#include "ReadFile.hpp"

#include "armadillo.hpp"

#include <iostream>
#include <vector>
#include <string>
//using namespace arma;

void test_ReadFile(){

    int cols = 34;
    int nRowsX = 200;
    int nRowsXtest = 200; //151;
    int guess = 0;
    int correct = 0;
    int True = -1;

    double distance;

    std::vector<std::vector<double>> allVec;
    std::vector<double> distLabelVec;
    std::vector<int> guessLabels;
    ReadFile Read;
    
    arma::mat labelsY(nRowsX,1);
    arma::mat dataX(nRowsX,cols);
    arma::rowvec rowdX(cols);
    arma::mat dataXtest(nRowsXtest,cols);
    
    Read.fillMatrix(dataX, "dataX.dat");
    Read.fillMatrix(dataXtest, "dataX.dat");    
    Read.fillMatrix(labelsY, "dataY.dat");

    for (int rowTest = 0; rowTest < nRowsXtest; rowTest++)
    {
        for (int rowX = 0; rowX < nRowsX; rowX++)
        {   
            // calc vector between point and other point
            rowdX = dataXtest.row(rowTest) - dataX.row(rowX);

            distance = norm(rowdX);
            
            // Create vector with relevant info of the point close to it (distance, label, index)
            distLabelVec.push_back(distance); 
            distLabelVec.push_back(labelsY(rowTest,0));
            distLabelVec.push_back((double)rowTest);
            
            allVec.push_back(distLabelVec);

            distLabelVec.clear();
        }

        // sort vector of vectors:
        std::sort(allVec.begin(), allVec.end(), [](const std::vector<double>& a, const std::vector<double>& b){ return a[0] < b[0]; } );
        
        guess = 0;

        
        // calc label (sum top 5 of allvec)
        for (int i = 0; i < 5; i++){
            
            guess += allVec[i][1];
            
            if (rowTest<3){
                //std::cout << "allVec[" << i << "][1]" << allVec[i][1] << ", " << allVec[i][0] << std::endl;
            }
            
        }

        True = std::pow(-1, rowTest); // To test how many right results

        
        correct += labelsY(rowTest,0)==(guess/std::abs(guess)); // To test how many right results
        
        allVec.clear(); // reset allVec to reuse it 

        std::cout << "guess: " << guess/std::abs(guess) << ", " <<  labelsY(rowTest,0) << " (" << rowTest + 1 << ")" << std::endl;
        
        //
        
        guessLabels.push_back(guess/std::abs(guess)); // Set labels

    }

    std::cout << "correct: " << correct << std::endl; // Print correct number out of 200
    
    for (size_t i = 0; i < nRowsX; i++){

        //std::cout << "labelsY[" << i << "]: " << labelsY[i] << " | guessLabels[" << i << "]: " << guessLabels[i] << std::endl;
    }

}

int main(int argc, char const *argv[])
{   
    // test
    arma::mat A = arma::randu<arma::mat>(4,5);
    arma::mat B = arma::randu<arma::mat>(4,5);
  
    //std::cout << A*B.t() << std::endl;

    test_ReadFile();
    return 0;
}
