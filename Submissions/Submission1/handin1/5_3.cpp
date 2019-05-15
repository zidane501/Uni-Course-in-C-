// #include <iostream>
// #include <cassert>
// #include <math.h>
// #include <vector>
// #include <iomanip>
// #include <fstream>
// #include "2_6.h"
// #include "3_3.h"
#include "5_3.h"
// #include "5_6.h"
// #include "5_9.h"
// #include "5_10.h"

// using namespace std;


// 5.3
void swap_pointer ( double *a, double *b ){

    // cout << " a: " << *a <<  "\n b: " << *b << endl;

    double c = *a;
    double d = *b;

    *a = d;
    *b = c;
}

void swap_ref(double &a, double &b){

    // cout << " a: " << a <<  "\n b: " << b << endl;

    double c = a;
    double d = b;

    a = d;
    b = c;

};
