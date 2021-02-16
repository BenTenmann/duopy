//
//  duals.hpp
//  duopy
//
//  Created by Benjamin Tenmann on 31/01/2021.
//

#ifndef duals_hpp
#define duals_hpp

#include <stdio.h>
#include <iostream>


namespace DU
{
class Dual {
public:
    double r;
    double d;
    
    Dual(double real, double dual);
    
    Dual operator +(double b);
    
    Dual operator +(Dual B);
    
    Dual operator -(double b);
    
    Dual r_subi(double b);
    
    Dual operator -(Dual B);
    
    Dual operator *(double b);
    
    Dual operator *(Dual B);
    
    Dual operator /(double b);
    
    Dual r_divi(double b);
    
    Dual operator /(Dual B);
    
    friend std::ostream &operator<<( std::ostream &output, const Dual A );
    
    friend Dual operator +(double b, Dual A);
    
    friend Dual operator -(double b, Dual A);
    
    friend Dual operator *(double b, Dual A);
    
    friend Dual operator /(double b, Dual A);
};

std::ostream &operator<<( std::ostream &output, const DU::Dual A );

Dual operator +(double b, Dual A);

Dual operator -(double b, Dual A);

Dual operator *(double b, Dual A);

Dual operator /(double b, Dual A);

}


#endif /* duals_hpp */
