//
//  main.cpp
//  Riemann Sum
//
//  Created by Jorge Mata Jr on 11/25/19.
//  Copyright © 2019 Mata Works. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "calculator.hpp"
#include "functionReader.hpp"


int main(int argc, const char * argv[])
{
    try
    {

        functionReader userFunction;

        summation userCalculation;

        userFunction.reader();

        userCalculation.functionBase();

        userCalculation.sumChoice(userFunction);

    }

    catch (...)
    {
        std::cout << "Error" << std::endl;
        std::cout << "Try inputting the function again." << std::endl;
    }


    return 0;
    
}


