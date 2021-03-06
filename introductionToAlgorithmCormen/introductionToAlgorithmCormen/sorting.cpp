//
//  main.cpp
//  algorithm_practice
//
//  Created by Brian Cho on 6/19/16.
//  Copyright © 2016 Cho. All rights reserved.
//

#define INT_MAX 2147483647
#define INT_MIN -2147483648

#include <iostream>
#include <vector>

// insertion sort
void insertionSort(std::vector<int> & arr){
    int temp;
    int n = arr.size();
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] <= arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// merge sort
std::vector<int> mergeSort(std::vector<int> & vect, int start, int end){
    std::vector<int> temp;
    temp.push_back(vect[start]);
    if(start == end)
        return temp;
    temp.clear();
    int middle = (start + end) / 2;
    std::vector<int> left;
    std::vector<int> right;
    for(int i = 0; i <= middle - start; i++)
        left.push_back(vect[i]);
    for(int i = middle - start + 1; i <= end - start; i++)
        right.push_back(vect[i]);
    mergeSort(left, start, middle);
    mergeSort(right, middle + 1, end);
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);
    int j = 0;
    int k = 0;
    for(int i = 0; i <= end - start; i++){
        if(left[j] < right[k]){
            vect[i] = left[j];
            j++;
        }
        else{
            vect[i] = right[k];
            k++;
        }
    }
    return vect;
}

// application of divide and conquer to find longest increasing subsequence
int maxOfThree(int a, int b, int c){
    if(a >= b && a >= c)
        return a;
    else if(b >= a && b >= c)
        return b;
    else
        return c;
}

int middleOut(std::vector<int> left, std::vector<int> right){
    int leftCount = 1;
    int leftLength = left.size();
    for(int i = leftLength - 1; i > 0; i--){
        if(left[i] > left[i - 1])
            leftCount++;
        else
            break;
    }
    int rightCount = 1;
    int rightLength = right.size();
    for(int i = 0; i < rightLength - 1; i++){
        if(right[i] < right[i + 1])
            rightCount++;
        else
            break;
    }
    if(left[leftLength - 1] < right[0])
        return leftCount + rightCount;
    else
        if(leftCount >= rightCount)
            return leftCount;
        else
            return rightCount;
}

int longestIncreasingSubsequence(std::vector<int> vect, int start, int end){
    if(start == end)
        return 1;
    int middle = (start + end) / 2;
    std::vector<int> left;
    std::vector<int> right;
    for(int i = 0; i <= middle - start; i++)
        left.push_back(vect[i]);
    for(int i = middle - start + 1; i <= end - start; i++)
        right.push_back(vect[i]);
    int leftSide = longestIncreasingSubsequence(left, start, middle);
    int rightSide = longestIncreasingSubsequence(right, middle + 1, end);
    return maxOfThree(leftSide, rightSide, middleOut(left, right));
}

// heap sort
void heapify(std::vector<int> & vect, int index, int size){
    int l = (index + 1) * 2 - 1;
    int r = (index + 1) * 2;
    int largest;
    if(l < size && vect[l] > vect[index])
        largest = l;
    else
        largest = index;
    if(r < size && vect[r] > vect[largest])
        largest = r;
    if(largest != index){
        int temp = vect[largest];
        vect[largest] = vect[index];
        vect[index] = temp;
        heapify(vect, largest, size);
    }
    
}

void buildHeap(std::vector<int> & vect){
    for(int i = vect.size() / 2 - 1; i >= 0; i--){
        heapify(vect, i, vect.size());
    }
}

void heapSort(std::vector<int> & vect){
    int size = vect.size();
    buildHeap(vect);
    for(int i = vect.size() -  1; i > 0; i--){
        int temp = vect[0];
        vect[0] = vect[i];
        vect[i] = temp;
        size--;
        heapify(vect, 0, size);
    }
}



// quick sort

void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(std::vector<int> & vect, int start, int end){
    if(start >= end)
        return;
    else{
        int pivot = vect[start];
        int j = start;
        for(int i = start + 1; i <= end; i++){
            if(vect[i] < pivot){
                j++;
                swap(vect[i], vect[j]);
            }
        }
        swap(vect[start], vect[j]);
        quickSort(vect, start, j - 1);
        quickSort(vect, j + 1, end);
    }
}

// counting sort
void countingSort(std::vector<int> & vect){
    std::vector<int> count(10, 0);
    for(int i = 0; i < vect.size(); i++){
        (count[vect[i]])++;
    }
    for(int i = 1; i < count.size(); i++){
        count[i] = count[i] + count[i - 1];
    }
    std::vector<int> output(vect.size());
    for(int i = 0; i < vect.size(); i++){
        output[count[vect[i]] - 1] = vect[i];
        (count[vect[i]])--;
    }
    for(int i = 0; i < vect.size(); i++){
        vect[i] = output[i];
    }
}

// radix sort
void radixSort(std::vector<int> & vect, int d){
    std::vector<int> digit(vect.size());
    std::vector<int> output(vect.size(), 0);
    int div = 1;
    for(int i = 0; i < d; i++){
        for(int j = 0; j < vect.size(); j++){
            digit[j] = (vect[j] / div) % 10;
        }
        quickSort(digit, 0, vect.size() - 1);
        for(int j = 0; j < vect.size(); j++){
            for(int k = 0; k < vect.size(); k++){
                if(digit[j] == (vect[k] / div) % 10){
                    output[j] = vect[k];
                    break;
                }
            }
        }
        for(int i = 0; i < vect.size(); i++){
            vect[i] = output[i];
        }
        div *= 10;
    }
    for(int i = 0; i < vect.size(); i++){
        vect[i] = output[i];
    }
    
}


// bucket sort
struct Node{
    int val;
    Node* next;
};

class List{
public:
    List();
    void insertNode(int val);
    Node* getHead(void){
        return m_head;
    }
private:
    Node* m_head;
};

List::List(void){
    m_head = nullptr;
}

void List::insertNode(int val){
    Node* A = new Node;
    A->val = val;
    A->next = nullptr;
    if(m_head == nullptr){
        m_head = A;
    }
    else{
        Node* temp = m_head;
        while(temp->next != nullptr && temp->val < val){
            temp = temp->next;
        }
        A->next = temp->next;
        temp->next = A;
    }
}

void bucketSort(std::vector<int> & vect){
    std::vector<List> dataStruct(10);
    for(int i = 0; i < vect.size(); i++){
        dataStruct[vect[i] % 10].insertNode(vect[i]);
    }
    int count = 0;
    for(int i = 0; i < 10; i++){
        Node* nodePtr = dataStruct[i].getHead();
        while(nodePtr != nullptr){
            vect[count] = nodePtr->val;
            nodePtr = nodePtr->next;
            count++;
        }
    }
}

/*
int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector <int> vect = {2, 1, 2, 1, 4, 11, 7, 8};
    bucketSort(vect);
    for(int i = 0; i < vect.size(); i++){
        std::cout << vect[i] << std::endl;
    }
    return 0;
}
*/
