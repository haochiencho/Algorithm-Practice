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

bool isPerm(string a, string b){  // is permutation
    if(a.length() != b.length())
        return false;
    vector<int> vect(256, 0);
    for(int i = 0; i < a.length(); i++){
        vect[a[i]]++;
    }
    for(int i = 0; i < b.length(); i++){
        vect[b[i]]--;
    }
    for(int i = 0; i < 256; i++){
        if(vect[i] != 0)
            return false;
    }
    return true;
}

string replaceSpace(string a){ // replace spaces with %20
    for(int i = a.length() - 1; i >= 0; i--){
        if(a[i] == ' ') // removes spaces at the end
            a[i] = '\0';
        else
            break;
    }
    string* output = new string;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == ' ')
            output->append("%20");
        else{
            string temp;
            temp += a[i];
            output->append(temp);
        }
    }
    return *output;
}

bool isPalindrome(string a){ // is a word or phrase a palindrome
    vector<int> vect(128, 0);
    int spaceCount = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == ' '){
            spaceCount++;
            continue;
        }
        if(vect[a[i]] == 0)
            vect[a[i]] = 1;
        else
            vect[a[i]] = 0;
    }
    int sum = 0;
    for(int i = 0; i < 128; i++){
        sum += vect[i];
    }
    if(sum > 1)
        return false;
    else if(sum == 1 && (a.length() - spaceCount) % 2 == 0)
        return false;
    else
        return true;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string a = "aba cc";
    string b = "aabc";
    std::cout << isPalindrome(a);
    return 0;
}
