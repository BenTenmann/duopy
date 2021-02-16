//
//  duals.cpp
//  duopy
//
//  Created by Benjamin Tenmann on 31/01/2021.
//

#include <iostream>
#include "duals.hpp"

namespace DU {

Dual::Dual(double real, double dual){
    r = real;
    d = dual;
}

Dual Dual::operator +(double b){
        // add a dual number and a real number
        double real = r + b;
        
        Dual C(real, d);
        
        return C;
    }
    
Dual Dual::operator +(Dual B){
        // add two dula numbers
        double real = r + B.r;
        double dual = d + B.d;
        
        Dual C(real, dual);
        return C;
    }
    
Dual Dual::operator -(double b){
        // subtract a real number from a dual number
        double real = r - b;
        
        Dual C(real, d);
        
        return C;
    }
    
Dual Dual::r_subi(double b){
        // subtract a dual number from a real number
        double real = b - r;
        double dual = -d;
        
        Dual C(real, dual);
        
        return C;
    }
    
Dual Dual::operator -(Dual B){
        // subtract a dual number from a dual number
        double real = r - B.r;
        double dual = d - B.d;
        
        Dual C(real, dual);
        
        return C;
    }
    
Dual Dual::operator *(double b){
        // multiply a real number and a dual number
        double real = r * b;
        double dual = d * b;
        
        Dual C(real, dual);
        
        return C;
    }
    
Dual Dual::operator *(Dual B){
        // multiply two dual numbers
        double real = r * B.r;
        double dual = r * B.d + d * B.r;
        
        Dual C(real, dual);
        
        return C;
    }
    
Dual Dual::operator /(double b){
        // divide a dual number by a real number
        double real = r / b;
        double dual = d / b;
        
        Dual C(real, dual);
        
        return C;
    }
    
Dual Dual::r_divi(double b){
        // divide a real number by a dual number
        double real = b / r;
        double dual = -(b * d) / (r * r);
        
        Dual C(real, dual);
        
        return C;
    }
    
Dual Dual::operator /(Dual B){
        // divide two dual numbers
        double real = r / B.r;
        double dual = (d / B.r) - ((r * B.d) / (r * r));
        
        Dual C(real, dual);
        
        return C;
    }
    
std::ostream &operator<<( std::ostream &output, const Dual A ) {

        if (A.d < 0){
            output << A.r << A.d << "e";
        }
        else{
            output << A.r << "+" << A.d << "e";
        }
        return output;

}


Dual operator +(double b, Dual A){
    // add a real and a dual number
    double real = A.r + b;
    
    Dual C(real, A.d);
    
    return C;
}

Dual operator -(double b, Dual A){
    // subtract a dual number from a real number
    double real = b - A.r;
    double dual = -A.d;
    
    Dual C(real, dual);
    
    return C;
}

Dual operator *(double b, Dual A){
    // multiply a real number and a dual number
    double real = A.r * b;
    double dual = A.d * b;
    
    Dual C(real, dual);
    
    return C;
}

Dual operator /(double b, Dual A){
    // divide a real number by a dual number
    double real = b / A.r;
    double dual = -(b * A.d) / (A.r * A.r);
    
    Dual C(real, dual);
    
    return C;
}

}
