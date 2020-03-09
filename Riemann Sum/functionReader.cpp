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
                std::cout << this->powerFunctionCatcher(i) << std::endl;
            }
            
        else if ( functionBuffer[i] == 'x' )
            {
                std::cout << this->multipleFunctionCatcher(i) << std::endl;
            }
                
    }
    
    std::cout << this->constantFunctionCatcher() << std::endl;
}



long double functionReader::multipleFunctionCatcher ( int head )
{
    std::vector<char> temp;
    for ( int j = head - 1; 0 <= j; j-- )
    {
        if ( !((( '1' <= functionBuffer[j]) && (functionBuffer[j] <= '9')) || functionBuffer [j] == '.' || functionBuffer[j] == '-') )
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



int functionReader::powerFunctionCatcher ( int head )
{
        std::vector<char> temp;
        for ( int j = head + 1; j <= 39; j++ )
        {
            if ( !(( '1' <= functionBuffer[j]) && (functionBuffer[j] <= '9')) )
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
        
        int number = std::stoi(sNumber);
        
        return number;
}



bool functionReader::constantChecker ()
{
    bool constantCondition = false;
    for ( int j = 40; 0 <= j; j-- )
    {
        if ( functionBuffer[j] == ' ' )
        {
            continue;
        }
        else if (( '1' <= functionBuffer[j]) && (functionBuffer[j] <= '9'))
        {
            continue;
        }
        else if ( functionBuffer[j] == '+' )
        {
            constantCondition = true;
            break;
        }
        else
            {
                break;
            }
    }
    return constantCondition;
}



long double functionReader::constantFunctionCatcher ()
{
    long double number = 0;
    
    if (this->constantChecker())
    {
        std::vector<char> temp;
        for ( int j = 40; 0 <= j; j-- )
        {
            if ( functionBuffer[j] == ' ' )
                {
                    continue;
                }
            
            else if ( ( '1' <= functionBuffer[j]) && (functionBuffer[j] <= '9') )
                {
                    temp.push_back(functionBuffer[j]);
                }
            
            else
                {
                    continue;
                }
        }
        
        std::reverse(temp.begin(), temp.end());
        
        std::string sNumber (temp.begin(), temp.end());
        
        number = std::stold(sNumber);
    }
    
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


//This is the old algorithm I put in the else if statement in the reader function.
//std::vector<char> temp;
//for ( int j = i + 1; j <= 39; j++ )
//{
//    if ( !(( '1' <= functionBuffer[j]) && (functionBuffer[j] <= '9')) )
//        {
//            break;
//        }
//    else
//        {
//            temp.push_back(functionBuffer[j]);
//        }
//}
//
//std::reverse(temp.begin(), temp.end());
//
//std::string sNumber (temp.begin(), temp.end());
//
//int number = std::stoi(sNumber);
//
//std::cout << number << std::endl;
