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

int main(int argc, char* argv[]){
    cout << stairDP(5);
}
