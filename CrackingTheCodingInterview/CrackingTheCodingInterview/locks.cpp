//
//  locks.cpp
//  introductionToAlgorithmCormen
//
//  Created by Brian Cho on 9/11/16.
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
#include <fstream>
#include <sstream>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* pthread_func(void* arg){
    return NULL;
}

void diningPhilophers(){
    pthread_t thread[8];
    int rc;
    for(int i = 0; i < 8; i++){
        if(rc = pthread_create(&(thread[i]), NULL, &pthread_func, NULL))
            cerr << "error message";
    }
    for(int i = 0; i < 8; i++){
        pthread_join(thread[(i + 1) % 8], NULL);
    }
    
}

// create a class that provides a lock only if there are no deadlocks

class NoDeadlock{
public:
    NoDeadlock(){
        isLock = false;
    }
    bool provideLock(pthread_mutex_t lock);
private:
    bool isLock;
};

bool NoDeadlock::provideLock(pthread_mutex_t lock){
    if(isLock)
        return false;
    else{
        pthread_mutex_lock(&lock);
        return true;
    }
}

// design a class with a function, foo, that will be passed to three threads, each calling different functions.

/*
class Foo{
public:
    Foo(){
        pthread_t thr[3];
        for(int i = 0; i < 3; i++){
            switch(i){
                case 0:
                    pthread_create(&(thr[i]), NULL, &Foo::first, NULL);
                    break;
                case 1:
                    pthread_create(&(thr[i]), NULL, &Foo::second, NULL);
                    break;
                case 2:
                    pthread_create(&(thr[i]), NULL, &Foo::third, NULL);
                    break;
            }
        }
    }
    void* first(void* arg){
        return NULL;
    }
    void* second(void* arg){
        return NULL;
    }
    void* third(void* arg){
        return NULL;
    }
};
*/

// implement the fizzbuzz game with 2 threads. print fizz if number is divisible by 3 and buzz if it is divisible by 5.
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void* fizz(void* count){
    int* ptr = (int*) count;
    if((*ptr) % 3)
        cout << "fizz";
    pthread_mutex_unlock(&lock2);
    return NULL;
}

void* buzz(void* count){
    int* ptr = (int*) count;
    pthread_mutex_lock(&lock2);
    if(*(ptr) % 5)
        cout << "buzz";
    return NULL;
}

void fizzBuzz(int count){
    pthread_t id[2];
    pthread_mutex_lock(&lock2);
    pthread_create(&(id[0]), NULL, &fizz, &count);
    pthread_create(&(id[1]), NULL, &buzz, &count);
    
    
}


int main(int argc, char* argv[]){
    
}
