//
//  codeforces362.cpp
//  codeforces
//
//  Created by Brian Cho on 7/14/16.
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
#include <algorithm>
using namespace std;




/*
int main(int argc, char* argv[]){
    int t, s, x;
    cin >> t >> s >> x;
    int temp = (x - t) % s;
    if(x < t){
        cout << "NO";
        return 0;
    }
    bool isFirst = false;
    if(x - t == 1)
        isFirst = true;
    if((temp == 0 || temp == 1) && (!isFirst))
        cout << "YES";
    else
        cout << "NO";
}
*/

int main(int argc, char* argv[]){
    string input;
    cin >> input;
    bool isDecimal = false;
    int pos;
    for(int i = 0; i < 2; i++){
        pos = i;
        if(input[i] == '.'){
            isDecimal = true;
            break;
        }
    }
    
    if(input[0] == '0' && (!isDecimal)){
        cout << "0";
        return 0;
    }
    string* expString = new string;
    while(1){
        if(input[input.length() - 1] == 'e'){
            input.pop_back();
            break;
        }
        expString->insert(0, input.substr(input.length() - 1, 1));
        input.pop_back();
    }
     int exp = atoi(expString->c_str());

    
    
    if(isDecimal){
    for(int i = pos; i < pos + exp; i++){
            if(input.length() - 2 == i){
                input[i] = input[i + 1];
                input.pop_back();
                continue;
            }
            else if(input.length() <= i){
                input.append("0");
                continue;
            }
            input[i] = input[i + 1];
        }
        if(pos + exp < input.length() - 1)
            input[pos + exp] = '.';
        isDecimal = false;
        for(int i = 0; i < input.length(); i++){
            pos = i;
            if(input[i] == '.'){
                isDecimal = true;
                break;
            }
        }
        if(isDecimal){
            while(1){
                if(input[input.length() - 1] == '0')
                    input.pop_back();
                else if(input[input.length() - 1] == '.'){
                    input.pop_back();
                    break;
                }
                else
                    break;
            }
        }
    }
    else{
        for(int i = 0; i < exp; i++){
            input.append("0");
        }
    }
    cout << input;
}