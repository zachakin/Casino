// CS1300 Fall 2020
// Author: Zach Akin-Amland
// Recitation: 511 - Calista Nguyen
// Project 3 - Cards Class
#include <iostream>
#include <string>
#include "classes.h"
#include <unistd.h>
using namespace std;

Cards::Cards(char cardInput, int suitInput)
{
    card=cardInput;
    num=assignNum();
    suit=suitInput;
    given=false;
}
char Cards::getCard()
{
    return card;
}
int Cards::getNum()
{
    return num;
}
int Cards::getSuit()
{
    return suit;
}
void Cards::nameCard()
{
    switch(suit)
    {
        case 1:
            nameSuit="Hearts";
        break;
        case 2:
            nameSuit="Spades";
        break;
        case 3:
            nameSuit="Diamonds";
        break;
        case 4:
            nameSuit="Clubs";
        break;
    }
    if(card=='A')
    {
        
        cout << " -------- " << endl;
        cout << "| " << "A" << "      |" << endl;
        cout << "|        |" << endl;
        if(suit==1||suit==2)
        {
            cout << "| " << nameSuit << " |" << endl;
        }
        else if(suit==3)
        {
            cout << "|" << nameSuit << "|" << endl;
        }
        else if(suit==4)
        {
            cout << "| " << nameSuit << "  |" << endl;
        }
        cout << "|        |" << endl;
        cout << "|       " << "A" << "|" << endl;
        cout << " -------- " << endl; usleep(1000000);
        /*cout << "Ace of " << nameSuit << endl;*/
    }
    else if(card=='T')
    {
        
        cout << " -------- " << endl;
        cout << "|" << "10" << "      |" << endl;
        cout << "|        |" << endl;
        if(suit==1||suit==2)
        {
            cout << "| " << nameSuit << " |" << endl;
        }
        else if(suit==3)
        {
            cout << "|" << nameSuit << "|" << endl;
        }
        else if(suit==4)
        {
            cout << "| " << nameSuit << "  |" << endl;
        }
        cout << "|        |" << endl;
        cout << "|      " << "10" << "|" << endl;
        cout << " -------- " << endl; usleep(1000000);
        /*cout << "10 of " << nameSuit << endl;*/
    }
    else if(card=='J')
    {
        
        cout << " -------- " << endl;
        cout << "| " << "J" << "      |" << endl;
        cout << "|        |" << endl;
        if(suit==1||suit==2)
        {
            cout << "| " << nameSuit << " |" << endl;
        }
        else if(suit==3)
        {
            cout << "|" << nameSuit << "|" << endl;
        }
        else if(suit==4)
        {
            cout << "| " << nameSuit << "  |" << endl;
        }
        cout << "|        |" << endl;
        cout << "|      " << "J" << " |" << endl;
        cout << " -------- " << endl; usleep(1000000);
        /*cout << "Jack of " << nameSuit << endl;*/
    }
    else if(card=='Q')
    {
        
        cout << " -------- " << endl;
        cout << "| " << "Q" << "      |" << endl;
        cout << "|        |" << endl;
        if(suit==1||suit==2)
        {
            cout << "| " << nameSuit << " |" << endl;
        }
        else if(suit==3)
        {
            cout << "|" << nameSuit << "|" << endl;
        }
        else if(suit==4)
        {
            cout << "| " << nameSuit << "  |" << endl;
        }
        cout << "|        |" << endl;
        cout << "|      " << "Q" << " |" << endl;
        cout << " -------- " << endl; usleep(1000000);
        /*cout << "Queen of " << nameSuit << endl;*/
    }
    else if(card=='K')
    {
        
        cout << " -------- " << endl;
        cout << "| " << "K" << "      |" << endl;
        cout << "|        |" << endl;
        if(suit==1||suit==2)
        {
            cout << "| " << nameSuit << " |" << endl;
        }
        else if(suit==3)
        {
            cout << "|" << nameSuit << "|" << endl;
        }
        else if(suit==4)
        {
            cout << "| " << nameSuit << "  |" << endl;
        }
        cout << "|        |" << endl;
        cout << "|      " << "K" << " |" << endl;
        cout << " -------- " << endl; usleep(1000000);
        /*cout << "King of " << nameSuit << endl;*/
    }
    else
    {
        
        cout << " -------- " << endl;
        cout << "| " << card << "      |" << endl;
        cout << "|        |" << endl;
        if(suit==1||suit==2)
        {
            cout << "| " << nameSuit << " |" << endl;
        }
        else if(suit==3)
        {
            cout << "|" << nameSuit << "|" << endl;
        }
        else if(suit==4)
        {
            cout << "| " << nameSuit << "  |" << endl;
        }
        cout << "|        |" << endl;
        cout << "|      " << card << " |" << endl;
        cout << " -------- " << endl; usleep(1000000);
        /*cout << card << " of " << nameSuit << endl;*/
    }
}
string Cards::getSuitName()
{
    switch(suit)
    {
        case 1:
            nameSuit="Hearts";
        break;
        case 2:
            nameSuit="Spades";
        break;
        case 3:
            nameSuit="Diamonds";
        break;
        case 4:
            nameSuit="Clubs";
        break;
    }
    return nameSuit;
}
bool Cards::isGiven()
{
    return given;
}
void Cards::setGiven(bool givenInput)
{
    given=givenInput;
}
int Cards::assignNum()
{
    if(card=='A')
    {
        return 11;
    }
    else if(card=='T'||card=='J'||card=='Q'||card=='K')
    {
        return 10;
    }
    else
    {
        return int(card)-48;
    }
}