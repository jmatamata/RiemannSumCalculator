//
//  polynomial.hpp
//  Riemann Sum
//
//  Created by Jorge Mata Jr on 11/26/19.
//  Copyright © 2019 Mata Works. All rights reserved.
//

#pragma once

class polynomial
{
    long double _variable;
    long double _multiple;
    long double _power;
    
public:
    //polynomial();   //This is the defult constructor
    polynomial( long double multiple = 0, long double variable = 0, long double power = 1 );   //This constructor creates the parts of the polynomial
    ~polynomial();  //deconstructor
    polynomial ( const polynomial& ); //This is a copy constructor
    void setPower (const long double& power);    //This member function sets the power of the polynomial
    void setMultiple (const long double& multiple);    //This member function sets the multiple of the polynomial
    void setVariable (const long double& Variable);    //This member function sets the variable of the polynomial
    long double getPower () const;  //This member function gets the power of the polynomial
    long double getMultiple () const; //This member function gets the multiple of the polynomial
    long double getVariable () const; //This member function gets the variable of the polynomial
    void print () const;    //This member function prints the parts of the polynimial in power form
    long double value () const;

};

long double operator + (const polynomial& lhs, const polynomial& rhs);

