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
    
    char sumChoiceBuffer[40];
    
public:
    
    void functionBase ();
    
    void sumChoice ( functionReader& userFunction );
    
    long double leftRiemannSum (functionReader& userFunction );
    
    long double rightRiemannSum ( functionReader& userFunction );
    
    long double midRiemannSum ( functionReader& userFunction );
    
    long double trapRiemannSum ( functionReader& userFunction );
};
