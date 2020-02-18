//
//  prompt.cpp
//  Riemann Sum
//
//  Created by Jorge Mata Jr on 11/26/19.
//  Copyright © 2019 Mata Works. All rights reserved.
//

#include <iostream>
#include <vector>
#include "prompt.hpp"

extern std::vector<long double> variableContainer;    //This is a vector that is located in main.cpp but will be utilized during compile.
extern std::vector<long double> multipleContainer;    //This is a vector that is located in main.cpp but will be utilized during compile.
extern std::vector<int> powerContainer; //This is a vector that is located in main.cpp but will be utilized during compile.

//This function takes in the user variable and iterator number as arguments and propts user to enter corisponding values
void variablePush( long double user, const int& i)
{
    std::cout << "Type variable " << i << " for term " << i << std::endl;
    std::cin >> user;
    variableContainer.push_back(user);
}

//This function takes in the user multiple and iterator number as arguments and propts user to enter corisponding values
void multiplePush( long double user, const int& i)
{
    std::cout << "Type multiple " << i << " for term " << i << std::endl;
    std::cin >> user;
    multipleContainer.push_back(user);
}

 //This function takes in the user power and iterator number as arguments and propts user to enter corisponding values
void powerPush( int user, const int& i)
{
    std::cout << "Type power " << i << " for term " << i << std::endl;
    std::cin >> user;
    powerContainer.push_back(user);
}

//This function prompts the user runs the above functions in a loop
void promptRun (const int& run)
{
    float userVariable = 0; //This variable contains all the users input for the variables
    float userMultiple = 1; //This variable contains all the users input for the multiples
    int userPower = 1;  //This variable contains all the users input for the powers
    
    //This runs a loop for how ever many times the user specifies
    for (int i = 1; i < run + 1; i++)
    {
        variablePush(userVariable, i);
        powerPush(userPower, i);
        multiplePush(userMultiple, i);
        
    }
}
