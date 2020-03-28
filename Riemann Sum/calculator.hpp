//
//  calculator.hpp
//  Riemann Sum
//
//  Created by Jorge Mata Jr on 3/27/20.
//  Copyright © 2020 Mata Works. All rights reserved.
//

#pragma once
#include "functionReader.hpp"


class summation
{
    
    double _beginInterval;
    
    double _endInterval;
    
    int _nTerm;
    
    long double _base;
    
public:
    
    void functionBase ();
    
    long double leftRiemannSum (functionReader& userFunction);
};
