#include "ReadFile.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include "armadillo.hpp"

ReadFile::ReadFile(){};
ReadFile::~ReadFile(){};

void ReadFile::fillMatrix( arma::mat &mat, std::string fileName){
	std::vector<std::string> lines;

    getFileContent(fileName, lines);

    std::vector<std::string> values;
    
    int i = 0;
    int j = 0;    

    for(auto x : lines)
    {
        //std::cout << "x: " << x << std::endl;
        
        j = 0;

        split1(x, values);
        
        for(auto rowString : values)
        {
            //std::cout << "rowString: " << rowString << std::endl;
            //std::cout << "i,j: [" << i << ", " << j << "]" << std::endl;

            double rowDouble = std::stod(rowString);
            
            if((i>198) && (j>30) && (j<50) ){
                std::cout << "rowDouble: " << rowDouble << " |i,j: [" << i << ", " << j << "]" << std::endl;
            }

            mat[i,j] = rowDouble;

            j++;
        }
        
        i++;
    }    
}

void ReadFile::split1(const std::string& str, std::vector<std::string>& cont)
{	
	cont.clear();
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         std::back_inserter(cont));
}


bool ReadFile::getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs)
{
 
	// Open the File
	std::ifstream in(fileName.c_str());
 
	// Check if object is valid
	if(!in)
	{
		std::cerr << "Cannot open the File : "<<fileName<<std::endl;
		return false;
	}
 
	std::string str;
	// Read the next line from File untill it reaches the end.
	while (std::getline(in, str))
	{
		// Line contains string of length > 0 then save it in vector
		if(str.size() > 0)
			vecOfStrs.push_back(str);
	}
	//Close The File
	in.close();
	return true;
}