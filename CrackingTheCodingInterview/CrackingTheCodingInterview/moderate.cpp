//
//  moderate.cpp
//  introductionToAlgorithmCormen
//
//  Created by Brian Cho on 9/11/16.
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
#include <pthread.h>
#include <semaphore.h>
using namespace std;

// swap two numbers without a temporary variable

void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// Design a method that find the number of occurences a word occurs in a book

struct Node{
    Node* left;
    Node* right;
    int count;
    string val;
};

class stringTree{
public:
    Node* createNode(string A);
    void insertNode(string A);
    int getCount(string A);
private:
    Node* m_head;
};

Node* stringTree::createNode(string A){
    Node* ptr = new Node;
    ptr->left = nullptr;
    ptr->right = nullptr;
    ptr->count = 1;
    ptr->val = A;
    return ptr;
}

void stringTree::insertNode(string A){
    if(m_head == nullptr){
        Node* ptr = createNode(A);
    }
    else{
        Node* ptr = m_head;
        while(ptr != nullptr){
            if(ptr->val == A)
                ptr->count++;
            else if(ptr->val < A){
                if(ptr->right == nullptr){
                    Node* temp = createNode(A);
                    ptr->right = temp;
                }
                else
                    ptr = ptr->right;
            }
            else{
                if(ptr->left == nullptr){
                    Node* temp = createNode(A);
                    ptr->left = temp;
                }
                else
                    ptr = ptr->left;
            }
        }
    }
}

int stringTree::getCount(string A){
    Node* ptr = m_head;
    while(ptr != nullptr){
        if(ptr->val == A)
            return ptr->count;
        else if(ptr->val < A)
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }
    return 0;
}

// given two lines, indicated by two points, compute the intersection of two lines (if any)

vector<int> intersect(int x1, int y1, int x2, int y2, int X1, int Y1, int X2, int Y2){
    int slope1, int1, slope2, int2;
    slope1 = (y2 - y1) / (x2 - x1);
    slope2 = (Y2 - Y1) / (X2 - X1);
    int1 = y1 - (x1 * slope1);
    int2 = Y1 - (X1 * slope2);
    vector<int> result(2);
    result[0] = (int1 - int2) / (slope2 - slope1);
    result[1] = (slope1 * result[0]) + int1;
    return result;
}

// given NxN matrix. look for N sequence of 1s

bool detectLine(vector<vector<int> > vect){
    int n = vect.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){ // check rows
            if(vect[i][j] == '0')
                break;
            if(j == n - 1)
                return true;
        }
    }
    for(int i = 0; i < n; i++){ // check cols
        for(int j = 0; j < n; j++){
            if(vect[j][i] == '0')
                break;
            if(j == n - 1)
                return true;
        }
    }
    for(int i = 0; i < n; i++){ // check diagonals
        if(vect[i][i] == '0')
            break;
        if(i == n - 1)
            return true;
    }
    for(int i = 0; i < n; i++){
        if(vect[i][n - i - 1] == '0')
            break;
        if(i == n - 1)
            return true;
    }
    return false;
}

// number of trailing zeroes in n factorial

int numZeroes(int factorial){
    int count = 0;
    int numInc = 0;
    int remain;
    for(int i = 5; i <= factorial; i += 5){
        remain = i;
        numInc = 0;
        while(remain % 5 == 0){
            numInc++;
            remain /= 5;
        }
        count += numInc;
    }
    return count;
}

// given two vectors of integers output the pair with the smallest difference

vector<int> sort(vector<int> vect, int start, int end){
    vector<int> temp;
    if(start >= end){
        temp.push_back(vect[start]);
        return temp;
    }
    int mid;
    mid = (start + end) / 2;
    vector<int> left = sort(vect, start, mid);
    vector<int> right = sort(vect, mid + 1, end);
    int i, j;
    i = 0;
    j = 0;
    while(i + j < left.size() + right.size()){
        if(i >= left.size()){
            temp.push_back(right[j]);
            j++;
            continue;
        }
        if(j >= right.size()){
            temp.push_back(left[i]);
            i++;
            continue;
        }
        if(left[i] > right[j])
            temp.push_back(right[i]);
        else
            temp.push_back(left[i]);
    }
    return temp;
}

int abs(int a, int b){
    if(a > b)
        return a - b;
    else
        return b - a;
}

vector<int> smallestPair(vector<int> A, vector<int> B){
    vector<int> sortedA = sort(A, 0, A.size() - 1);
    vector<int> sortedB = sort(B, 0 , B.size() - 1);
    vector<int> result(2);
    int curMin = INT_MAX;
    int i, j;
    i = 0;
    j = 0;
    while(i < sortedA.size() && j < sortedB.size()){
        if(abs(sortedA[i], sortedB[j]) > curMin){
            curMin = abs(sortedA[i], sortedB[j]);
            result[0] = sortedA[i];
            result[1] = sortedB[j];
        }
        if(sortedA[i] > sortedB[j])
            j++;
        else
            i++;
    }
    return result;
}

int main(int argc, char* argv[]){
    int a = 5;
    int b = 9;
    swap(a, b);
    intersect(0, 0, 1, 1, 2, 0, 1, 1);
    numZeroes(30);
    
}
