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
                for ( int j = i - 1; 0 <= j; j-- )
                {
                    if ( !(( '1' <= functionBuffer[j]) && (functionBuffer[j] <= '9')) )
                        {
                            break;
                        }
                    else
                        {
                        std::cout << functionBuffer[j] << std::endl;
                        }
                }

            }
                
    }
    
    std::wcout << functionBuffer << std::endl;
}

