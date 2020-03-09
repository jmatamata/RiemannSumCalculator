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
    //This data member holds an array of characters that the user inputs as a function.
   char functionBuffer[40];
    
public:
    void reader ();
    
    //This function catches all the multiples in the user inputted function. All numbers after 'x' symbol.
    long double multipleFunctionCatcher ( int head );
    
    //This function catches all the power numbers that are after the '^' symbol.
    int powerFunctionCatcher ( int head );
    
    //This function catches the constant at the end of the user defined function.
    long double constantFunctionCatcher ();
    
    bool constantChecker ();
};
