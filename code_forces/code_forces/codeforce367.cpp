//
//  main.cpp
//  codeforce367
//
//  Created by Brian Cho on 9/22/16.
//  Copyright © 2016 Cho. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <iomanip>
using namespace std;

/*
int main(int argc, const char * argv[]) {
    double x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    double minTime = INT_MAX;
    for(int i = 0; i < n; i++){
        double x1, y1, v;
        cin >> x1 >> y1 >> v;
        if(minTime > sqrt(pow(x - x1, 2) + pow(y - y1, 2)) / v)
            minTime = sqrt(pow(x - x1, 2) + pow(y - y1, 2)) / v;
    }
    cout.setf(ios::fixed, ios::floatfield); // set fixed floating format
    cout << setprecision(7) << minTime << endl;
    return 0;
}
 */

/*

vector<int> mergeSort(vector<int> vect, int start, int end){
    int mid = (start + end) / 2;
    vector<int> output;
    if(start == end){
        output.push_back(vect[start]);
        return output;
    }
    vector<int> left = mergeSort(vect, start, mid);
    vector<int> right = mergeSort(vect, mid + 1, end);
    int i = 0;
    int j = 0;
    while(i + j < left.size() + right.size()){
        if(i >= left.size()){
            output.push_back(right[j]);
            j++;
            continue;
        }
        if(j >= right.size()){
            output.push_back(left[i]);
            i++;
            continue;
        }
        if(left[i] < right[j]){
            output.push_back(left[i]);
            i++;
        }
        else{
            output.push_back(right[j]);
            j++;
        }
    }
    return output;
}

int binarySearch(vector<int> vect, int val){
    int start = 0;
    int end = vect.size() - 1;
    int mid;
    while(start <= end){
        mid = (start + end) / 2;
        if(start == end){
            if(vect[start] <= val)
                return start + 1;
            else
                return start;
        }
        if(vect[mid] <= val){
            if(mid == vect.size() - 1 || vect[mid + 1] > val)
                return mid + 1;
            else
                start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    return 0;
}

int main(int argc, char * argv[]){
    int n;
    cin >> n;
    vector<int> vect;
    vector<int> hash(100001, 0);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        vect.push_back(temp);
        hash[temp]++;
    }
    for(int i = 2; i <= 100000; i++){
        hash[i] += hash[i - 1];
    }
    int num, val;
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> val;
        if(val > 100000)
            val = 100000;
        cout << hash[val] << endl;
    }
    
    
}
*/

string flip(string A){
    return A;
}

int main(int argc, char * argv[]){
    int n;
    cin >> n;
    int temp;
    vector<int> vect;
    for(int i = 0; i < n; i++){
        cin >> temp;
        vect.push_back(temp);
    }
    int arr[100001][2] = {0};
    arr[0][1] = vect[0];
    string curString, prevString;
    cin >> prevString;
    for(int i = 1; i < n; i++){
        cin >> curString;
        if(curString >= prevString && curString >= flip(prevString)){
            arr[i][0] = min(arr[i - 1][0], arr[i - 1][1]);
        }
        else if(curString >= prevString)
            arr[i][0] = arr[i - 1][0];
        else if(curString >= flip(prevString))
            arr[i][0] = arr[i - 1][1];
        else{ // not possible
            
        }
            prevString = curString;
    }
    
}
