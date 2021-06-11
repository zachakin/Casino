// CS1300 Fall 2020
// Author: Zach Akin-Amland
// Recitation: 511 - Calista Nguyen
// Project 3 - Slots Class
#include "classes.h"
#include <cstdlib>
using namespace std;

slotsWheel::slotsWheel()
{
    rev[0]=rand()%3+1;
    rev[1]=rand()%3+1;
    rev[2]=rand()%3+1;
    index=0;
}
int slotsWheel::slot1()
{
    index=rand()%3;
    return rev[index];
}
int slotsWheel::slot2()
{
    index=rand()%3;
    return rev[index];
}
int slotsWheel::slot3()
{
    index=rand()%3;
    return rev[index];
}
