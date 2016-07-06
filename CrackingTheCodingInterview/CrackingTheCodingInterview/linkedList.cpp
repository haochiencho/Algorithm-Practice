//
//  binarySearchTree.cpp
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
using namespace std;


struct Node{
    Node* next;
    Node* prev;
    int val;
    Node(int value) :
    val(value){
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList{ // singly linked list
public:
    LinkedList(){
        m_head = nullptr;
        m_tail = nullptr;
    }
    Node* getHead(void);
    void setHead(Node* head);
    Node* getTail(void);
    void setTail(Node* tail);
    void deleteNode(Node* ptr, LinkedList & list);
    void insert(int val, LinkedList & list);
    Node* find(int val, LinkedList list);

private:
    Node* m_head;
    Node* m_tail;
};

Node* LinkedList::getHead(void){
    return m_head;
}

void LinkedList::setHead(Node* head){
    m_head = head;
}

Node* LinkedList::getTail(void){
    return m_tail;
}

void LinkedList::setTail(Node* tail){
    m_tail = tail;
}


void LinkedList::deleteNode(Node* ptr, LinkedList & list){
    if(ptr == nullptr || list.getHead() == nullptr)
        return;
    if(list.getHead() == list.getTail()){ // only one element
        delete ptr;
        list.setHead(nullptr);
    }
    else if(ptr == list.getHead()){ // delete head
        ptr->next->prev = nullptr;
        list.setHead(ptr->next);
        delete ptr;
    }
    else if(ptr == list.getTail()){
        ptr->prev->next = nullptr;
        list.setTail(ptr->prev);
        delete ptr;
    }
    else{
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
    }
    
}

void LinkedList::insert(int val, LinkedList & list){
    Node* node = new Node(val);
    if(list.getHead() == nullptr){ // empty list
        list.setHead(node);
        list.setTail(node);
    }
    else{
        list.getTail()->next = node;
        node->prev = list.getTail();
        list.setTail(node);
    }
}

Node* LinkedList::find(int val, LinkedList list){ // returns first occurence
    if(list.getHead() == nullptr)
        return nullptr;
    Node* ptr = list.getHead();
    while(ptr != nullptr){
        if(ptr->val == val)
            return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

void removeDupWithHash(LinkedList & list){
    Node* ptr = list.getHead();
    long size = ((long)INT_MAX - (long)INT_MIN) + 1;
    vector<int> hash(100, 0);
    while(ptr != nullptr){
        if(hash[ptr->val] >= 1){
            list.deleteNode(ptr, list);
        }
        hash[ptr->val]++;
        ptr = ptr->next;
    }
}

void removeDup(LinkedList & list){ // remove duplicates without buffer
    Node* ptr = list.getHead();
    while(ptr != nullptr){
        Node* ptr2 = ptr->next;
        while(ptr2 != nullptr){
            if(ptr->val == ptr2->val){
                Node* temp = ptr2;
                ptr2 = ptr2->next;
                list.deleteNode(temp, list);
                continue;
            }
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
    }
}

Node* kthToLast(int k, LinkedList list){ // return the kth to last element
    if(list.getHead() == nullptr)
        return nullptr;
    Node* ptr = list.getHead();
    int counter = k - 1;
    Node* tracePtr = nullptr;
    while(ptr != nullptr){
        if(tracePtr != nullptr)
            tracePtr = tracePtr->next;
        if(counter == 0){
            tracePtr = list.getHead();
        }
        counter--;
        ptr = ptr->next;
    }
    return tracePtr;
}

void deleteMiddleNode(LinkedList & list){ // delete the node in the middle
    Node* ptr = list.getHead();
    Node* runner = list.getHead();
    while(runner != nullptr){
        if(runner != list.getHead())
            ptr = ptr->next;
        runner = runner->next;
        if(runner != nullptr)
            runner = runner->next;
    }
    list.deleteNode(ptr, list);
}

int main(int argc, char* argv[]){

    LinkedList list;
    list.insert(2, list);
    list.insert(2, list);
    list.insert(3, list);
    list.insert(1, list);
    list.insert(1, list);
    deleteMiddleNode(list);
    
    cout << "hello world";
}
