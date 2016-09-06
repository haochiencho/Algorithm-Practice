//
//  c++.cpp
//  introductionToAlgorithmCormen
//
//  Created by Brian Cho on 9/5/16.
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
#include <fstream>
#include <sstream>
using namespace std;

// print out the last K lines of a file

void printLines(string fileName, int k){
    ifstream fin(fileName);
    string line;
    queue<string> result;
    while(getline(fin, line)){
        istringstream iss(line);
        if(result.size() < k)
            result.push(line);
        else{
            result.pop();
            result.push(line);
        }
    }
    while(!result.empty()){
        cout << result.front() << endl;
        result.pop();
    }
}

// reversing a null terminal character array

void reverseString(char* charString){
    int counter = 0;
    while(1){
        if(charString[counter] == '\0')
            break;
    }
    for(int i = 0; i < counter / 2; i++){
        char temp = charString[i];
        charString[i] = charString[counter - i - 1];
        charString[counter - i - 1] = temp;
    }
}

int main(int argc, char* argv[]){
}
