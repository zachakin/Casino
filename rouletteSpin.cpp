// CS1300 Fall 2020
// Author: Zach Akin-Amland
// Recitation: 511 - Calista Nguyen
// Project 3 - Roulette Class
#include <iostream>
#include <string>
#include "classes.h"
using namespace std;

rouletteSpin::rouletteSpin(int randomNum)
{
    num=randomNum;
    color=getColor();
    half=getHalf();
    dozen=getDozen();
    row=getRow();

}
int rouletteSpin::getNum()
{
    return num;
}
void rouletteSpin::showNum()
{
    cout << color << " " << num << endl;
}
string rouletteSpin::getColor()
{
    if(isRed()==true)
    {
        color="Red";
    }
    else if(isBlack()==true)
    {
        color="Black";
    }
    else if(isGreen()==true)
    {
        color="Green";
    }
    return color;
}
int rouletteSpin::getHalf()
{
    if(isHalf1()==true)
    {
        half=1;
    }
    else if(isHalf2()==true)
    {
        half=2;
    }
    else
    {
        half=0;
    }
    return half;
}
int rouletteSpin::getDozen()
{
    if(isDozen1()==true)
    {
        dozen=1;
    }
    else if(isDozen2()==true)
    {
        dozen=2;
    }
    else if(isDozen3()==true)
    {
        dozen=3;
    }
    else
    {
        dozen=0;
    }
    return dozen;
}
int rouletteSpin::getRow()
{
    if(isRow1()==true)
    {
        row=1;
    }
    else if(isRow2()==true)
    {
        row=2;
    }
    else if(isRow3()==true)
    {
        row=3;
    }
    else
    {
        row=0;
    }
    return row;
}
bool rouletteSpin::isRed()
{
    int red[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    for(int i=0;i<18;i++)
    {
        if(num==red[i])
        {
            return true;
        }
    }
    return false;
    
}
bool rouletteSpin::isBlack()
{
    int black[18]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
    for(int i=0;i<18;i++)
    {
        if(num==black[i])
        {
            return true;
        }
    }
    return false;
}
bool rouletteSpin::isGreen()
{
    int green=0;
    if(num==green)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
bool rouletteSpin::isHalf1()
{
    if(num>=1&&num<=18)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool rouletteSpin::isHalf2()
{
    if(num>=19&&num<=36)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool rouletteSpin::isDozen1()
{
    if(num>=1&&num<=12)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool rouletteSpin::isDozen2()
{
    if(num>=13&&num<=24)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool rouletteSpin::isDozen3()
{
    if(num>=25&&num<=36)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool rouletteSpin::isRow1()
{
    int row1[12]={1,4,7,10,13,16,19,22,25,28,31,34};
    for(int i=0;i<12;i++)
    {
        if(num==row1[i])
        {
            return true;
        }
    }
    return false;
}
bool rouletteSpin::isRow2()
{
    int row2[12]={2,5,8,11,14,17,20,23,26,29,32,35};
    for(int i=0;i<12;i++)
    {
        if(num==row2[i])
        {
            return true;
        }
    }
    return false;
}
bool rouletteSpin::isRow3()
{
    int row3[12]={3,6,9,12,15,18,21,24,27,30,33,36};
    for(int i=0;i<12;i++)
    {
        if(num==row3[i])
        {
            return true;
        }
    }
    return false;
}