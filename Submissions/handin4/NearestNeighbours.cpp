#include "ReadFile.hpp"

#include "armadillo.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

/*
ReadMe:
Call NearestNeighbourMain()
*/
////////////////////////////////////////////////////////////////////////////////////////////

struct distLabel{ 
    double distance, label, index;
};

////////////////////////////////////////////////////////////////////////////////////////////

void nearestNeighbour(arma::mat& dataX, arma::mat& dataXtest, arma::mat& labelsY, 
                        distLabel distLabels, std::vector<distLabel> &allVec, int rowTest){
    
    double distance;
    arma::rowvec rowdX(dataXtest.n_cols);
    

    for(int rowX = 0; rowX < dataX.n_rows; rowX++)
    {   
        // calc vector between point and other point
        rowdX = dataXtest.row(rowTest) - dataX.row(rowX);

        distance = norm(rowdX);

        // Create vector with relevant info of the point close to it (distance, label, index)

        distLabels.distance = distance; 
        distLabels.label = (double) labelsY[rowX];
        distLabels.index = (double) rowX;
        
        allVec.push_back(distLabels);
    }

}

////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////

void giveLabels( std::vector<distLabel> &allVec, std::vector<int> &guessLabels, arma::mat labelsY){

    std::vector<int> top5labels;
    std::vector<int> top5Indices;
    std::vector<double> top5Dist;

    std::cout << "\ngivelabels()" << std::endl;
    // Sort labels
    double minDist = 100000000; 
    int label, index;
    bool c = false;

    for (int i = 0; i < 5; i++)
    {
        for(auto x : allVec){
            for(auto y : top5Indices){ 
                if (x.index == y)
                {
                    c = true;
                }
                  
            }

            if(c){
                c = false;
                //std::cout << "continue" << std::endl;
                continue;
            }

/*
            if (x.distance == 0.0)
            {
                continue;
            }
*/

            if (x.distance < minDist){
                minDist = x.distance;
                //std::cout << "minDist: " << minDist << " x.index: " << x.index << std::endl;                 
                label = x.label;
                index = x.index;
            }
            
        }
        std::cout << "minDist: " << minDist << " x.index: " << index << std::endl; 
        top5labels.push_back(label);
        top5Indices.push_back(index);
        top5Dist.push_back(minDist);

        minDist = 100000000;
        
    }
    //std::sort(allVec.begin(), allVec.end(), [](const distLabel& a, const distLabel& b){ 
    //If you want to sort in ascending order, then substitute > with <
    //return a.distance < b.distance; 
    //}); 
    
    std::cout << "allvec[0]" << allVec[0].distance << ", " << top5Dist[0] << " allvec.index[0]" << allVec[0].index << ", " << top5Indices[0] << std::endl;
    std::cout << "top5label: " << top5labels[0] << ", " << top5labels[1] << ", " << top5labels[2] << ", " << top5labels[3] << ", " << top5labels[4] << std::endl;
    std::cout << "top5Y    : " << labelsY[top5Indices[0]] << ", " << labelsY[top5Indices[1]] << ", " << labelsY[top5Indices[2]] << ", " 
              << labelsY[top5Indices[3]] << ", " << labelsY[top5Indices[4]] << std::endl;

    std::cout << "top5Indicies: " << top5Indices[0] << ", " << top5Indices[1] << ", " << top5Indices[2] << ", " << top5Indices[3] << ", " << top5Indices[4] << std::endl;
    std::cout << "top5Dist: " << top5Dist[0] << ", " << top5Dist[1] << ", " << top5Dist[2] << ", " << top5Dist[3] << ", " << top5Dist[4] << std::endl;
    
    int guess = calcLabel(top5labels);
    guessLabels.push_back(guess/std::abs(guess)); // Set labels

}

////////////////////////////////////////////////////////////////////////////////////////////

void testForCorrectness( arma::mat labelsY, std::vector<int> guessLabels){
    
    arma::colvec logRegLabels;
    logRegLabels.load("LogReg.dat");

    int correct = 0;

    for (int i = 0; i < logRegLabels.n_elem; i++)
    //for (int i = 0; i < labelsY.n_elem; i++)    
    {
        correct += logRegLabels[i]==guessLabels[i];
        //correct += labelsY[i]==guessLabels[i];
    
        std::cout << "guess: " << guessLabels[i] << " , " << logRegLabels(i) << " label" << " (" << i + 1 << ")" 
                  << " " << (logRegLabels(i)==guessLabels[i]? "True":"False") << std::endl;
        //std::cout << "guess: " << guessLabels[i] << " , " << labelsY[i] << " label" << " (" << i + 1 << ")" 
        //<< " " << (labelsY[i]==guessLabels[i]? "True":"False") << std::endl;
    }

    std::cout << "correct: " << correct << " %: " << 100.0*correct/logRegLabels.n_elem << " Nfalse: " << logRegLabels.n_elem-correct << std::endl;
    //std::cout << "correct: " << correct << " %: " << 100.0*correct/labelsY.n_elem << " Nfalse: " << labelsY.n_elem-correct << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////

void nearestNeighbourMain(){

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

    for (int rowTest = 0; rowTest < dataXtest.n_rows; rowTest++)
    //for (int rowTest = 0; rowTest < dataX.n_rows; rowTest++)
    {
        
        nearestNeighbour( dataX, dataXtest, labelsY, distLabels, allVec, rowTest );
        //nearestNeighbour( dataX, dataX, labelsY, distLabels, allVec, rowTest );
        giveLabels( allVec, guessLabels, labelsY );
        
        //std::cout << "allVec.size" << allVec.size() << std::endl;
        allVec.clear(); // reset allVec to reuse it 
    
    }

    // Print correct number out of 200
    testForCorrectness( labelsY, guessLabels); 
    Read.writeToFile(guessLabels, "NN.dat");
/*
    for (size_t i = 0; i < nRowsX; i++){

        //std::cout << "labelsY[" << i << "]: " << labelsY[i] << " | guessLabels[" << i << "]: " << guessLabels[i] << std::endl;
    }
*/
}