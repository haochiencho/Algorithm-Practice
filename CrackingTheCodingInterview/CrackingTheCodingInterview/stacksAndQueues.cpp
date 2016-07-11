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

// implement a single stack with multiple stacks (each with a limited size)

class multStack{
public:
    multStack(int max){
        m_max = max;
    }
    void push(int val);
    void pop();
    int top();
private:
    int m_max;
    vector<stack<int> > vect;
};

void multStack::push(int val){
    if(vect.size() == 0){
        stack<int> temp;
        vect.push_back(temp);
    }
    if(vect[vect.size() - 1].size() >= m_max){
        stack<int> temp;
        temp.push(val);
        vect.push_back(temp);
    }
    else
        vect[vect.size() - 1].push(val);
}

void multStack::pop(){
    if(vect.size() == 0)
        return;
    if(vect[vect.size() - 1].size() <= 1)
        vect.erase(vect.begin() + vect.size() - 1);
    else
        vect[vect.size() - 1].pop();
}

int multStack::top(){
    return vect[vect.size() - 1].top();
}

// implement a queue using two stacks

class myQueue{
public:
    void push(int val);
    int top(void);
    void pop(void);
private:
    stack<int> first;
    stack<int> second;
};

void myQueue::push(int val){
    while(!first.empty()){
        second.push(first.top());
        first.pop();
    }
    first.push(val);
    while(!second.empty()){
        first.push(second.top());
        second.pop();
    }
}

int myQueue::top(void){
    return first.top();
}

void myQueue::pop(void){
    if(!first.empty()){
        first.pop();
    }
}

// using one stack as a temporary buffer sort a stack of integers and store it in the same stack

void sortStack(stack<int> & myStack){ // bubble sort
    stack<int> tempBuf;
    bool isChange = true;
    while(isChange){
        isChange = false;
        if(!myStack.empty()){
            int temp = myStack.top();
            myStack.pop();
            if(!myStack.empty()){
                if(temp <= myStack.top()){
                    tempBuf.push(temp);
                }
                else{
                    tempBuf.push(myStack.top());
                    myStack.pop();
                    myStack.push(temp);
                }
            }
            else
                tempBuf.push(temp);
            isChange = true;
        }
        else{
            while(!tempBuf.empty()){
                myStack.push(tempBuf.top());
                tempBuf.pop();
            }
        }
    }
}

// adopting cats and dogs. The rule is to adopt the oldest animal. Implement three function adoptAny, adoptDog, adoptCat

int adoptAny(queue<int> cat, queue<int> dog){ // int represents the animal
    int temp;
    if(cat.empty() && dog.empty())
        return -1;
    else if(cat.empty()){
        temp = dog.front();
        dog.pop();
        return temp;
    }
    else if(dog.empty()){
        temp = cat.front();
        cat.pop();
        return temp;
    }
    else{
        if(cat.front() >= dog.front()){
            temp = cat.front();
            cat.pop();
            return temp;
        }
        else{
            temp = dog.front();
            dog.pop();
            return temp;
        }
    }
}

int adoptCat(queue<int> cat){
    int temp = cat.front();
    cat.pop();
    return temp;
}

int adoptDog(queue<int> dog){
    int temp = dog.front();
    dog.pop();
    return temp;
}

int main(int argc, char* argv[]){
    myStack* stackObj = new myStack;
    stackObj->push(2);
    stackObj->push(3);
    stackObj->push(1);
    stackObj->push(4);
    stackObj->pop();
    int temp = stackObj->min();
    stack<int> newStack;
    newStack.push(1);
    
    multStack* obj = new multStack(3);
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->pop();
    obj->pop();
    
    myQueue* queue = new myQueue;
    queue->push(1);
    queue->push(2);
    temp = queue->top();
    
    stack<int> input;
    input.push(2);
    input.push(1);
    input.push(3);
    sortStack(input);
    
    cout << "hello world";
}
