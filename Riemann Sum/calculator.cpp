//
//  calculator.cpp
//  Riemann Sum
//
//  Created by Jorge Mata Jr on 3/27/20.
//  Copyright © 2020 Mata Works. All rights reserved.
//

#include <iostream>
#include <vector>
#include "calculator.hpp"
#include "functionReader.hpp"
#include "polynomial.hpp"


void summation::functionBase ()
{
    std::cout <<  "Enter the beginging interval for your Riemann Sum: ";
    
    std::cin >> _beginInterval;
    
    std::cout <<  "Enter the ending interval for your Riemann Sum: ";
    
    std::cin >> _endInterval;
    
    std::cout <<  "Enter how many rectangles you want to use to find the area of your function: ";
    
    std::cin >> _nTerm;
    
    _base = (_endInterval - _beginInterval) / _nTerm;
    
    std::cout << "\n";
    
}


long double summation::leftRiemannSum ( functionReader& userFunction )
{
    long double sum = 0;
    
    for ( int i = 0; i < _nTerm; i++ )
        {
            sum += userFunction.function( _beginInterval + (i * _base) );
        }
    
    sum *= _base;
    
    return sum;
}

