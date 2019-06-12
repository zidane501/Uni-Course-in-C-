#ifndef READFILE_HPP
#define READFILE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "armadillo.hpp"


class ReadFile{
private:
    /* data */
public:
    ReadFile();
    
    void split1(const std::string& str, std::vector<std::string> & cont);

    bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs);
    
    void fillMatrix(arma::mat &mat, std::string filename);

    void writeToFile(std::vector<int>& guesses, std::string name);

    ~ReadFile();
};


#endif