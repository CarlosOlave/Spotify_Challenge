//
//  main.cpp
//  SpotifyProblem1
//
//  Created by Carlos Olave (Mr. Peru).
//  Copyright (c) 2013 Carlos Olave. All rights reserved.

#include <iostream>
#include <stack>
#include <math.h>

int main(int argc, const char * argv[])
{
    // Variable declartion.
    long iNumber = 0;
    int iExp = 0;
    std::stack<int> binaryStack;
    std::cin >> iNumber;
    
    if (iNumber == -1)
        return 0;
    
    // Reverse binary value of input integer.
    while (iNumber > 1) {
        
        if (iNumber%2 == 0)
            binaryStack.push(0);
        else if (iNumber%2 == 1)
            binaryStack.push(1);
        
        iNumber/=2;
    }
    binaryStack.push(1);
    
    // Calculate reverse input integer.
    long iNumberResult = 0;
    while (!binaryStack.empty())
    {
        if (binaryStack.top()) {
            iNumberResult += powl(2, iExp);
        }
        
        iExp++;
        binaryStack.pop();
    }
    
    std::cout<<iNumberResult;
}
