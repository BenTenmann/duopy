//
// Created by Benjamin Tenmann on 15/02/2021.
//

#ifndef DUOPY_DU_FUNCTIONS_H
#define DUOPY_DU_FUNCTIONS_H

#include "duals.h"

unsigned long long factorial(int n);
struct Dual powerDual(struct Dual *A, int n);
struct Dual expDual(struct Dual *A, int n);
struct Dual lnDual(struct Dual *A, int n);
struct Dual sinhDual(struct Dual *A);
struct Dual coshDual(struct Dual *A);
struct Dual tanhDual(struct Dual *A);

#endif //DUOPY_DU_FUNCTIONS_H