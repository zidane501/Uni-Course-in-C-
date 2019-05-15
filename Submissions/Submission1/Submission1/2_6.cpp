#include <iostream>
#include "2_6.h"
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

void printFunction(double x, int i){
    cout << std::fixed << endl;
    cout << std::setprecision(25);
    cout << "x" << i << " = " << x << "\n";
}

double f(double x){
 double res = exp(x)+pow(x,3)-5;
 return res;
}

double f_diff(double x){
    double res = exp(x) + 3*pow(x,2);
    return res;
}


double newton_Raphson (double initialGuess, double epsilon)
{
    vector<double> x_vals;

    // cout << 1 << endl;

    double x_prev = initialGuess;
    // cout << 2 << endl;

    for(int i=0; i<100; i++){

        double x_next = x_prev-f(x_prev)/f_diff(x_prev);

        printFunction(x_next, i);
        // cout << 3 << endl;
        // stop mechanism

        double stop;
        double abs_val=100.0;

        if(i>0){
            abs_val = x_vals.back()-x_next;
        }

        stop = abs(abs_val);
        // cout <<  4 << endl;
        if(stop<epsilon){
            // cout << 5 << endl;
            cout << "Stop: " << x_next << " " << x_vals.back() << endl;
            return x_next;
            break;
        }

        x_prev = x_next;
        x_vals.push_back(x_next);
        // cout << 47 << endl;

    }
    // cout << 50 << endl;
}

