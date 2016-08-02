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


// given two integers (N, M) and two positions (i, j) insert M starting at ith to jth

int insertPos(int N, int M, int i, int j){
    int mask = 0;
    for(int k = i; k <= j; k++){
        mask |= 1 << k;
    }
    M <<= i;
    M &= mask;
    N &= ~mask;
    N |= M;
    return N;
}

// check if a double can be represented as a float


/*
string CharToBits(char input){
    string* result = new string;
    for(int i = 0; i < sizeof(input) * 4; i++){
        string temp = "";
        temp += input & (1 << i);
        result->append(temp);
    }
    return *result;
}

bool canRepresent(double input){
    union {
        double val;
        char charRep[sizeof(double)];
    };
    val = input;
    string* stringInput = new string;
    for(int i = 0; i < sizeof(double); i++){
        stringInput->append(CharToBits(charRep[i]));
    }
    int expMask = 0;
    for(int i = 1; i <= 11; i++){
        expMask |= 0X8000 >> i;
    }
    

    return 1;
}
 */


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

// given the an integer print the next smallest and largest integer with the same number of 1s in its representation

void nextInt(int input){
    int firstOne = -1;
    int firstZero = -1;
    int secondOne = -1;
    int secondZero = -1;
    for(int i = 0; i < 32; i++){
        if((1 << i) & input)
        {
            if(firstOne != -1)
                firstOne = i;
            if(firstZero != -1 && secondOne == -1)
                secondOne = i;
        }
        else{
            if(firstZero != -1)
                firstZero = i;
            if(firstOne != -1 && secondZero == -1)
                secondZero = i;
        }
    }
    int nextInt = input;
    int prevInt = input;
    nextInt |= 1 << secondZero;
    nextInt &= (1 << (secondZero - 1));
    cout << nextInt;
    prevInt |= 1 << secondOne;
    prevInt &= (1 << (secondOne - 1));
}

int main(int argc, char* argv[]){
    cout << "hello world";
}
