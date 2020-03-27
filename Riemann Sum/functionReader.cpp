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


//MAIN READER
//---------------------------------------------------------------------------------------------------------------


void functionReader::reader ()
{
    
    std::cout <<  "Enter your function in terms of x below:" << std::endl;
    
    //Grabs the input of the user with a 40 character limit and stores it into functionBuffer.
    std::cin.getline(functionBuffer, 40);
    
    
    //Initializes a pointer that iterates through the char array and calls the functions below if needed.
    for ( char* index = functionBuffer; index != bufferEnd; index++)
    {
        
        //This runs the powerFunctionCatcher function if it sees the carot operator.
        //Obtains the powers of the polynomials.
        if ( *index == '^' )
            {
                std::cout << this->powerFunctionCatcher(index) << std::endl;
            }
        
        //This runs the multipleFunctionCatcher function if it sees the char x or X.
        //Obtains the multiples of the polynomials.
        if ( (*index == 'x' || *index == 'X' ) )
            {
                std::cout << this->multipleFunctionCatcher(index) << std::endl;
                variableTerms++;
            }
                
    }
    
    //This calls the constantFunctionCatcher function which retrieves the constants from the functions.
    std::cout << this->constantFunctionCatcher() << std::endl;
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
        if ( ('1' <= *multiplePointer && *multiplePointer <= '9') || *multiplePointer == '.' || *multiplePointer == '-')
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


int functionReader::powerFunctionCatcher ( char* index )
{
        //Initializes a temporary vector to store the needed characters.
        std::vector<char> temp;
    
        //Iterates through the charBuffer and pushes back any numbers that represent the power.
        for ( char* powerPointer = index + 1; powerPointer != bufferEnd; powerPointer++ )
        {
            if ( '1' <= *powerPointer && *powerPointer <= '9' )
                {
                    temp.push_back(*powerPointer);
                    
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
    
        //This erases any possible blank space from the string before being converted into an int.
        stringNumber.erase(std::remove(stringNumber.begin(), stringNumber.end(),' '), stringNumber.end());
        
        //This converts the string into an int.
        int number = std::stoi(stringNumber);
        
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
            
            if ( ('1' <= *index && *index <= '9') || *index == '.' || *index == '-')
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

