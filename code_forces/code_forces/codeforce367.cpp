//
//  recursionAndDynamicProgramming.cpp
//  introductionToAlgorithmCormen
//
//  Created by Brian Cho on 8/18/16.
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
#include <math.h>
using namespace std;

/*
int main(int argc, char* argv[]){
    int r, c;
    cin >> r >> c;
    char input;
    bool isColor = false;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> input;
            if(input == 'C' || input == 'M' || input == 'Y')
                isColor = true;
        }
    }
    if(isColor)
        cout << "#Color";
    else
        cout << "#Black&White";
}
 */

/*
struct Node{
    int a;
    int b;
    int dist;
    Node* next;
};

class List{
public:
    List(){
        head = nullptr;
    }
    void addNode(int a, int b, int dist);
    Node* head;
};

void List::addNode(int a, int b, int dist){
    Node* node = new Node;
    node->a = a;
    node->b = b;
    node->dist = dist;
    node->next = nullptr;
    if(head == nullptr){
        head = node;
    }
    else{
        Node* temp;
        temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = node;
    }
}

int main(int argc, char* argv[]){
    int n, m , k;
    cin >> n >> m >> k;
    if(k == 0){
        cout << "-1";
        return 0;
    }
    
    List* input = new List;
    
    for(int i = 0; i < m; i++){
        int a, b, dist;
        cin >> a >> b >> dist;
        input->addNode(a, b, dist);
    }
    vector<bool> hash(n + 1, false);
    bool isValid = false;
    int curMin = INT_MAX;
    int bake;
    for(int i = 0; i < k; i++){
        cin >> bake;
        hash[bake] = true;
    }
    
    Node* temp = input->head;
    while(temp != nullptr){
        if(hash[temp->a] && hash[temp->b]){
            temp = temp->next;
            continue;
        }
        else if((!hash[temp->a]) && (!hash[temp->b])){
            temp = temp->next;
            continue;
        }
        else{
            if(temp->dist < curMin)
                curMin = temp->dist;
            isValid = true;
            temp = temp->next;
        }
    }
    if(isValid)
        cout << curMin;
    else
        cout << "-1";
}
*/

int main(int argc, char* argv[]){
    int n;
    cin >> n;
    double a = 2000000000;
    for(int i = 0; i < sqrt(a); i++){
        
    }
}
