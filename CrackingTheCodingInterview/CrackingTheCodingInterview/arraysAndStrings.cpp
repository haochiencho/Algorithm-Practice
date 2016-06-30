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
#include <stdio.h>
#include <stdlib.h>
using namespace std;


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

unsigned int min(unsigned int a, unsigned int b){
    if(a > b)
        return b;
    else
        return a;
}

bool isOneEditDistance(string a, string b){ // checks if the two strings are one edit distance from each other
    if((int)a.length() - (int)b.length() < -1 || (int)a.length() - (int)b.length() > 1)
        return false;
    bool firstEdit = false;
    int Ashift = 0;
    int Bshift = 0;
    for(int i = 0; i < min(a.length(), b.length()); i++){
        if(a[i + Ashift] != b[i + Bshift]){
            if(firstEdit)
                return false;
            else{
                if(a.length() == b.length()){
                    firstEdit = true;
                    continue;
                }
                else if(a.length() > b.length())
                    Ashift++;
                else
                    Bshift++;
                firstEdit = true;
            }
        }
    }
    return true;
}

string compressString(string a){ // compress string aaabbc to a3b2c1
    string *output = new string;
    if(a.length() == 0)
        return *output;
    
    char temp = a[0];
    int count = 1;
    string tempHolder = "";
    string countHolder;
    for(int i = 1; i < a.length(); i++){
        if(temp == a[i])
            count++;
        else{
            temp = a[i - 1];
            tempHolder += temp;
            output->append(tempHolder);
            countHolder = to_string(count);
            output->append(countHolder);
            count = 1;
            tempHolder.clear();
            temp = a[i];
        }
    }
    tempHolder += a[a.length() - 1];
    output->append(tempHolder);
    countHolder = to_string(count);
    output->append(countHolder);
    return *output;
}

void rotateMatrix(vector<vector<char> > & vect){ // rotate N x N matrix by 90 degrees
    for(int i = 0; i < vect.size() / 2; i++){
        for(int j = i; j < vect.size() - i - 1; j++){
            char temp = vect[i][j];
            vect[i][j] = vect[vect.size() - j - 1][i];
            vect[vect.size() - j - 1][i] = vect[vect.size() - i - 1][vect.size() - j - 1];
            vect[vect.size() - i - 1][vect.size() - j - 1] = vect[j][vect.size() - i - 1];
            vect[j][vect.size() - i - 1] = temp;
            
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string a = "";
    string b = "abaa c";
    vector<vector<char> > vect;
    for(int i = 0; i < 5; i++){
        vector<char> temp;
        for(int j = 0; j < 5; j++)
            temp.push_back(static_cast<char>(j));
        vect.push_back(temp);
    }
    rotateMatrix(vect);
    return 0;
}
