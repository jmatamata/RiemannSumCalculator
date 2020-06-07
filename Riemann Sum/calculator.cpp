//
//  calculator.cpp
//  Riemann Sum
//
//  Created by Jorge Mata Jr on 3/27/20.
//  Copyright © 2020 Mata Works. All rights reserved.
//

#include <iostream>
#include <vector>
#include "calculator.hpp"
#include "functionReader.hpp"


void summation::functionBase ()
{
    std::cout << "\n";
    
    std::cout <<  "Enter the beginging interval for your Riemann Sum: ";
    
    std::cin >> _beginInterval;
    
    std::cout <<  "Enter the ending interval for your Riemann Sum: ";
    
    std::cin >> _endInterval;
    
    std::cout <<  "Enter how many rectangles you want to use to find the area of your function: ";
    
    std::cin >> _nTerm;
    
    _base = (_endInterval - _beginInterval) / _nTerm;
    
    std::cout << "\n";
    
}


void summation::sumChoice ( functionReader& userFunction )
{
    char userChoice;
    
    bool choiceCondition = false;

    std::cout <<  "L = Left Riemann Sum" << std::endl;
    std::cout <<  "R = Right Riemann Sum" << std::endl;
    std::cout <<  "M = Midpoint Riemann Sum" << std::endl;
    std::cout <<  "T = Trapezoidal Riemann Sum" << std::endl;

    std::cout <<  "Enter the Riemann Sum method you want to use: ";

    while ( !choiceCondition )
    {
        std::cin >> userChoice;

        if ( userChoice == 'L' || userChoice == 'l' )
        {
            std::cout << "\n";
            std::cout << "Left Riemann Sum result: " <<this->leftRiemannSum(userFunction) << std::endl;
            std::cout << "\n";
            choiceCondition = true;
        }
        else if ( userChoice == 'R' || userChoice == 'r' )
        {
            std::cout << "\n";
            std::cout << "Right Riemann Sum result: " << this->rightRiemannSum(userFunction) << std::endl;
            std::cout << "\n";
            choiceCondition = true;
        }
        else if ( userChoice == 'M' || userChoice == 'm' )
        {
            std::cout << "\n";
            std::cout << "Midpoint Riemann Sum result: " << this->midRiemannSum(userFunction) << std::endl;
            std::cout << "\n";
            choiceCondition = true;
        }
        else if ( userChoice == 'T' || userChoice == 't' )
        {
            std::cout << "\n";
            std::cout << "Trapezoidal Riemann Sum result: " << this->trapRiemannSum(userFunction) << std::endl;
            std::cout << "\n";
            choiceCondition = true;
        }
        else
        {
            std::cout << "\n";
            std::cout << "Invalid Choice. Try again: ";
        }
    }
}


float summation::leftRiemannSum ( functionReader& userFunction )
{
    float sum = 0;
    
    for ( int i = 0; i < _nTerm; i++ )
    {
        sum += userFunction.function( _beginInterval + (i * _base) );
    }
    
    sum *= _base;
    
    return sum;
}


float summation::rightRiemannSum ( functionReader& userFunction )
{
    float sum = 0;
    
    for ( int i = 1; i <= _nTerm; i++ )
    {
        sum += userFunction.function( _beginInterval + (i * _base) );
    }
    
    sum *= _base;
    
    return sum;
}


float summation::midRiemannSum ( functionReader& userFunction )
{
    float sum = 0;
    
    for ( float i = 0.5; i <= _nTerm; i++ )
    {
        sum += userFunction.function( _beginInterval + ( i * _base ) );
    }
    
    sum *= _base;
    
    return sum;
}



float summation::trapRiemannSum ( functionReader& userFunction )
{
    float sum = 0;
    
    for ( int i = 0; i < _nTerm; i++ )
    {
        if ( i == 0 )
        {
            sum += userFunction.function( _beginInterval );
        }
        
        else
        {
            sum += 2 * (userFunction.function( _beginInterval + (i * _base)) );
        }
        
    }
    
    sum *= (_base / 2);
    
    return sum;
}
