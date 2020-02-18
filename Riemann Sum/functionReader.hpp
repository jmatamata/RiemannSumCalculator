//
//  functionReader.hpp
//  Riemann Sum
//
//  Created by Jorge Mata Jr on 2/15/20.
//  Copyright © 2020 Mata Works. All rights reserved.
//

#pragma once

class functionReader
{
   char functionBuffer[40];
    
public:
    void reader ();
    
    long double multipleFunctionCatcher ( int head );
    
    int powerFunctionCatcher ( int head );
};
