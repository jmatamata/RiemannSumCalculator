//
//  functionReader.cpp
//  Riemann Sum
//
//  Created by Jorge Mata Jr on 2/15/20.
//  Copyright © 2020 Mata Works. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "functionReader.hpp"



void functionReader::reader ()
{
    
    std::cout <<  "Enter your function in terms of x below:" << std::endl;
    
    std::cin.getline(functionBuffer, 40);
    
    for ( int i = 0; i < 40; i++)
    {
        
        if ( functionBuffer[i] == '^' )
            {
                
            }
                
        else if ( functionBuffer[i] == '*' )
            {
                
            }
            
        else if ( functionBuffer[i] == '+' )
            {
                
            }
            
        else if ( functionBuffer[i] == '-' )
            {
                
            }
            
        else if ( functionBuffer[i] == 'x' )
            {
                std::cout << this->multipleFunctionCatcher(i) << std::endl;
            }
                
    }
}

long double functionReader::multipleFunctionCatcher ( int head )
{
    std::vector<char> temp;
    for ( int j = head - 1; 0 <= j; j-- )
    {
        if ( !((( '1' <= functionBuffer[j]) && (functionBuffer[j] <= '9')) || functionBuffer [j] == '.') )
            {
                break;
            }
        else
            {
                temp.push_back(functionBuffer[j]);
            }
    }
    
    std::reverse(temp.begin(), temp.end());
    
    std::string sNumber (temp.begin(), temp.end());
    
    long double number = std::stold(sNumber);
    
    return number;
}

//This is the old algorithm I put in the else if statement in the reader function.
//                std::vector<char> temp;
//                for ( int j = i - 1; 0 <= j; j-- )
//                {
//                    if ( !((( '1' <= functionBuffer[j]) && (functionBuffer[j] <= '9')) || functionBuffer [j] == '.') )
//                        {
//                            break;
//                        }
//                    else
//                        {
//                            temp.push_back(functionBuffer[j]);
//                        }
//                }
//
//                std::reverse(temp.begin(), temp.end());
//
//                std::string sNumber (temp.begin(), temp.end());
//
//                long double number = std::stold(sNumber);
//
//                std::cout << number << std::endl;
