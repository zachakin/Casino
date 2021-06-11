// CS1300 Fall 2020
// Author: Zach Akin-Amland
// Recitation: 511 - Calista Nguyen
// Project 3 - Player Class
#include <iostream>
#include <string>
#include <vector>
#include "classes.h"
#include <unistd.h>
using namespace std;

Player::Player()
{
    draw=1;
    playerHand.cardIn(deck.giveCard(),deck.giveCard());
}
Player::Player(Deck deckInput)
{
    draw=1;
    deck=deckInput;
    playerHand.cardIn(deck.giveCard(),deck.giveCard());
}
void Player::showCards()
{
    cout << "Your cards are:" << endl; usleep(1000000);
    playerHand.showCard();
}
int Player::total()
{
    totalSum=playerHand.total();
    return totalSum;
}
void Player::stay()
{
    cout << "Flipping Dealer's Card..." << endl; usleep(1000000);
    draw=0;
    totalSum=playerHand.total();
}
void Player::hit()
{
    if(draw==true)
    {
        playerHand.addCard(deck.giveCard());
    }
    else
    {
        cout << "You cannot hit" << endl;
    }
}
void Player::hitSimulated()
{
    if(draw==true)
    {
        playerHand.addSimulatedCard(deck.giveCard());
    }
}
void Player::staySimulated()
{
    draw=0;
    totalSum=playerHand.total();
}
bool Player::win()
{
    if(playerHand.total()==21)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
bool Player::lose()
{
    if(playerHand.total()>21)
    {
        return true;
    }
    else
    {
        return false;
    }
}