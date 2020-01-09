//
//  polynomial.cpp
//  Riemann Sum
//
//  Created by Jorge Mata Jr on 11/26/19.
//  Copyright © 2019 Mata Works. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "polynomial.hpp"

extern std::vector<long double> variableContainer;    //This is a vector that is located in main.cpp but will be utilized during compile.

extern std::vector<long double> multipleContainer;    //This is a vector that is located in main.cpp but will be utilized during compile.
extern std::vector<int> powerContainer; //This is a vector that is located in main.cpp but will be utilized during compile.


//vector that contains the parts of the polynomial that is located in main.cpp
extern std::vector<polynomial*> polynomialVector;

//Member function that takes arguments (the multiple and power arguments are initialized in the function declaration)
polynomial::polynomial( long double variable, int power, long double multiple ) : _variable(variable), _power(power), _multiple(multiple)
{
    std::cout << "object created" << std::endl;
}

//Destructor
polynomial::~polynomial()
{
    std::cout << "object destroyed" << std::endl;
}

polynomial::polynomial ( const polynomial& p) : _variable(p._variable), _power(p._power), _multiple(p._multiple)
{
    std::cout << "COPY" << std::endl;
}

//Sets power of polynomial
void polynomial::setPower ( const int& power)
{
    _power = power;
}

//Sets multiple of polynomial
void polynomial::setMultiple ( const long double& multiple )
{
    _multiple = multiple;
}

//Sets variable of polynomial
void polynomial::setVariable ( const long double& variable )
{
    _variable = variable;
}

//Gets power of polynomial
int polynomial::getPower () const
{
    return _power;
}

//Gets multiple of polynomial
float polynomial::getMultiple () const
{
    return _multiple;
}

//Gets variable of polynomial
float polynomial::getVariable () const
{
    return _variable;
}

//Prints polynomial in the special format
void polynomial::print () const
{
    std::cout << _multiple << " * " << _variable << " ^ " << _power << std::endl;
}

long double polynomial::value () const
{
    long double value = _multiple * (pow(_variable, _power));
    return value;
}

// This overloads the + operator to add two parts of a polynomial
long double operator + (const polynomial& lhs, const polynomial& rhs)
{
    long double value = lhs.value() + rhs.value();
    return value;
}


// This puts the parts of the polynomial into a vector located in the heap (DONT FORGET TO DEALLOCATE)
void polyLoad ( const int& run )
{
    for (int i = 0; i < run; i++)
    {
        polynomial* polynomialPart = new polynomial(variableContainer.at(i), powerContainer.at(i), multipleContainer.at(i));
        polynomialVector.push_back(polynomialPart);
    }
}


// This function adds up the polynomial parts and evaluates a polynomial
long double polySum ( const int& run )
{
    long double sum = 0;
    for(int i = 0; i < polynomialVector.size(); i++)
    {
        sum += polynomialVector.at(i)->value();
    }
    return sum;
}

