//
//  stacksAndQueues.cpp
//  introductionToAlgorithmCormen
//
//  Created by Brian Cho on 7/4/16.
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
using namespace std;



class Array{ // implement an array with 2 stacks
public:
    Array(int size){
        m_size = size;
        for(int i = 0; i < size; i++){ // initialize stack with all zeroes to simulate an uninitialized array
            first.push(0);
        }
    }
    int getVal(int index); // return ith index
    void changeVal(int index, int val); // change val at ith index
private:
    int m_size;
    stack<int> first;
    stack<int> second;
};

int Array::getVal(int index){
    if(index < 0 || index >= m_size) //
        return -1;
    for(int i = 0; i < index; i++){
        second.push(first.top());
        first.pop();
    }
    int temp = first.top();
    while(!second.empty()){
        first.push(second.top());
        second.pop();
    }
    return temp;
}

void Array::changeVal(int index, int val){
    if(index < 0 || index >= m_size) //
        return;
    for(int i = 0; i < index; i++){
        second.push(first.top());
        first.pop();
    }
    first.pop();
    first.push(val);
    while(!second.empty()){
        first.push(second.top());
        second.pop();
    }
}

// create a stack that does push, pop, and min (returns the minimum value in the stack) operations in O(1)

int minOf2(int a, int b){
    if(a > b)
        return b;
    else
        return a;
}

struct Node{
    int val;
    int min; // min holds the minimum value of all nodes below (and including) the node in the stack
};

class myStack{
public:
    void push(int val);
    void pop(void);
    Node top(void);
    int min(void);
private:
    vector<Node> vect;
};

void myStack::push(int val){
    Node* ptr = new Node;
    ptr->val = val;
    if(vect.size() == 0){
        ptr->min = val;
    }
    else{
        ptr->min = minOf2(vect[vect.size() - 1].min, val);
    }
    vect.push_back(*ptr);
}

void myStack::pop(void){
    vect.erase(vect.begin() + vect.size() - 1);
}

Node myStack::top(void){
    return vect[vect.size() - 1];
}

int myStack::min(void){
    return top().min;
}

int main(int argc, char* argv[]){
    myStack* stackObj = new myStack;
    stackObj->push(2);
    stackObj->push(3);
    stackObj->push(1);
    stackObj->push(4);
    stackObj->pop();
    int temp = stackObj->min();
    cout << "hello world";
}
