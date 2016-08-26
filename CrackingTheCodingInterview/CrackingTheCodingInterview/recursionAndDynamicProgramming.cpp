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

// output all possible ordering of parentheses

vector<string> allParentheses(int n){
    vector<string> output;
    if(n <= 0)
        return output;
    if(n == 1){
        output.push_back("()");
        return output;
    }
    vector<string> temp = allParentheses(n - 1);
    int size = temp.size();
    for(int i = 0; i < size; i++){
        string str = temp[i];
        temp.push_back(str.insert(0, "()"));
        str = temp[i];
        str.insert(temp[i].size(), "()");
        if(str != temp[temp.size() - 1])
            temp.push_back(str);
        str = temp[i];
        str.insert(0, "(");
        str.insert(str.size(), ")");
        temp[i] = str;
    }
    return temp;
}

// paint fill: given a 2d vector of pixels, a point, and a color, change all regions next to the point of the same color to a specified color

vector<vector<int> > paintFill(vector<vector<int> > canvas, int x, int y, int color, int initColor){
    if(x < 0 || x >= canvas[0].size())
        return canvas;
    if(y < 0 || y >= canvas.size())
        return canvas;
    if(canvas[x][y] != initColor)
        return canvas;
    else{
        canvas[x][y] = color;
        paintFill(canvas, x, y - 1, color, initColor);
        paintFill(canvas, x + 1, y, color, initColor);
        paintFill(canvas, x, y + 1, color, initColor);
        paintFill(canvas, x - 1, y, color, initColor);
        return canvas;
    }
}

// output the number of ways to represent n cents with quarters, dimes, nickels, and pennies.
int numWays(int cents){
    if(cents < 5)
        return 0;
    int sum = 0;
    int nickel, dime, quarter;
    nickel = cents / 5;
    dime = cents / 10;
    quarter = cents / 25;
    sum += nickel + dime + quarter;
    if(cents % 10 == 0 && dime > 0)
        sum += dime - 1;
    else
        sum += dime;
    sum += numWays(cents - 25);
    sum += 1;
    return sum;
}

// 8 queens on a 8x8 chess board

vector<vector<int> > updateMap(vector<vector<int> > map, int x, int y){
    map[x][y] = 2;
    for(int i = 0; i < 8; i++){
        if(map[x][i] == 0)
            map[x][i] = 1;
        if(map[i][y] == 0)
            map[i][y] = 1;
    }
    for(int i = 1; i < 8; i++){
        if(x - i < 0 || y - i < 0 )
            break;
        if(map[x - i][y - i] == 0)
            map[x - i][y - i] = 1;
    }
    for(int i = 1; i < 8; i++){
        if(x + i < 0 || y - i < 0 )
            break;
        if(map[x + i][y - i] == 0)
            map[x + i][y - i] = 1;
    }
    for(int i = 1; i < 8; i++){
        if(x - i < 0 || y + i < 0 )
            break;
        if(map[x - i][y + i] == 0)
            map[x - i][y + i] = 1;
    }
    for(int i = 1; i < 8; i++){
        if(x + i < 0 || y + i < 0 )
            break;
        if(map[x + i][y + i] == 0)
            map[x + i][y + i] = 1;
    }
    return map;
}

vector<vector<vector<int> > > allPoss8Queens(vector<vector<int> > map, int x, int y, int numQueen){
    vector<vector<vector<int> > > output;
    if(y >= 8)
        return output;
    for(int i = 0; i < 8; i++){
        if(map[x][i] == 0){
             vector<vector<vector<int> > > temp = allPoss8Queens(updateMap(map, i, y), i, y, numQueen + 1);
            output.insert(output.end(), temp.begin(), temp.end());
        }
    }
    if(numQueen == 8)
        output.push_back(map);
    return output;
}

// stacking boxes: boxes can only be stacked if the height, width and length of the box underneath is greater than
// the 3 dimensions of the box above. calculate the max height

bool greaterthan(vector<int> a, vector<int> b){
    if(a[3] > b[3])
        return true;
    else
        return false;
}



vector<vector<int> > mergeSort(vector<vector<int> > vect, int begin, int end){ // sort by height
    vector<vector<int> > output;
    if(begin == end){
        output.push_back(vect[begin]);
        return output;
    }
    int mid = (begin + end) / 2;
    vector<vector<int> > vect1 = mergeSort(vect, begin, mid);
    vector<vector<int> > vect2 = mergeSort(vect, mid + 1, end);
    int i, j;
    i = 0;
    j = 0;
    while(i >= vect1.size() && j >= vect2.size()){
        if(i >= vect1.size()){
            output.push_back(vect[j]);
            j++;
        }
        if(j >= vect2.size()){
            output.push_back(vect[i]);
            i++;
        }
        if(greaterthan(vect[i], vect[j])){
            output.push_back(vect[j]);
            j++;
        }
        else{
            output.push_back(vect[i]);
            i++;
        }
    }
    return output;
}

int maxHeight(int numBoxes, vector<vector<int> > box){
    vector<vector<int> > sortedBox = mergeSort(box, 0, numBoxes - 1);
    vector<vector<int> > result; // curHeight, bottom length, bottom width
    vector<int> temp(3, 0);
    for(int i = 0; i < numBoxes; i++){
        if(i == 0){
            temp[0] = sortedBox[i][2];
            temp[1] = sortedBox[i][0];
            temp[2] = sortedBox[i][1];
            result.push_back(temp);
            continue;
        }
        int j;
        for(j = sortedBox.size() - 1; j >= 0; j--){
            if(sortedBox[i][2] > result[j][0] && sortedBox[i][0] > result[j][1] && sortedBox[i][1] > result[j][2])
                break;
        }
        if(j < 0){
            if(result[result.size() - 1][0] > sortedBox[i][2]){
                temp[0] = result[result.size() - 1][0];
                temp[1] = result[result.size() - 1][1];
                temp[2] = result[result.size() - 1][2];
                result.push_back(temp);
            }
            else{
                temp[0] = sortedBox[i][2];
                temp[1] = sortedBox[i][0];
                temp[2] = sortedBox[i][1];
                result.push_back(temp);
            }
        }
        else{
            if(result[j][0] + sortedBox[i][2] > result[result.size() - 1][0]){
                temp[0] = result[j][0] + sortedBox[i][2];
                temp[1] = sortedBox[i][0];
                temp[2] = sortedBox[i][1];
                result.push_back(temp);
            }
            else{
                temp[0] = result[result.size() - 1][0];
                temp[1] = result[result.size() - 1][1];
                temp[2] = result[result.size() - 1][2];
                result.push_back(temp);
            }
        }
    }
    return result[result.size() - 1][0];
}

// output the number of possible orders that will yield in that result
// eg. 1^0|1, false = 1

int boolPoss(string input, int answer){
    vector<string> vect;
    vect.push_back(input);
    int prevSize;
    string temp;
    while(1){
        if(vect[0].size() <= 1)
            break;
        for(int i = 0; i < vect[0].size();){
            temp = vect[0];
            if(vect[0][i + 1] == '^'){
                string holder = to_string(stoi(vect[i]) ^ stoi(vect[i + 2]));
                temp.insert(vect[0].begin(), holder.begin(), holder.end());
                temp.erase(i, 3);
                
            }
            else if(vect[0][i + 1] == '&'){
                string holder = to_string(stoi(vect[i]) & stoi(vect[i + 2]));
                temp.insert(vect[0].begin(), holder.begin(), holder.end());
                temp.erase(i, 3);
            }
            else{
                string holder = to_string(stoi(vect[i]) | stoi(vect[i + 2]));
                temp.insert(vect[0].begin(), holder.begin(), holder.end());
                temp.erase(i, 3);
            }
            vect.push_back(temp);
            i += 2;
        }
        vect.erase(vect.begin());
    }
    int count = 0;
    for(int i = 0; i < vect.size(); i++){
        if(stoi(vect[i]) == answer)
            count++;
    }
    return count;
}


int main(int argc, char* argv[]){
    // testing
    cout << stairDP(5) << endl;
    cout << numSteps(3) << endl;
    vector<string> temp;
    vector<string> output = allParentheses(3);
    cout << numWays(30) << endl;
    
}
