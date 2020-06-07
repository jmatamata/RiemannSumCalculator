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
    
    float _beginInterval;
    
    float _endInterval;
    
    int _nTerm;
    
    float _base;
    
    char sumChoiceBuffer[40];
    
public:
    
    void functionBase ();
    
    void sumChoice ( functionReader& userFunction );
    
    float leftRiemannSum (functionReader& userFunction );
    
    float rightRiemannSum ( functionReader& userFunction );
    
    float midRiemannSum ( functionReader& userFunction );
    
    float trapRiemannSum ( functionReader& userFunction );
};
