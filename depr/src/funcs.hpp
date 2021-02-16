//
//  funcs.hpp
//  duopy
//
//  Created by Benjamin Tenmann on 31/01/2021.
//

#ifndef funcs_hpp
#define funcs_hpp

#include <stdio.h>
#include "duals.hpp"

unsigned long long factorial(int n);

DU::Dual power(DU::Dual A, int n);

DU::Dual exp(DU::Dual A, int n);

DU::Dual ln(DU::Dual A, int n);

DU::Dual tanh(DU::Dual A, int n = 20);

#endif /* funcs_hpp */
