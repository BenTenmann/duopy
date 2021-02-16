//
// Created by Benjamin Tenmann on 15/02/2021.
//

#include "duals.h"

struct Dual addDual(struct Dual *A, struct Dual *B) {
    struct Dual C = {.r = (*A).r + (*B).r, .d = (*A).d + (*B).d};
    return C;
}

struct Dual addVal(struct Dual *A, double *b) {
    struct Dual C = {.r = (*A).r + (*b), (*A).d};
    return C;
}

struct Dual subDual(struct Dual *A, struct Dual *B) {
    struct Dual C = {.r = (*A).r - (*B).r, .d = (*A).d - (*B).d};
    return C;
}

struct Dual subVal(struct Dual *A, double *b) {
    struct Dual C = {.r = (*A).r - (*b), .d = (*A).d};
    return C;
}

struct Dual isubVal(double *a, struct Dual *B) {
    struct Dual A = {.r = (*a) - (*B).r, .d = 0 - (*B).d};
    return A;
}

struct Dual mulDual(struct Dual *A, struct Dual *B) {
    struct Dual C = {.r = (*A).r * (*B).r, .d = (*A).r * (*B).d + (*A).d * (*B).r};
    return C;
}

struct Dual mulVal(struct Dual *A, double *b) {
    struct Dual C = {.r = (*A).r * (*b), .d = (*A).d * (*b)};
    return C;
}

struct Dual divDual(struct Dual *A, struct Dual *B) {
    struct Dual C = {.r = (*A).r / (*B).r, .d = (*A).d / (*B).r - (*A).r * (*B).d / ((*B).r * (*B).r)};
    return C;
}

struct Dual divVal(struct Dual *A, double *b) {
    struct Dual B = {.r = (*b), .d = 0};
    struct Dual C = divDual(A, &B);
    return C;
}

struct Dual idivVal(double *a, struct Dual *B) {
    struct Dual A = {.r = (*a), .d = 0};
    struct Dual C = divDual(&A, B);
    return C;
}

