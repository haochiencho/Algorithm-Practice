//
//  treesAndGraphs.cpp
//  introductionToAlgorithmCormen
//
//  Created by Brian Cho on 7/12/16.
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
        int temp = stack.top();
        stack.pop();
        if(temp == end)
            return true;
        for(int i = 0; i < 5; i++){
            if(adjMatrix[temp][i] == 1){
                if(arr[i] == 0)
                    stack.push(i);
            }
        }
    }
    return false;
}

// given an array of sorted (increasing) unique integers, create a balanced binary tree

struct treeNode{
    int val;
    int height;
    treeNode* left;
    treeNode* right;
};

treeNode* binaryTree(int arr[], int start, int end, treeNode *&head){
    int mid = (start + end) / 2;
    treeNode* ptr = new treeNode;
    ptr->left = nullptr;
    ptr->right = nullptr;
    ptr->val = arr[mid];
    head = ptr;
    
    if(start == end)
        return ptr;
    
    if(start != mid)
        binaryTree(arr, start, mid - 1, head->left);
    binaryTree(arr, mid + 1, end, head->right);
    return head;
    
}

// given a balanced binary tree. create a linked list for each depth.



struct linkNode{
    int val;
    linkNode* next;
};

class linkList{
public:
    void insert(int val);
private:
    linkNode* head;
};

void linkList::insert(int val){
    linkNode* ptr = new linkNode;
    if(head == nullptr)
        head = ptr;
    linkNode* nodePtr = head;
    while(nodePtr->next != nullptr){
        nodePtr = nodePtr->next;
    }
    nodePtr->next = ptr;
    
}

vector<linkList*> binaryTreeDepth(treeNode* root){ // use Breadth First Search to create a linked list for each depth
    queue<treeNode*> myQueue;
    myQueue.push(root);
    int curHeight = -1;
    linkList* ptr;
    vector<linkList*> output;
    while(!myQueue.empty()){
        treeNode* temp = myQueue.front();
        if(temp->height != curHeight){
            curHeight = temp->height;
            output.push_back(ptr);
            ptr = new linkList;
            
        }
        if(temp->left != nullptr)
            myQueue.push(temp->left);
        if(temp->right != nullptr)
            myQueue.push(temp->right);
        ptr->insert(temp->val);
    }
    return output;
}

// check if a binary tree is balanced

bool isBalanced(treeNode* root){
    if(root == nullptr)
        return true;
    int curLevel = 0;
    int nullLevel;
    bool isNull = false;
    treeNode* ptr = root;
    queue<treeNode*> myQueue;
    myQueue.push(root);
    myQueue.push(nullptr);
    while(1){
        if(isNull && (curLevel - nullLevel > 0)){
            return false;
        }
        while(!myQueue.empty()){
            treeNode* temp = myQueue.front();
            myQueue.pop();
            if(temp == nullptr)
                break;
            if(temp->left != nullptr)
                myQueue.push(temp->left);
            else if(!isNull){
                nullLevel = curLevel + 1;
                isNull = true;
            }
            if(temp->right != nullptr)
                myQueue.push(temp->left);
            else if(!isNull){
                nullLevel = curLevel + 1;
                isNull = true;
            }
        }
        if(myQueue.empty())
            return true;
        myQueue.push(nullptr);
        curLevel++;
    }
    
}

bool isValid(treeNode* root){ // return true if tree is a valid binary search tree
    if(root == nullptr)
        return true;
    if(root->left != nullptr && root->val < root->left->val)
        return false;
    if(root->right != nullptr && root->val > root->right->val)
        return false;
    if(isValid(root->left) && isValid(root->right))
        return true;
    else
        return false;
}


// given a list of dependecies, output an order that nodes can be traversed

// {1, 2, 3, 4}, {1, 2}, {2, 3}
// 1 depends on 2. 2 depends on 3.

vector<int> listDependecies(vector<vector<int> > vect){
    vector<int> arr(vect.size(), 0);
    map<int, int> myMap;
    for(int i = 0; i < vect[0].size(); i++){
        myMap[vect[0][i]] = i;
    }
    for(int i = 1; i < vect.size(); i++){
        arr[myMap[vect[i][0]]]++;
    }
    queue<int> myQueue;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0){
            myQueue.push(i);
        }
    }
    vector<int> output;
    while(!myQueue.empty()){
        int temp = myQueue.front();
        myQueue.pop();
        for(int i = 1; i < vect.size(); i++){
            if(vect[i][1] == temp){
                arr[myMap[vect[i][0]]]--;
                if(arr[myMap[vect[i][0]]] == 0)
                    myQueue.push(vect[i][0]);
            }
        }
        output.push_back(temp);
    }
    return output;
}

// find the first common ancestor, given two tree nodes

bool findNode(treeNode* head, treeNode* node){
    if(head == node)
        return true;
    if(head == nullptr)
        return false;
    if(findNode(head->right, node) || findNode(head->left, node))
        return true;
    else
        return false;
}

treeNode* commonAncestor(treeNode* A, treeNode* B, treeNode* head){
    if(findNode(head, A) && findNode(head, B))
        return head;
    if(findNode(head->left, A) && head->left == B)
        return head->left;
    if(findNode(head->right, A) && head->right == B)
        return head->right;
    if(head->left != nullptr)
        return commonAncestor(A, B, head->left);
    if(head->right != nullptr)
        return commonAncestor(A, B, head->right);
    return nullptr;
}

// given an binary search tree. Print all possible orders that they could have been inserted

vector<string> printPossibleOrder(treeNode* head){
    string* output = new string;
    vector<string> result;
    if(head->left == nullptr && head->right == nullptr){
        output->append(to_string(head->val));
        result.push_back(*output);
        return result;
    }
    vector<string> left;
    vector<string> right;
    if(head->left != nullptr)
        left = printPossibleOrder(head->left);
    if(head->right != nullptr)
        right = printPossibleOrder(head->right);
    return combineTwoVectString(left, right, to_string(head->val)); // returns a list of all possible orders recursively
    
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
    bool isTrue = pathExist(1, 4, adjMatrix);
    int arr[6] = {0, 1, 2, 3, 4, 5};
    treeNode* head;
    treeNode* ptr = binaryTree(arr, 0, 4, head);
    
    cout << "hello world";
}
