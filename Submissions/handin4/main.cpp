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

    for(int rowX = 0; rowX < nRowsX; rowX++)
    {   
        // calc vector between point and other point
        rowdX = dataXtest.row(rowTest) - dataX.row(rowX);

        distance = norm(rowdX);
        
        // Create vector with relevant info of the point close to it (distance, label, index)
        distLabels.distance = distance; 
        distLabels.label = (double) labelsY(rowX,0);
        distLabels.index = (double) rowX;
        
        allVec.push_back(distLabels);

        
    }

}

int calcLabel(std::vector<int> &top5labels){
    // calc label (sum top 5 of allvec)
    //std::cout << "\n" << std::endl;
    int guess = 0;
    
    for(auto x : top5labels)
    {
        //std::cout << "label: " << x << std::endl;
        guess += x;
    }
    
    //std::cout << "guess" << guess << std::endl;
    
    return guess;

}

void giveLabels( std::vector<distLabel> &allVec, std::vector<int> &guessLabels){

    // sort vector of vectors:
    //std::cout << "\n" << std::endl;
    //std::cout << "allVec[x]: " <<  allVec[0].distance << " , " << allVec[0].index << std::endl;
    
    std::vector<int> top5labels;
    std::vector<int> top5Indices;

    //std::sort(allVec.begin(), allVec.end(), [](const distLabel& a, const distLabel& b){ return a.distance < b.distance; } );
    
    // Sort labels
    double minDist = 10000; 
    int label, index;
    bool c = false;

    for (int i = 0; i < 5; i++)
    {
        //std::cout << "\n" << "round: "<< i+1 << std::endl;
        for(auto x : allVec){
            //std::cout << "allVec[x]: " << x.distance << ", " << x.label << ", " << x.index << std::endl;
            for(auto y : top5Indices){
                //std::cout << "top5Indices y: " << y << std::endl;
                if (i==1){
                    //std::cout << "\nx.index, y: "  << x.index << ", " << y << std::endl;
                    //std::cout << "x.index == y: " << (x.index == y) << std::endl;
                }
                
                
                if(x.index == y){
                    c = true;
                    //std::cout << "allVec[x]: " << x.distance << ", " << x.label << ", " << x.index << std::endl;
                }
            }
            //std::cout << "leaving: for(auto y : top5Indices)" << std::endl;
            if(c){
                c = false; 
                continue;
            }
           
            //std::cout << "allVec[x].distance < minDist: " << x.distance << " < " << minDist << " | x.index: " << x.index << std::endl;
           
            if (x.distance < minDist){
                minDist = x.distance; 
                //std::cout << "miniDist: " << minDist << ", " << x.index << ", " << x.label << std::endl;
                
                label = x.label;
                index = x.index;
            }
            
        }
        //std::cout << "leaving: for(auto x : allVec)" << std::endl;
        top5labels.push_back(label);
        top5Indices.push_back(index);
    }
    
    
    //std::cout << "allVec[x]: " <<  allVec[0].distance << " , " << allVec[0].index << std::endl;
    
    // calc label (sum top 5 labels of allvec)
    int guess = calcLabel(top5labels);
    guessLabels.push_back(guess/std::abs(guess)); // Set labels

}

void testForCorrectness( arma::mat labelsY, std::vector<int> guessLabels, int nRowsXtest){
    
    int correct = 0;

    for (int i = 0; i < nRowsXtest; i++)
    {
        correct += labelsY(i,0)==guessLabels[i];
    
        std::cout << "guess: " << guessLabels[i] << " , " <<  labelsY(i,0) << " label" << " (" << i + 1 << ")" << std::endl;
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
        
        //std::cout << "allVec.size" << allVec.size() << std::endl;
        allVec.clear(); // reset allVec to reuse it 
    
    }

    // Print correct number out of 200
    testForCorrectness( labelsY, guessLabels, nRowsXtest ); 
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
