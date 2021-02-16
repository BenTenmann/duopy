//
// Created by Benjamin Tenmann on 15/02/2021.
//

#include <math.h>
#include "duals.h"
#include "du_functions.h"

unsigned long long factorial(int n){
    if (n == 0){
        return 1;
    }else{
        return n * factorial(n - 1);
    }
}

struct Dual powerDual(struct Dual *A, int n) {
    double i = 1.0;
    struct Dual B = mulVal(A, &i);
    while (n > 1){
        B = mulDual(A, &B);
        n--;
    }
    return B;
}

struct Dual expDual(struct Dual *A, int n){
    double i, k;
    i = 1.0;
    struct Dual B, C;
    B = mulVal(A, &i);
    unsigned long long j;
    while (n > 1){
        C = powerDual(A, n);
        j = factorial(n);
        k = (double) j;
        C = divVal(&C, &k);
        B = addDual(&B, &C);
        n--;
    }
    return addVal(&B, &i);
}

struct Dual lnDual(struct Dual *A, int n) {
    // needs re-evaluation
    // currently returns NA
    double i, k;
    i = 1.0;
    struct Dual B = subVal(A, &i);
    struct Dual C;
    while (n > 1){
        C = powerDual(&B, n);
        C = divVal(&C, (double *) &n);
        k = pow(-1, (double) (n-1));
        C = mulVal(&C, &k);
        B = addDual(&B, &C);
        n--;
    }
    return B;
}

struct Dual sinhDual(struct Dual *A){
    // breaks down around x = -4;
    int n = 20;
    double b, c;
    b = 2.0;
    c = 1.0;
    struct Dual B, C, D;
    B = mulVal(A, &b);
    B = expDual(&B, n);
    B = subVal(&B, &c); // nominator
    C = expDual(A, n);
    C = mulVal(&C, &b); // denominator
    D = divDual(&B, &C);
    return D;
}

struct Dual coshDual(struct Dual *A){
    // relatively stable -- test more
    int n = 20;
    double b, c;
    b = 2.0;
    c = 1.0;
    struct Dual B, C, D;
    B = mulVal(A, &b);
    B = expDual(&B, n);
    B = addVal(&B, &c); // nominator
    C = expDual(A, n);
    C = mulVal(&C, &b); // denominator
    D = divDual(&B, &C);
    return D;
}

struct Dual tanhDual(struct Dual *A){
    // breaks down around x = -4;
    struct Dual B, C, D, E;
    double i, j;
    i = 2.0;
    B = mulVal(A, &i);
    B = expDual(&B, 20);
    j = 1.0;
    C = subVal(&B, &j);
    D = addVal(&B, &j);
    E = divDual(&C, &D);
    return E;
}