//
//  main.cpp
//  Riemann Sum
//
//  Created by Jorge Mata Jr on 11/25/19.
//  Copyright © 2019 Mata Works. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "polynomial.hpp"
#include "prompt.hpp"

std::vector<long double> variableContainer;
std::vector<long double> multipleContainer;
std::vector<int> powerContainer;
std::vector<polynomial*> polynomialVector;

int main(int argc, const char * argv[]) {
   
    
    int runNum;

    std::cout << "How many terms does your polynomial have?:" << std::endl;
    std::cin >> runNum;


    promptRun(runNum);


    polyLoad(runNum);


    long double answer = polySum(runNum);

    std::cout << answer << std::endl;

    polyDestroy(polynomialVector);

/*
    At 1:50a I decided a method for aproaching this. I thought it would be a magnificant idea to push the multiple/variable/power
    user variables into vectors to be called later to be used as polynomial parameters. The main would run a loop to dependeing on
    how long the users polynomial is. Every loop would ask the user for term 1, 2, 3... and the results would be stored into the
    coresponding vectors. I also had a great idea to manage the amount of bits the user's int would be, the last thing we need
    is for some retard to make 2000 objects lmao. We will also need to overload the operators to be able to add the terms together.
*/
    return 0;
}
