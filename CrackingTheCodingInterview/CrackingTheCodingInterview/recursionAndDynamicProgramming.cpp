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
using namespace std;

// A child can take 1, 2, or 3 steps at a time. how many possible ways are there to get up a n step stairway?

int stairRecur(int numSteps){
    if(numSteps <= 0)
        return 0;
    else if(numSteps == 1)
        return 1;
    else if(numSteps == 2)
        return 2;
    else if(numSteps == 3)
        return 4;
    return stairRecur(numSteps - 1) + stairRecur(numSteps - 2) + stairRecur(numSteps - 3);
}

int stairDP(int numSteps){
    vector<int> vect(numSteps);
    vect[0] = 1;
    vect[1] = 2;
    vect[2] = 4;
    for(int i = 3; i < numSteps; i++){
        vect[i] = vect[i - 1] + vect[i - 2] + vect[i - 3];
    }
    return vect[vect.size() - 1];
}

// given a rectangular grid and a robot that can only move down and right.
// starting from the top left and moving to bottom right.
// there are tiles that cannot be passed through
// find a path for the robot

vector<vector<int> > findPathRecur(vector<vector<int> > grid, vector<int> start, vector<vector<int> > curPath){
    vector<int> temp(2);
    temp[0] = start[0];
    temp[1] = start[1];
    curPath.push_back(temp);
    if((start[0] == grid.size() - 1) && (start[1] == grid[0].size() - 1))
        return curPath;
    if(grid[start[0] + 1][start[1]])
    {
        start[0]++;
        return findPathRecur(grid, start, curPath);
    }
    if(grid[start[0]][start[1] + 1]){
        start[1]++;
        return findPathRecur(grid, start, curPath);
    }
    return curPath; // function will never reach this point
}

vector<vector<int> > findPathDFS(vector<vector<int> > grid){
    stack<vector<int> > curPath;
    stack<vector<int> > allPath;
    vector<vector<int> > visited;
    vector<int> curStep(2, 0);
    allPath.push(curStep);
    for(int i = 0; i < grid.size(); i++){
        vector<int> temp(grid[0].size(), 0);
        visited.push_back(temp);
    }
    visited[0][0] = 1;
    while(!allPath.empty()){
        vector<int> temp;
        temp = allPath.top();
        allPath.pop();
        visited[temp[0]][temp[1]] = 1;
        curPath.push(temp);
        temp[0]++;
        if(visited[temp[0]][temp[1]] && grid[temp[0]][temp[1]]){
            allPath.push(temp);
        }
        temp[0]--;
        temp[1]++;
        if(visited[temp[0]][temp[1]] && grid[temp[0]][temp[1]]){
            allPath.push(temp);
        }
        if((visited[temp[0] + 1][temp[1]] || grid[temp[0]+ 1][temp[1]]) && (visited[temp[0]][temp[1] + 1] || grid[temp[0]][temp[1] + 1]))
            curPath.pop();
    }
    vector<vector<int> > output;
    while(!curPath.empty()){
        output.insert(output.begin(), curPath.top());
        curPath.pop();
    }
    return output;
}

// given a sorted array of distinct integers, find a magic index.
// a magic index is the index equaling the value of index. A[i] = i

int magicIndexRecur(int arr[], int start, int end){
    if(start > end)
        return -1;
    int mid = (start + end) / 2;
    if(arr[mid] == mid)
        return mid;
    else if(arr[mid] > mid)
        return magicIndexRecur(arr, start, mid - 1);
    else
        return magicIndexRecur(arr, mid + 1, end);
}

// given a set of integers, output all possible sets

vector<vector<int> > allSets(vector<int> set){ // pass in a single empty set for curSet
    vector<vector<int> > curSet;
    vector<int> emptySet;
    curSet.push_back(emptySet);
    for(int i = 0; i < set.size(); i++){
        int n = curSet.size();
        for(int j = 0; j < n; j++){
            vector<int> temp = curSet[j];
            temp.push_back(set[i]);
            curSet.push_back(temp);
        }
    }
    return curSet;
}

// towers of hanoi

int numSteps(int numDisks){
    if(numDisks <= 0)
        return 0;
    else if(numDisks == 1)
        return 1;
    return 2 * numSteps(numDisks - 1) + 1;
}

// compute all permutations of a string that contains only unique characters

void swap2(string& input, int pos1, int pos2){
    char temp = input[pos1];
    input[pos1] = input[pos2];
    input[pos2] = temp;
}

vector<string> allPerm(string input, vector<string> output, int length){
    if(length == 0)
        return output;
    if(length == 1){
        output.push_back(input);
        return output;
    }
    vector<string> temp = allPerm(input, output, length - 1);
    output.insert(output.end(), temp.begin(), temp.end());
    for(int i = 0; i < length - 1; i++){
        swap2(input, i, length - 1);
        temp = allPerm(input, output, length - 1);
        output.insert(output.end(), temp.begin(), temp.end());
    }
    return output;
}

int main(int argc, char* argv[]){
    cout << stairDP(5) << endl;
    cout << numSteps(3) << endl;
    vector<string> temp;
    vector<string> output = allPerm("ABC", temp, 4);
}
