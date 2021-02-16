//
//  funcs.cpp
//  duopy
//
//  Created by Benjamin Tenmann on 31/01/2021.
//

#include <math.h>
#include "funcs.hpp"
#include "duals.hpp"

using namespace DU;

unsigned long long factorial(int n){
    // factorial of an integer
    if (n == 0){
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

Dual power(Dual A, int n){
    // dual number raised to the power n
    if (n == 1){
        return A * 1;
    }
    else {
        return A * power(A, n-1);
    }
}

Dual exp(Dual A, int n){
    // exponential function applied on dual number
    // n is the depth of the estimation
    if (n == 1){
        return 1 + (power(A, n) / factorial(n));
    }
    
    else {
        return exp(A, n-1) + (power(A, n) / factorial(n));
    }
}

Dual ln(Dual A, int n){
    // the natural log of a dual number
    // only works on x <= 1
    if (n == 1){
        return A  - 1;
    }
    else {
        return ln(A, n-1) + (pow(-1, n-1) * ((power(A - 1, n)) / n));
    }
}

Dual tanh(Dual A, int n){
    // hyper-tangent of a dual number
    Dual C = (exp(2 * A, n) - 1) / (exp(2 * A, n) + 1);
    return C;
}
