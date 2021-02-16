//
// Created by Benjamin Tenmann on 15/02/2021.
//

#ifndef DUOPY_DUALS_H
#define DUOPY_DUALS_H

#include "du_functions.h"

struct Dual{
    double r, d;
};

struct Dual addDual(struct Dual *A, struct Dual *B);
struct Dual addVal(struct Dual *A, double *b);
struct Dual subDual(struct Dual *A, struct Dual *B);
struct Dual subVal(struct Dual *A, double *b);
struct Dual isubVal(double *a, struct Dual *B);
struct Dual mulDual(struct Dual *A, struct Dual *B);
struct Dual mulVal(struct Dual *A, double *b);
struct Dual divDual(struct Dual *A, struct Dual *B);
struct Dual divVal(struct Dual *A, double *b);
struct Dual idivVal(double *a, struct Dual *B);

#endif //DUOPY_DUALS_H
