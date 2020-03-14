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
    
    
    for ( char* index = functionBuffer; index != bufferEnd; index++)
    {
        
        if ( *index == '^' )
            {
                std::cout << this->powerFunctionCatcher(index) << std::endl;
            }
            
        else if ( (*index == 'x' || *index == 'X' ) )
            {
                std::cout << this->multipleFunctionCatcher(index) << std::endl;
            }
                
    }
    
    std::cout << this->constantFunctionCatcher() << std::endl;
}



long double functionReader::multipleFunctionCatcher ( char* index )
{
    std::vector<char> temp;
    
    for ( char* multiplePointer = index - 1; multiplePointer != bufferStart; --multiplePointer )
    {
        if ( !((( '1' <= *multiplePointer) && (*multiplePointer <= '9')) || *multiplePointer == '.' || *multiplePointer == '-') )
            {
                break;
            }
        else
            {
                temp.push_back(*multiplePointer);
            }
    }
    
    std::reverse(temp.begin(), temp.end());
    
    std::string stringNumber (temp.begin(), temp.end());
    
    long double number = std::stold(stringNumber);
    
    return number;
}



int functionReader::powerFunctionCatcher ( char* index )
{
        std::vector<char> temp;
        for ( char* powerPointer = index; powerPointer != bufferEnd; powerPointer++ )
        {
            if ( !(( '1' <= *powerPointer) && (*powerPointer <= '9')) )
                {
                    break;
                }
            else
                {
                    temp.push_back(*powerPointer);
                }
        }
        
        std::reverse(temp.begin(), temp.end());
        
        std::string stringNumber (temp.begin(), temp.end());
        
        int number = std::stoi(stringNumber);
        
        return number;
}



bool functionReader::constantChecker ()
{
    bool constantCondition = false;
    
    for ( char* index = functionBuffer + 40; index != bufferStart; --index )
    {
        if ( *index == ' ' || ( ( '1' <= *index) && (*index <= '9') ) )
        {
            continue;
        }
        else if ( *index == '^' || (*index == 'x' || *index == 'X' ))
        {
            break;
        }
        else if ( *index == '+' )
        {
            constantCondition = true;
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
        for ( char* index = functionBuffer + 40; index != bufferStart; --index )
        {
            if ( *index == ' ' )
                {
                    continue;
                }
            
            else if ( ( '1' <= *index) && (*index <= '9') )
                {
                    temp.push_back(*index);
                }
            
            else
                {
                    break;
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
