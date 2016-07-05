//
//  binarySearchTree.cpp
//  introductionToAlgorithmCormen
//
//  Created by Brian Cho on 7/4/16.
//  Copyright © 2016 Cho. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree{ // without balancing
public:
    Node* getRoot(){
        return root;
    }
    void setRoot(Node* ptr){
        root = ptr;
    }
    void insertValue(int value);
    void deleteValue(int value);
    Node* findValue(int value);
    
    
private:
    Node* root;
};

void BinarySearchTree::insertValue(int value){
    Node* nodePtr = new Node;
    nodePtr->value = value;
    nodePtr->left = nullptr;
    nodePtr->right = nullptr;
    
    Node* itr = getRoot();
    if(root == nullptr){
        setRoot(nodePtr);
        return;
    }
    else{
        while(itr != nullptr){
            if(value > itr->value){
                if(itr->right == nullptr){
                    itr->right = nodePtr;
                    return;
                }
                itr = itr->right;
            }
            else{
                if(itr->left == nullptr){
                    itr->left = nodePtr;
                    return;
                }
                itr = itr->left;
            }
        }
    }
}



void BinarySearchTree::deleteValue(int value){
    if(root == nullptr)
        return;
    else{
        Node* itr = root;
        Node* oneBehind = root;
        while(itr != nullptr){

            Node* temp;
            if(itr != nullptr && itr->value == value && oneBehind->left == itr){
                temp = itr;
                if(temp->left == nullptr && temp->right == nullptr)
                    oneBehind->left = nullptr;
                else if(temp->left == nullptr && temp->right != nullptr)
                    oneBehind->left = temp->right;
                else if(temp->left != nullptr && temp->right == nullptr)
                    oneBehind->left = temp->left;
                else{
                    itr = temp->left;
                    while(itr->right != nullptr){
                        itr = itr->right;
                    }
                    itr->right = temp->right;
                    oneBehind->left = itr;
                }
                delete temp;
                return;
            }
            else if(itr != nullptr && itr->value == value && oneBehind->right == itr){
                temp = itr;
                if(temp->left == nullptr && temp->right == nullptr)
                    oneBehind->right = nullptr;
                else if(temp->left == nullptr && temp->right != nullptr)
                    oneBehind->right = temp->right;
                else if(temp->left != nullptr && temp->right == nullptr)
                    oneBehind->right = temp->left;
                else{
                    itr = temp->left;
                    while(itr->right != nullptr){
                        itr = itr->right;
                    }
                    itr->right = temp->right;
                    oneBehind->right = itr;
                }
                delete temp;
                return;
            }
            oneBehind = itr;
            if(value < itr->value)
                itr = itr->left;
            else
                itr = itr->right;
        }
    }
    return;
}

int main(int argc, char* argv[]){
    BinarySearchTree* ptr = new BinarySearchTree;
    ptr->insertValue(2);
    ptr->insertValue(1);
    ptr->insertValue(3);
    ptr->insertValue(3);
    ptr->insertValue(5);
    ptr->deleteValue(3);
    
    cout << "hello world";
}