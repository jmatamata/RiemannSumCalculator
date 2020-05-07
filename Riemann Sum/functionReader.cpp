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
#include <cmath>
#include "functionReader.hpp"


//MAIN READER
//---------------------------------------------------------------------------------------------------------------


void functionReader::reader ()
{
    
    std::cout <<  "Enter your function in terms of x below (40 Character Limit)" << std::endl;
    std::cout <<  "(Write in Format Below)" << std::endl;
    std::cout <<  "Ex: Ax^2 + Bx^1 + C" << std::endl;
    
    //Grabs the input of the user with a 40 character limit and stores it into functionBuffer.
    std::cin.getline(functionBuffer, 40);
    
    
    //Initializes a pointer that iterates through the char array and calls the functions below if needed.
    for ( char* index = functionBuffer; index != bufferEnd; index++)
    {
        
        //This runs the powerFunctionCatcher function if it sees the carot operator.
        //Obtains the powers of the polynomials.
        if ( *index == '^' )
            {
                //std::cout << "Power: " <<this->powerFunctionCatcher(index) << std::endl;
                functionPowers.push_back(this->powerFunctionCatcher(index));
            }
        
        //This runs the multipleFunctionCatcher function if it sees the char x or X.
        //Obtains the multiples of the polynomials.
        if ( (*index == 'x' || *index == 'X' ) )
            {
                //std::cout << "Multiple: " <<this->multipleFunctionCatcher(index) << std::endl;
                functionMultiples.push_back(this->multipleFunctionCatcher(index));
                variableTerms++;
                //std::cout << "Term: " << variableTerms << std::endl;
            }
                
    }
    
    //This calls the constantFunctionCatcher function which retrieves the constants from the functions.
    //std::cout << this->constantFunctionCatcher() << std::endl;
    functionConstant = this->constantFunctionCatcher();
}


//FOR MULTIPLES
//---------------------------------------------------------------------------------------------------------------


long double functionReader::multipleFunctionCatcher ( char* index )
{
    //Initializes a temporary vector to store the needed characters.
    std::vector<char> temp;
    
    
    //Iterates through the charBuffer and pushes back any numbers that represent the multiples.
    for ( char* multiplePointer = index - 1; multiplePointer != bufferStart; --multiplePointer )
    {
        if ( ('0' <= *multiplePointer && *multiplePointer <= '9') || *multiplePointer == '.' || *multiplePointer == '-' )
            {
                temp.push_back(*multiplePointer);
            }
        else
            {
                break;
            }
    }
    
    //This reverses the temporary vector inorder to get the number in it's correct orientation.
    std::reverse(temp.begin(), temp.end());
    
    //This converts the char vector into a string
    std::string stringNumber (temp.begin(), temp.end());
    
    //This erases any possible blank space from the string before being converted into a long double.
    stringNumber.erase(std::remove(stringNumber.begin(), stringNumber.end(),' '), stringNumber.end());
    
    //This converts the string into a long double.
    long double number = std::stold(stringNumber);
    
    //This returns the multiple number.
    return number;
}


//FOR POWERS
//---------------------------------------------------------------------------------------------------------------


long double functionReader::powerFunctionCatcher ( char* index )
{
        //Initializes a temporary vector to store the needed characters.
        std::vector<char> temp;
    
        //Iterates through the charBuffer and pushes back any numbers that represent the power.
        for ( char* powerPointer = index + 1; powerPointer != bufferEnd; powerPointer++ )
        {
            if ( ('0' <= *powerPointer && *powerPointer <= '9') || *powerPointer == '.' || *powerPointer == '-' )
                {
                    temp.push_back(*powerPointer);
                    
                }
            else
                {
                    break;
                }
        }
        
        //This converts the char vector into a string
        std::string stringNumber (temp.begin(), temp.end());
    
        //This erases any possible blank space from the string before being converted into an int.
        stringNumber.erase(std::remove(stringNumber.begin(), stringNumber.end(),' '), stringNumber.end());
        
        //This converts the string into an int.
        long double number = std::stold(stringNumber);
    
        //This returns the power number.
        return number;
        
}


//FOR CONSTANTS
//---------------------------------------------------------------------------------------------------------------


bool functionReader::constantChecker ()
{
    //By default sets the function return as false.
    bool constCondition = false;
    
    //Iterates through the function buffer finds whether a '^' or '+' comes before one another.
    for ( char* index = functionBuffer + 40; index != bufferStart; --index )
    {
        
        if ( *index == '+' )
            {
                constCondition = true;
                break;
            }
        
        else if ( *index == '^' )
            {
                constCondition = false;
                break;
            }
    }
    
    return constCondition;
}





long double functionReader::constantFunctionCatcher ()
{
    long double number = 0;
    
    //Checks whether the code should run using constChecker function.
    if (this->constantChecker())
    {
        //Initializes a temporary vector to store the needed characters.
        std::vector<char> temp;
        
        //Iterates through the charBuffer and pushes back any numbers that represent the constant.
        for ( char* index = functionBuffer + 40; index != bufferStart; --index )
        {
            
            if ( ('0' <= *index && *index <= '9') || *index == '.' || *index == '-')
                {
                    temp.push_back(*index);
                }
            
            if ( *index == '+' )
                {
                    break;
                }
        }
        
        //This reverses the temporary vector inorder to get the number in it's correct orientation.
        std::reverse(temp.begin(), temp.end());
        
        //This converts the char vector into a string
        std::string stringNumber (temp.begin(), temp.end());
        
        //This erases any possible blank space from the string before being converted into a long double.
        stringNumber.erase(std::remove(stringNumber.begin(), stringNumber.end(),' '), stringNumber.end());
        
        //This converts the string into a long double.
        number = std::stold(stringNumber);
    }
    
    return number;
}

//FOR FUNCTION BUILDER
//---------------------------------------------------------------------------------------------------------------

long double functionReader::function ( const long double& variable )
{
    if ( int(functionMultiples.size()) == variableTerms && int(functionPowers.size()) == variableTerms)
    {
        long double functionEvaluation = 0;
        
        for ( int i = 0; i < variableTerms; i++)
        {
            functionEvaluation += functionMultiples[i] * (pow(variable, functionPowers[i]));
        }
        
        functionEvaluation += functionConstant;
        
        return functionEvaluation;
    }
    else
    {
        std::cout << "Function Evaluation Failed" << std::endl;
        return -1;
    }
}


//FOR VARIABLE TERM GETTER
//---------------------------------------------------------------------------------------------------------------

int functionReader::getVariableTerms()
{
    return variableTerms;
}

