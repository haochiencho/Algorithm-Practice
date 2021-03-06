//
//  object.cpp
//  introductionToAlgorithmCormen
//
//  Created by Brian Cho on 8/12/16.
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

// design a card deck and implement black jack

struct Card{ // assuming no jokers
    string suit;
    int value;
};

class Player{
public:
    Player(int money){
        curMoney = money;
    }
    void placeBet(int bet);
    void getCard(); // gets a random card
    bool isBust(); // checks if the player has busted
    int countSum();
private:
    vector<Card> hand;
    int curMoney;
    int curBet;
};

class BlackJack{
public:
    BlackJack(vector<Player> vect) : dealer(INT_MAX){
        players = vect;
    }
    void dealCards(); // deals cards to all players and the dealer
    bool comparedWithDealer(Player player); // compares to see if player wins
private:
    Player dealer;
    vector<Player> players;
};

void Player::placeBet(int bet){
    curBet = bet;
}

void Player::getCard(){
    Card* card = new Card;
    card->value = (rand() % 13) + 1;
    card->suit = rand() % 4;
    hand.push_back(*card);
}

int Player::countSum(){
    int sum = 0;
    int aceCount = 0;
    for(int i = 0; i < hand.size(); i++){
        if(hand[i].value == 1){
            sum += 11;
            aceCount++;
        }
        else
            sum += hand[i].value;
    }
    while(aceCount > 0 && sum > 21){
        sum -= 10;
        aceCount--;
    }
    return sum;
}

bool Player::isBust(){
    if(countSum() > 21)
        return true;
    else
        return false;
}

void BlackJack::dealCards(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < players.size(); j++){
            players[j].getCard();
        }
        dealer.getCard();
    }
}

bool BlackJack::comparedWithDealer(Player player){
    if(dealer.countSum() > player.countSum())
        return false;
    else
        return true;
}


// there are 3 levels of employees: respondents, managers, and directors. they must deal with the clients calles and passes it
// to their superior if they cannot handle it

struct Customer{
    int difficulty;
    int time;
};

class Employee{
public:
    Employee(int diffCap){
        difficultyCap = diffCap;
    }
    int getDifCap(){
        return difficultyCap;
    }
private:
    int difficultyCap;
};

class Director : public Employee{
public:
    Director()
    : Employee(INT_MAX){}
    void handleCall(Customer cust);
    bool isFree();
private:
    bool free;
};
/*
class Manager : public Employee{
public:
    Manager(int diffCap, vector<Director> superior)
    : Employee(diffCap){
        upper = superior;
        free = true;
    }
    void handleCall(Customer cust);
    bool isAvailable();
private:
    vector<Director> upper;
    bool free;
};

class Respondent : public Employee{
public:
    Respondent(int diffCap, vector<Manager> superior)
    : Employee(diffCap){
        upper = superior;
        free = true;
    }
    void handleCall(Customer cust);
    bool isAvailable();
private:
    vector<Manager> upper;
    bool free;
};

void Respondent::handleCall(Customer cust){
    if(getDifCap() < cust.difficulty){
        for(int i = 0; i < upper.size(); i++){
            if(upper[i].isAvailable()){
                free = false;
                // pause for time of cust
                free = true;
            }
        }
    }
    else{
        free = false;
        // pause for time of cust
        free = true;
    }
}
*/

// design a juke box with object oriented principles

struct Song{
    string name;
    int duration;
};

class JukeBox{
public:
    void addSong(string name, int duration);
    Song shufflePlay();
private:
    vector<Song> song;
};

class Polygon{
public:
    Polygon(int numSides) : numSides(numSides){
        
    }
    virtual void aboutMe();
    virtual ~Polygon(){
        cout << "deleting a polygon" << endl;
    }
private:
    int numSides;
};

void Polygon::aboutMe(){
    cout << "I am a polygon" << endl;
}

class Square : public Polygon{
public:
    Square(int numSides, int numLength) : Polygon(numSides), sideLength(numLength){
        
    }
    void aboutMe();
    ~Square(){
        cout << "deleting a square" << endl;
    }
    Square operator+(Square &other);
private:
    int sideLength;
};

void Square::aboutMe(){
    cout << "I am a square" << endl;
}

Square Square::operator+(Square &other){
    Square square(4, 0);
    square.sideLength = other.sideLength + this->sideLength;
    return square;
}


int main(int argc, char* argv[]){
    Square* newSquare = new Square(4, 5);
    Square* square = new Square(4, 2);
    
    (*square) = (*newSquare + *square);
    newSquare->aboutMe();
    delete newSquare;
}
