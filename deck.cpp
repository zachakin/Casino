// CS1300 Fall 2020
// Author: Zach Akin-Amland
// Recitation: 511 - Calista Nguyen
// Project 3 - Deck Class
#include <iostream>
#include <string>
#include <vector>
#include "classes.h"
using namespace std;

Deck::Deck()
{
    fill();
    shuffle();
}
void Deck::fill()
{
    char card;
    for(int i=1; i<14; i++)
    {
        switch(i)
        {
            case 1:
                card='A';
            break;
            case 2:
                card='2';
            break;
            case 3:
                card='3';
            break;
            case 4:
                card='4';
            break;
            case 5:
                card='5';
            break;
            case 6:
                card='6';
            break;
            case 7:
                card='7';
            break;
            case 8:
                card='8';
            break;
            case 9:
                card='9';
            break;
            case 10:
                card='T';
            break;
            case 11:
                card='J';
            break;
            case 12:
                card='Q';
            break;
            case 13:
                card='K';
            break;
        }
        for(int j=0;j<4;j++)
        {
            deck.push_back(Cards(card,j+1));
        }
    }
}
void Deck::shuffle()
{
    random_shuffle(deck.begin(),deck.end());
}
Cards Deck::giveCard()
{
    for(int i=0; i<deck.size();i++)
    {
        if(deck[i].isGiven()==false)
        {
            deck[i].setGiven(1);
            return deck[i];
        }
    }
    return deck[0];
}
void Deck::readDeck()
{
    for(int i=0; i<deck.size(); i++)
    {
        deck[i].nameCard();
    }
    cout << "Number of cards in the deck: " << deck.size() << endl;
}