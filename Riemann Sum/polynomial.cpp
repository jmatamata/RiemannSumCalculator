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


//Member function that takes arguments (the multiple and power arguments are initialized in the function declaration)
polynomial::polynomial( long double multiple, long double variable, long double power ) : _multiple(multiple), _variable(variable), _power(power)
{
    //std::cout << "object created" << std::endl;
}

//Destructor
polynomial::~polynomial()
{
    //std::cout << "object destroyed" << std::endl;
}

polynomial::polynomial ( const polynomial& p) : _variable(p._variable), _multiple(p._multiple), _power(p._power)
{
    std::cout << "COPY" << std::endl;
}

//Sets power of polynomial
void polynomial::setPower ( const long double& power)
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
long double polynomial::getPower () const
{
    return _power;
}

//Gets multiple of polynomial
long double polynomial::getMultiple () const
{
    return _multiple;
}

//Gets variable of polynomial
long double polynomial::getVariable () const
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

