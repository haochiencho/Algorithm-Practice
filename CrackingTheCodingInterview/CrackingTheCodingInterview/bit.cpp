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
            if(firstOne == -1)
                firstOne = i;
            if(firstZero != -1 && secondOne == -1)
                secondOne = i;
        }
        else{
            if(firstZero == -1)
                firstZero = i;
            if(firstOne != -1 && secondZero == -1)
                secondZero = i;
        }
    }
    int nextInt = input;
    int prevInt = input;
    nextInt |= 1 << secondZero;
    nextInt &= ~(1 << (secondZero - 1));
    cout << nextInt << endl;
    prevInt &= ~(1 << secondOne);
    prevInt |= 1 << (secondOne - 1);
    cout << prevInt << endl;
}

// change from 2's complement to 1's complement representation

// (n & (n - 1) == 0.
// this statement only holds true for values of 2, 1, 0.

// given two integers, output the number of bits that must be flipped to make one equal the other.

int numBits(int A, int B){
    int count = 0;
    for(int i = 0; i < 32; i++){
        if(((1 << i) & A) != ((1 << i) & B))
            count++;
    }
    return count;
}

// pairwise swap: given an integer swap all even with all odd bits
void pairWiseSwap(int &input){
    int leftShift = input << 1;
    int rightShift = input >> 1;
    int mask;
    for(int i = 0; i < 32; i++){
        mask = 1 << i;
        if(i % 2 == 0)
            input = ((~mask) & input) | (rightShift & mask);
        else
            input = ((~mask) & input) | (leftShift & mask);
    }
}

// A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to be stored in one byte.
// Implement a function that draws a horizontal line from (x1, y) to (x2, y)

void drawLine(char* screen, int width, int x1, int x2, int y){
    // let 0 value to equal a horizontal line
    char* temp = &screen[y];
    for(int i = 0; i < x1 / 8; i++){
        temp++;
    }
    for(int i = x1 % 8; i < 8; i++){
        char mask = 1 << i;
        int a = (~mask & (*temp));
        char b = a;
        *temp = b;
    }
    temp++;
    int start, end;
    start += 8 - (x1 % 8);
    end -= x2 % 8;
    for(int i = (end - start) / 8; i > 0; i--){
        *temp = '0';
        temp++;
    }
    
    for(int i = 0; i <= x2 % 8; i++){
        char mask = 1 << i;
        int a = (~mask & (*temp));
        char b = a;
        *temp = b;
    }
}

int main(int argc, char* argv[]){
    int a = 11;
    int b = 13;
    pairWiseSwap(b);
    cout << a;
    char screen[] = "hello";
    drawLine(screen, 5, 5, 5, 5);
}
