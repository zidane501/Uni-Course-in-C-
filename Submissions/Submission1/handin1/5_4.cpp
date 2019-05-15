// #include <iostream>
// #include <cassert>
#include <cmath>
// #include <vector>
// #include <iomanip>
// #include <fstream>
// #include "2_6.h"
// #include "3_3.h"
#include "5_4.h"
// #include "5_6.h"
// #include "5_9.h"
// #include "5_10.h"


// 5.4
double calc_mean ( double a[] , int length ){
    double sum = 0;

    for(int i = 0; i<length; i++){
            sum += a[i];
    }
    return sum/length;
} ;

double calc_std ( double a[], int length ){
    double sum2 = 0;
    double mean = calc_mean(a, length);

    for(int i = 0; i<length; i++){
            sum2 += (a[i] - mean)*(a[i] - mean);
    }
    if(length==1){return sqrt(sum2/(length));}
    return sqrt(sum2/(length-1));
} ;
