//
//  functionReader.cpp
//  Riemann Sum
//
//  Created by Jorge Mata Jr on 2/15/20.
//  Copyright © 2020 Mata Works. All rights reserved.
//
#include <iostream>
#include <vector>
#include "functionReader.hpp"

extern std::vector<long double> function;

void functionReader::reader ()
{
    
    std::cout <<  "Enter your function in terms of x below (don't use spaces):" << std::endl;
    
    std::cin.getline(functionBuffer, 40);
    
    for ( int i = 0; i < 40; i++)
    {
        switch (i) {
            case '^':
                std::cout << "Exponent" << std::endl;
                break;
                
            case '*':
                std::cout << "Multiplication" << std::endl;
                break;
                
            case '+':
                std::cout << "Addition" << std::endl;
                break;
                
            case '-':
                std::cout << "Subtraction" << std::endl;
                break;
                
            case 'x':
                std::cout << "Variable" << std::endl;
                break;
                
            default:
                break;
        }
    }
    
    std::wcout << functionBuffer << std::endl;
}

