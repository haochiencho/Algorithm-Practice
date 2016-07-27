//
//  bit.cpp
//  introductionToAlgorithmCormen
//
//  Created by Brian Cho on 7/27/16.
//  Copyright © 2016 Cho. All rights reserved.
//

#define INT_MAX 2147483647
#define INT_MIN -2147483648

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;


// given a string of 1's and 0's, output the longest chain of 1's flipping at most one bit
// e.g. input 110001111011
// output 7

int longestChain(string input){
    int curChain = 0;
    int prevChain = 0;
    int longestChain = 0;
    bool firstZero = false;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == '1')
            curChain++;
        if(input[i] == '0'){
            curChain -= prevChain;
            prevChain = curChain;
            curChain++;
            if(firstZero)
                curChain--;
            firstZero = true;
            if(input[i - 1] == '0'){
                prevChain = 0;
                curChain = 0;
            }
        }
        if(curChain > longestChain)
            longestChain = curChain;
    }
    return longestChain;
}


int main(int argc, char* argv[]){
    cout << "hello world";
}
