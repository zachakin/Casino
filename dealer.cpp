// CS1300 Fall 2020
// Author: Zach Akin-Amland
// Recitation: 511 - Calista Nguyen
// Project 3 - Dealer Class
#include <iostream>
#include <string>
#include <vector>
#include "classes.h"
#include <unistd.h>
using namespace std;

Dealer::Player(Deck())
{
    return Dealer::Player(Deck());
}
void Dealer::dealerCard()
{
    cout << "Dealer's Cards:" << endl; usleep(1000000);
    playerHand.showDealerCard();
    cout << " -------- " << endl;
    cout << "|?       |" << endl;
    cout << "|        |" << endl;
    cout << "|   ?    |" << endl;
    cout << "|        |" << endl;
    cout << "|      ? |" << endl;
    cout << " -------- " << endl; usleep(1000000);
}
int Dealer::play(Player player1)
{
    //figure out how to display, win, and lose the game
    int x;
    string input;
    while(playerHand.total()<=21)
    {
        cout << "Dealer's Cards:" << endl;
        playerHand.showCard();
        cout << "Dealer's total: " << playerHand.total() << endl;
        if(playerHand.total()>player1.total()&&playerHand.total()<=21)
        {
            cout << "The Dealer won" << endl;
            return -1;
        }
        if(playerHand.total()==player1.total())
        {
            cout << "Push" << endl;
            return 0;
        }    
        hit();
    }
    if(playerHand.total()>21)
    {
        cout << "The dealer went over 21" << endl;
        return 1;
    }
    return 0;
}
int Dealer::playSimulated(Player player1)
{
    //figure out how to display, win, and lose the game
    int x;
    string input;
    while(playerHand.total()<=21)
    {
        if(playerHand.total()>player1.total()&&playerHand.total()<=21)
        {
            return -1;
        }
        if(playerHand.total()==player1.total())
        {
            return 0;
        }    
        hitSimulated();
    }
    if(playerHand.total()>21)
    {
        return 1;
    }
    return 0;
}
