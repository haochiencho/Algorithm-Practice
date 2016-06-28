//
//  main.cpp
//  code_forces
//
//  Created by Brian Cho on 6/22/16.
//  Copyright © 2016 Cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>

/* A
int max(int a, int b){
    if(a >= b)
        return a;
    else
        return b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    std::cin >> n;
    std::vector<int> input;
    int temp;
    int minPos, maxPos;
    for(int i = 0; i < n; i++){
        std::cin >> temp;
        input.push_back(temp);
        if(temp == 1)
            minPos = i;
        if(temp == n)
            maxPos = i;
    }
    int curDistance;
    int output;
    if(minPos < maxPos){
        curDistance = maxPos - minPos;
        output = curDistance + max(minPos, n - 1 - maxPos);
    }
    else{
        curDistance = minPos - maxPos;
        output = curDistance + max(maxPos, n - 1 - minPos);
    }
    
    std::cout << output << std::endl;
    return 0;
}
 
 */

/* B
struct Glass{
    double curQuality;
    double incomingRate;
    double maxIncomingRate;
    std::vector<int> parent;
};

int main(int argc, const char * argv[]){
    int n, t;
    std::cin >> n >> t;
    std::vector<Glass> vect;
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(i == 0){
                Glass temp;
                temp.curQuality = 0;
                temp.incomingRate = 1;
                temp.parent.push_back(-1);
                temp.maxIncomingRate = 1;
                vect.push_back(temp);
                count++;
            }
            else{
                Glass temp;
                temp.curQuality = 0;
                temp.incomingRate = 0;
                if(j == 0){
                    temp.parent.push_back(count - i);
                    temp.maxIncomingRate = vect[count - i].maxIncomingRate / 2;
                }
                else if (j == i){
                    temp.parent.push_back(count - i - 1);
                    temp.maxIncomingRate = vect[count - i - 1].maxIncomingRate / 2;
                }
                else{
                    temp.parent.push_back(count - i);
                    temp.parent.push_back(count - i - 1);
                    temp.maxIncomingRate = vect[count - i].maxIncomingRate / 2;
                    temp.maxIncomingRate += vect[count - i - 1].maxIncomingRate / 2;
                }
                vect.push_back(temp);
                count++;
            }
        }
    }
    
    for(int i = 0; i < t; i++){
        if(i == 0){
            vect[0].curQuality = 1;
            continue;
        }
        for(int j = count - 1; j > 0; j--){
            for(int k = 0; k < vect[j].parent.size(); k++){
                if(vect[vect[j].parent[k]].curQuality >= 1 && vect[j].incomingRate + vect[vect[j].parent[k]].incomingRate / 2 <= vect[j].maxIncomingRate)
                    vect[j].incomingRate += vect[vect[j].parent[k]].incomingRate / 2;
                
            }
            vect[j].curQuality += vect[j].incomingRate;
        }
    }

    int counter = 0;
    for(int i = 0; i < vect.size(); i++){
        if(vect[i].curQuality >= 1)
            counter++;
    }
    
    std::cout << counter << std::endl;
    return 0;
}
 
 



int main(int argc, const char * argv[]){
    std::string input = "";
    int n, curSwitch;
    std::cin >> n >> curSwitch;
    char temp;
    for(int i = 0; i < n; i++){
        std::cin >> temp;
        input += temp;
    }
    int lastNeg = 0;
    int curMax = 0;
    int count = 0;
    int negTemp = 0;
    bool first = true;
    for(int i = 0; i < n; i++){
        if(input[i] == 'a')
            count++;
        else{
            if(curSwitch > 0){
                curSwitch--;
                if(first){
                    lastNeg = i;
                    first = false;
                }

            }
            else{
                for(int j = lastNeg + 1; j < n; j++){
                    if(input[j] == 'b'){
                        lastNeg = j;
                        break;
                    }
                }
                negTemp = lastNeg;
            }
        }
        if(i - negTemp + 1 > curMax)
            curMax = i - negTemp + 1;
    }
    std::cout << curMax << std::endl;
}
 
 */
