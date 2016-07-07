//
//  codeforce361.cpp
//  debugger
//
//  Created by Brian Cho on 7/6/16.
//  Copyright © 2016 Cho. All rights reserved.
//

#define INT_MAX 2147483647
#define INT_MIN -2147483648

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


bool isValid(vector<string> keyPad, int dir){ // 0 up, 1 right, 2 down, 3 left
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 3; j++){
            switch(dir){
                case 0:
                    if(keyPad[i][j] == '1' && keyPad[i - 1][j] == 'x'){
                        return false;
                    }
                    break;
                case 1:
                    if(keyPad[i][j] == '1' && keyPad[i][j + 1] == 'x'){
                        return false;
                    }
                    break;
                case 2:
                    if(keyPad[i][j] == '1' && keyPad[i + 1][j] == 'x'){
                        return false;
                    }
                    break;
                case 3:
                    if(keyPad[i][j] == '1' && keyPad[i][j - 1] == 'x'){
                        return false;
                    }
                    break;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]){
    int n;
    cin >> n;
    vector<int> vect;
    for(int i = 0; i < n; i++){
        char temp;
        cin >> temp;
        int temp1 = temp - '0';
        vect.push_back(temp1);
    }
    string temp = "xxxxx";
    vector<string> keyPad;
    keyPad.push_back(temp);
    for(int i = 0; i < 3; i++){
        temp = "x000x";
        keyPad.push_back(temp);
    }
    temp = "xx0xx";
    keyPad.push_back(temp);
    temp = "xxxxx";
    keyPad.push_back(temp);
    
    for(int i = 0; i < vect.size(); i++){
        switch(vect[i]){
            case 0:
                keyPad[4][2] = '1';
                break;
            case 1:
                keyPad[1][1] = '1';
                break;
            case 2:
                keyPad[1][2] = '1';
                break;
            case 3:
                keyPad[1][3] = '1';
                break;
            case 4:
                keyPad[2][1] = '1';
                break;
            case 5:
                keyPad[2][2] = '1';
                break;
            case 6:
                keyPad[2][3] = '1';
                break;
            case 7:
                keyPad[3][1] = '1';
                break;
            case 8:
                keyPad[3][2] = '1';
                break;
            case 9:
                keyPad[3][3] = '1';
                break;
            default:
                break;
        }
    }
    if(isValid(keyPad, 0) || isValid(keyPad, 1) || isValid(keyPad, 2) || isValid(keyPad, 3)){
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
    
}
