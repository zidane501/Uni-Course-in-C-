#include "ReadFile.hpp"

#include "armadillo.hpp"

#include <iostream>
#include <vector>
#include <string>
//using namespace arma;

struct distLabel{ 
    double distance, label, index;
};

void nearestNeighbour(arma::mat& dataX, arma::mat& dataXtest, arma::mat& labelsY, 
                        distLabel distLabels, std::vector<distLabel> &allVec,
                        int rowTest, int nRowsX){
    
    
    int cols = 34;
    double distance;
    arma::rowvec rowdX(cols);

    for (int rowX = 0; rowX < nRowsX; rowX++)
    {   
        // calc vector between point and other point
        rowdX = dataXtest.row(rowTest) - dataX.row(rowX);

        distance = norm(rowdX);
        
        // Create vector with relevant info of the point close to it (distance, label, index)
        distLabels.distance = distance; 
        distLabels.label = (double) labelsY(rowTest,0);
        distLabels.index = (double)rowTest;
        
        allVec.push_back(distLabels);

        
    }
}

int calcLabel(std::vector<distLabel> &allVec, int guess){
    // calc label (sum top 5 of allvec)
    //std::cout << "\n" << std::endl;
    for (int i = 0; i < 5; i++){
        //std::cout << "allVec[i][1]: " << allVec[i][1] << " " << allVec[i][0] << std::endl;
        guess += allVec[i].label;
    }
    
    //std::cout << "guess" << guess << std::endl;
    
    return guess;

}

void giveLabels( std::vector<distLabel> &allVec, std::vector<int> &guessLabels){
    
    int guess = 0;

    // sort vector of vectors:
    std::cout << "\n" << std::endl;
    
    std::cout << "allVec[x]: " <<  allVec[0].distance << " , " << allVec[0].index << std::endl;
    

    std::sort(allVec.begin(), allVec.end(), [](const distLabel& a, const distLabel& b){ return a.distance < b.distance; } );
    
    std::cout << "allVec[x]: " <<  allVec[0].distance << " , " << allVec[0].index << std::endl;

    // calc label (sum top 5 labels of allvec)
    guess = calcLabel(allVec, guess);
    guessLabels.push_back(guess/std::abs(guess)); // Set labels

}

void testForCorrectness( arma::mat labelsY, std::vector<int> guessLabels){
    
    //int True = -1;
    
    //True = std::pow(-1, rowTest); 

    //guess = calcLabel(allVec, guess);
    int correct = 0;

    for (int i = 0; i < 151; i++)
    {
        correct += labelsY(i,0)==guessLabels[i];
    
        //std::cout << "guess: " << guessLabels[i] << " , " <<  labelsY(i,0) << " label" << " (" << i + 1 << ")" << std::endl;
    }

    std::cout << "correct: " << correct << std::endl;
    

}

void test_ReadFile(){

    int cols        = 34;
    int nRowsX      = 200;
    int nRowsXtest  = 151;
    int guess       = 0;
    int correct     = 0;

    std::vector<distLabel>  allVec;
    std::vector<double>     distLabelVec;
    std::vector<int>        guessLabels;
    
    ReadFile Read;

    distLabel distLabels;
    
    arma::mat    labelsY(nRowsX,1);
    arma::mat    dataX(nRowsX,cols);
    arma::mat    dataXtest(nRowsXtest,cols);
    arma::rowvec rowdX(cols);
    
    Read.fillMatrix(dataX, "dataX.dat");
    Read.fillMatrix(dataXtest, "dataXtest.dat");    
    Read.fillMatrix(labelsY, "dataY.dat");

    for (int rowTest = 0; rowTest < nRowsXtest; rowTest++)
    {
        
        nearestNeighbour( dataX, dataXtest, labelsY, distLabels, allVec, rowTest, nRowsX );
        
        giveLabels( allVec, guessLabels );
        
        allVec.clear(); // reset allVec to reuse it 
    
    }

    // Print correct number out of 200
    testForCorrectness( labelsY, guessLabels ); 
/*
    for (size_t i = 0; i < nRowsX; i++){

        //std::cout << "labelsY[" << i << "]: " << labelsY[i] << " | guessLabels[" << i << "]: " << guessLabels[i] << std::endl;
    }
*/
}

int main(int argc, char const *argv[])
{   

    test_ReadFile();
    
    return 0;
}
