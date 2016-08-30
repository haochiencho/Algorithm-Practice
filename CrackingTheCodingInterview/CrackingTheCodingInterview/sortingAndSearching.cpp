//
//  sortingAndSearching.cpp
//  introductionToAlgorithmCormen
//
//  Created by Brian Cho on 8/30/16.
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

// Given to 2 sorted arrays merge them into a single sorted array

vector<int> merge(vector<int> A, vector<int> B){
    vector<int> output;
    int i = 0;
    int j = 0;
    while(i + j < (A.size() + B.size())){
        if(i >= A.size()){
            output.push_back(B[j]);
            j++;
            continue;
        }
        if(j >= B.size()){
            output.push_back(A[i]);
            i++;
            continue;
        }
        if(A[i] > B[j]){
            output.push_back(B[j]);
            j++;
        }
        else{
            output.push_back(A[i]);
            i++;
        }
    }
    return output;
}

// given a vector of string, place all anagrams next to each other

bool isAnagram(string A, string B){
    if(A.length() != B.length())
        return false;
    vector<int> hashA(26, 0);
    vector<int> hashB(26, 0);
    for(int i = 0; i < A.length(); i++){
        hashA[A[i] - 'a']++;
        hashB[B[i] = 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(hashA[i] != hashB[i])
            return false;
    }
    return true;
}

void anagram(vector<string> & vect){
    for(int i = 1; vect.size(); i++){
        for(int j = 0; j < i; j++){
            if(isAnagram(vect[i], vect[j])){
                vect.insert(vect.begin() + j, vect[i]);
                vect.erase(vect.begin() + i);
                break;
            }
        }
    }
}


int main(int argc, char* argv[]){

    int arr1[] = {1, 3, 5};
    int arr2[] = {1, 2, 4, 6};
    vector<int> A(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> B(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> temp = merge(A, B);
    
}
