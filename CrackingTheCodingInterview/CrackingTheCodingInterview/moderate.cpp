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

// return the max of two numbers without using an if else statement or any sort of comparsion operator.

int max(int A, int B){
    int dif = A - B;
    int mask = 1 << 31;
    dif &= mask; // nonzero if B > A, 0 if A >= B
    dif = dif >> 31;
    int dif2 = B - A;
    dif2 &= mask;
    dif2 = dif2 >> 31;
    int same = (!(A ^ B)) * -1;
    return (B & dif) + (A & dif2) + (same & A);
}

// print an integer in english format
// e.g. 1372 one thousand, three hundred seventy two

int countCommas(int input){
    int count = 0;
    int i = 1;
    while(i <= input){
        count++;
        i *= 1000;
    }
    return count;
}

void printNum(int digit){
    switch(digit){
        case 0:
            cout << "zero ";
            break;
        case 1:
            cout << "one ";
            break;
        case 2:
            cout << "second ";
            break;
        case 3:
            cout << "three ";
            break;
        case 4:
            cout << "four ";
            break;
        case 5:
            cout << "five ";
            break;
        case 6:
            cout << "six ";
            break;
        case 7:
            cout << "seven ";
            break;
        case 8:
            cout << "eight ";
            break;
        case 9:
            cout << "nine ";
            break;
    }
}

void print3digit(int num){
    int single, ten, hundred;
    single = num % 10;
    num /= 10;
    ten = num % 10;
    num /= 10;
    hundred = num % 10;
    printNum(hundred);
    cout << "hundred ";
    printNum(ten);
    cout << "ten ";
    printNum(single);
    
}

void printInt(int input){
    int n = countCommas(input);
    int div = 1000 * (n - 1);
    for(int i = n - 1; i >= 0; i--){
        int temp = input / div;
        temp %= 1000;
        print3digit(temp);
        div /= 1000;
    }
}

// Opertions: create multiply, divide, subtract operations on integer operands with only the addition operator

int mult2pos(int A, int B){
    int output = 0;
    if(A > B){
        for(int i = 0; i < B; i++){
            output += A;
        }
    }
    else{
        for(int i = 0; i < A; i++){
            output += B;
        }
    }
    return output;
}

void inverse(int A){
    
}

int mult(int A, int B){
    int output = 0;
    if(A == 0 || B == 0)
        return 0;
    if(A > 0 && B > 0){
        output = mult2pos(A, B);
    }
    else if(A < 0 && B > 0){
        A *= -1;
        output = mult2pos(A, B);
        output *= -1;
    }
    else if(A > 0 && B < 0){
        B *= -1;
        output = mult2pos(A, B);
        output *= -1;
    }
    else{
        A *= -1;
        B *= -1;
        output = mult2pos(A, B);
    }
    return output;
}

int sub(int A, int B){ // A - B
    return A + mult(B, -1);
}

int division(int A, int B){ // A / B
    int count = 0;
    int inc = B;
    while(B < A){
        B += inc;
        count++;
    }
    return count;
}



int main(int argc, char* argv[]){
    int a = 5;
    int b = 9;
    swap(a, b);
    intersect(0, 0, 1, 1, 2, 0, 1, 1);
    numZeroes(30);
    int c = max(15, 15);
    
}
