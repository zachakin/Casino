// CS1300 Fall 2020
// Author: Zach Akin-Amland
// Recitation: 511 - Calista Nguyen
// Project 3 - Hand Class
#include <iostream>
#include <string>
#include <vector>
#include "classes.h"
#include <unistd.h>
using namespace std;

void Hand::cardIn(Cards first,Cards second)
{
    hand.push_back(first);
    hand.push_back(second);
}
void Hand::showCard()
{
    for(vector<Cards>::iterator i=hand.begin();i!=hand.end();i++)
    {
        i->nameCard();
    }
}
void Hand::showDealerCard()
{
    hand[0].nameCard();
}
void Hand::addCard(Cards card)
{
    cout << "Drawing card..." << endl; usleep(1000000);
    card.nameCard();
    for(vector<Cards>::iterator i=hand.begin();i!=hand.end();i++)
    {
        if(i->getCard()=='A'&&totalSum>11)
        {
            totalSum=totalSum-10;
        }
    }
    hand.push_back(card);
}
void Hand::addSimulatedCard(Cards card)
{
    for(vector<Cards>::iterator i=hand.begin();i!=hand.end();i++)
    {
        if(i->getCard()=='A'&&totalSum>11)
        {
            totalSum=totalSum-10;
        }
    }
    hand.push_back(card);
}
int Hand::numCards()
{
    return hand.size();
}
int Hand::total()
{
    totalSum=0;
    for(vector<Cards>::iterator i=hand.begin();i!=hand.end();i++)
    {
        totalSum+=i->getNum();
    }
    for(vector<Cards>::iterator i=hand.begin();i!=hand.end();i++)
    {
        if(i->getCard()=='A'&&totalSum>21)
        {
            totalSum=totalSum-10;
        }
    }
    return totalSum;
}
