//
//  main.cpp
//  CrackingTheCodingInterview
//
//  Created by Brian Cho on 6/27/16.
//  Copyright © 2016 Cho. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// # 1

bool isUnique(string word){
    string prevChars = "";
    string temp;
    for(int i = 0; i < word.length(); i++){
        for(int j = 0; j < prevChars.length(); j++){
            if(prevChars[j] == word[i])
                return false;
        }
        temp = word.substr(i, 1);
        prevChars.append(temp);
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string a = "abca";
    std::cout << isUnique(a);
    return 0;
}
