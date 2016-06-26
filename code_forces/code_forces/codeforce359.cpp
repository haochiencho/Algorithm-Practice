//
//  codeforces 359.cpp
//  code_forces
//
//  Created by Brian Cho on 6/23/16.
//  Copyright © 2016 Cho. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>


/* A
int main(int argc, const char * argv[]){
    int n;
    long long x;
    std::cin >> n >> x;
    char plusMinus;
    int counter = 0;
    long long temp;
    for(int i = 0; i < n; i++){
        std::cin >> plusMinus;
        std::cin >> temp;
        if(plusMinus == '-' && temp > x)
            counter++;
        else if(plusMinus == '-'){
            x -= temp;
        }
        else
            x += temp;
            
    }
    
    
    
    std::cout << x << " " << counter << std::endl;
    return 0;
    
}

*/

/* B

void animalSort(std::vector<int> & vect, int start, int end){
    std::cout << start << " " << end << std::endl;
    int temp;
    for(int i = start - 1; i < end; i++){
        temp = vect[i];
        vect[i] = vect[i + 1];
        vect[i + 1] = temp;
        i++;
    }
    
}

void sort(std::vector<int> & vect){
    std::vector<int> temp;
    for(int i = 1; i < vect.size(); i++){
        if(vect[i] < vect[i - 1]){
            temp.push_back(i);
            temp.push_back(i + 1);
        }

    }
    
    
    bool isFirst = false;
    for(int i = 0; i < temp.size(); i++){
        for(int j = temp.size() - 1; j > i; j--){
            if((temp[j] - temp[i]) % 2 == 1){
                animalSort(vect, temp[i], temp[j]);
                i = temp[j];
                isFirst = true;
                break;
            }
        }
        if(isFirst)
            break;
    }
    
    if(temp.size() == 0)
        return;
    else{
        sort(vect);
    }
}

int main(int argc, const char * argv[]){
    int n;
    std::cin >> n;
    std::vector<int> vect;
    int temp;
    for(int i = 0; i < n; i++){
        std::cin >> temp;
        vect.push_back(temp);
    }
    sort(vect);
}

*/



int main(int argc, const char * argv[]){
    int hourRange, minRange;
    std::cin >> hourRange >> minRange;
    std::vector<int> vect;
    int numDigits = 0;
    int firstHour;
    int minHour;
    for(int i = hourRange; i != 0; i /= 7){
        firstHour = i;
        numDigits++;
    }
    for(int i = minRange; i != 0; i /= 7){
        minHour = i;
        numDigits++;
    }
    
    if(numDigits > 7){
        std::cout << 0;
    }
    else{
        
    }
    
}
