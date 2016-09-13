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

int main(int argc, char* argv[]){
    int a = 5;
    int b = 9;
    swap(a, b);
    intersect(0, 0, 1, 1, 2, 0, 1, 1);
}
