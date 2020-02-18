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
                std::vector<char> temp;
                for ( int j = i - 1; 0 <= j; j-- )
                {
                    if ( !(( '1' <= functionBuffer[j]) && (functionBuffer[j] <= '9')) )
                        {
                            break;
                        }
                    else
                        {
                            std::cout << functionBuffer[j];
                            temp.push_back(functionBuffer[j]);
                        }
                }
                
                std::cout << '\n';
                    
                std::reverse(temp.begin(), temp.end());
                    
                    for (std::vector<char>::const_iterator it = temp.begin(); it != temp.end(); ++it)
                    {
                        std::cout << *it;
                    }
                    std::cout << '\n';

            }
                
    }
}

