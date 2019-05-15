#include "3_3.h"
#include <fstream>
#include <iostream>
#include <iomanip>

// 3.3
void implicit_Euler(int n){

    // cout.precision(5);
    // cout << fixed;
    double h = 1.0/(double)n;
    // cout << "h: " << h << endl;

    double x[n];
    double x0 = 0.;
    x[0] = x0;

    double y[n];
    double y0 = 1.;
    y[0] = y0;

    // cout << x0 << " , " << y0 << "\n" << endl;

    std::ofstream outputfile("xy.dat");

    outputfile << std::setprecision(5) << std::fixed << x[0] << "," << y[0] << std::endl;


    for(int i=1; i<n; i++){
        x[i] = h*i;
        y[i] = y[i-1]/(1+h);
        // cout << x[i] << "," << y[i] << "\n" << endl;
        outputfile << std::setprecision(5) << std::fixed << x[i] << "," << y[i] << std::endl;

    }
    outputfile.close();
}