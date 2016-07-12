//
//  treesAndGraphs.cpp
//  introductionToAlgorithmCormen
//
//  Created by Brian Cho on 7/11/16.
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


// given a directed graph find if there is a path from node a to b

struct Node{
    int id;
    int* children; // map translates integers to Nodes
    int numChildren;
};

class graph{
public:
    void addNodes(int* adjMatrix[], vector<Node*> nodes, int size);
private:
    int** matrix;
    
};

void graph::addNodes(int* adjMatrix[], vector<Node*> nodes, int size){ // includes nodes and their children
    for(int i = 0; i < size; i++){
        int* arr = nodes[i]->children;
        for(int j = 0; j < nodes[i]->numChildren; j++){
            adjMatrix[i][arr[j]] = 1;
        }
    }
    matrix = adjMatrix;
}


bool pathExist(int start, int end, int* adjMatrix[]){ // Depth first search
    stack<int> stack;
    stack.push(start);
    int* arr = new int[5];
    for(int i = 0; i < 5; i++){
        arr[i] = 0;
    }
    arr[start] = 1;
    while(!stack.empty()){
        if(stack.top() == end)
            return true;
        for(int i = 0; i < 5; i++){
            if(adjMatrix[stack.top()][i] == 1){
                if(arr[i] == 0)
                    stack.push(i);
            }
        }
        stack.pop();
    }
    return false;
}

int main(int argc, char* argv[]){
    int** adjMatrix;
    adjMatrix = new int *[5];
    for(int i = 0; i < 5; i++)
        adjMatrix[i] = new int [5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            adjMatrix[i][j] = 0;
        }
    }
    vector<Node*> vect;
    for(int i = 0; i < 5; i++){ // creates five nodes
        Node* temp = new Node;
        temp->id = i;
        int* arr = new int[5];
        temp->children = arr;
        vect.push_back(temp);
    }
    vect[0]->numChildren = 0;
    
    vect[1]->numChildren = 2;
    vect[1]->children[0] = 0;
    vect[1]->children[1] = 2;
    
    vect[2]->numChildren = 1;
    vect[2]->children[0] = 3;
    
    vect[3]->numChildren = 1;
    vect[3]->children[0] = 4;
    
    vect[4]->numChildren = 0;
    
    graph* graphObj = new graph;
    
    
    graphObj->addNodes(adjMatrix, vect, 5);
    int temp = adjMatrix[1][2];
    
    cout << "hello world";
}
