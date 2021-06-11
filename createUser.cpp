// CS1300 Fall 2020
// Author: Zach Akin-Amland
// Recitation: 511 - Calista Nguyen
// Project 3 - Create User Class
#include <iostream>
#include <fstream>
#include "classes.h"
#include <string>
#include <cctype>
using namespace std;

createUser::createUser()
{
    username="";
    password="";
    birthDay=0;
    birthMonth=0;
    birthYear=0;
    totalBalance=getBalance2();
}
createUser::createUser(string userName, string passWord, int day, int month, int year, int balance)
{
    username=userName;
    password=passWord;
    birthYear=year;
    birthMonth=month;
    birthDay=day;
    totalBalance=balance;
}
createUser::createUser(string userName, string passWord)
{
    username=userName;
    password=passWord;
    birthDay=getBirthDay();
    birthMonth=getBirthMonth();
    birthYear=getBirthYear();
    totalBalance=getBalance2();
}
void createUser::setUsername(string usernameInput)
{
    username=usernameInput;
}
void createUser::setPassword(string passwordInput)
{
    password=passwordInput;
}
void createUser::setBalance(string balance)
{
    totalBalance=balance;
}
string createUser::getUsername()
{
    return username;
}
string createUser::getPassword()
{
    return password;
}
int createUser::getBirthDay()
{
    /*ifstream file;
    file.open("users.txt");
    char separator=',';
    string line;
    int size=6;
    string arr[size];
    int x;
    while(getline(file,line))
    {
        split(line,separator,arr,size);
        if(username==arr[0])
        {
            birthDay=stoi(arr[2]);
        }
    }
    file.close();*/
    return birthDay;
}
int createUser::getBirthMonth()
{
    /*ifstream file;
    file.open("users.txt");
    char separator=',';
    string line;
    int size=6;
    string arr[size];
    int x;
    while(getline(file,line))
    {
        split(line,separator,arr,size);
        if(username==arr[0])
        {
            birthMonth=stoi(arr[3]);
        }
    }
    file.close();*/
    return birthMonth;
}
int createUser::getBirthYear()
{
    /*ifstream file;
    file.open("users.txt");
    char separator=',';
    string line;
    int size=6;
    string arr[size];
    int x;
    while(getline(file,line))
    {
        split(line,separator,arr,size);
        if(username==arr[0])
        {
            birthYear=stoi(arr[4]);
        }
    }
    file.close();*/
    return birthYear;
}
void createUser::createUsername(string temp, createUser newUser)
{
    temp="";
    cout << "Create a username:" << endl;
    getline(cin,temp);
    if(temp.length()==0)
    {
        cout << "Username cannot be empty. Please try again." << endl;
        createUsername(temp,newUser);
    }
    else if(findUser(temp)>=0)
    {
        cout<<"Username already exists. Please try again." << endl;
        createUsername(temp,newUser);
    }
    else
    {
        username = temp;
    }
}
void createUser::createPassword(string temp, createUser newUser)
{
    temp="";
    cout << "Create a password:" << endl;
    getline(cin,temp);
    if(temp.length()<3)
    {
        cout << "Password too short. Please try again." << endl;
        createPassword(temp,newUser);
    }
    else
    {
        password=temp;
    }
}
void createUser::createBirthMonth(string temp, createUser newUser, int x)
{
    temp="";
    cout << "What month were you born? (1-12)" << endl;
    getline(cin,temp);
    if(isNumber(temp)==true)
    {
        x = stoi(temp);
        if(x<1||x>12)
        {
            cout << "Month must be from 1 to 12. Please try again." << endl;
            createBirthMonth(temp,newUser,x);
        }
        else
        {
            birthMonth=x;
        }
    }
    else
    {
        cout << "Month must be a number from 1 to 12. Please try again." << endl;
        createBirthMonth(temp,newUser,x);
    }
}
void createUser::createBirthDay(string temp, createUser newUser, int x)
{
    temp="";
    cout << "What day were you born? (1-31)" << endl;
    getline(cin,temp);
    if(isNumber(temp)==true)
    {
        x = stoi(temp);
        if(x<1||x>31)
        {
            cout << "Day must be from 1 to 31. Please try again." << endl;
            createBirthDay(temp,newUser,x);
        }
        else
        {
            birthDay=x;
        }
    }
    else
    {
        cout << "Day must be a number from 1 to 31. Please try again." << endl;
        createBirthDay(temp,newUser,x);
    }
}
void createUser::createBirthYear(string temp, createUser newUser, int x)
{
    temp="";
    cout << "What year were you born? (XXXX)" << endl;
    getline(cin,temp);
    if(isNumber(temp)==true)
    {
        x = stoi(temp);
        if(x<1900||x>2020)
        {
            cout << "Year must be from 1900 to 2020. Please try again." << endl;
            createBirthYear(temp,newUser,x);
        }
        else
        {
            birthYear=x;
        }
    }
    else
    {
        cout << "Day must be a number from 1900 to 2020. Please try again." << endl;
        createBirthYear(temp,newUser,x);
    }
}
void createUser::depositBalance(int amount)
{
    int sum;
    int x;
    x=stoi(totalBalance);
    sum=x+amount;
    totalBalance=to_string(sum);
    updateBalance();
}
void createUser::withdrawBet(int amount)
{
    int sum;
    int x;
    x=stoi(totalBalance);
    sum=x-amount;
    totalBalance=to_string(sum);
    updateBalance();
}
void createUser::getBalance()
{   
    ifstream file;
    file.open("users.txt");
    char separator=',';
    string line;
    int size=6;
    string arr[size];
    while(getline(file,line))
    {
        split(line,separator,arr,size);
        if(arr[0]==getUsername())
        {
            totalBalance=arr[5];
        }
    }
    file.close();
    cout << "Your Balance: $" << totalBalance << endl;
}
string createUser::getBalance2()
{   
    ifstream file;
    file.open("users.txt");
    char separator=',';
    string line;
    int size=6;
    string arr[size];
    while(getline(file,line))
    {
        split(line,separator,arr,size);
        if(arr[0]==getUsername())
        {
            totalBalance=arr[5];
        }
    }
    file.close();
    return totalBalance;
}
void createUser::updateBalance()
{
    ifstream file;
    ofstream usersOut;

    vector<string> data;

    char separator=',';
    string line;
    int size=6;
    string arr[size];
    
    int x;
    string info;
    string str;

    file.open("users.txt");

    while(getline(file,line))
    {
        split(line,separator,arr,size);
        if(getUsername()!=arr[0]&&line.length()!=0)
        {
            info = arr[0] + "," + arr[1] + "," + arr[2] + "," + arr[3] + "," + arr[4] + "," + arr[5];
            data.push_back(info);
        }
    }
    file.close();
    file.open("users.txt");
    while(getline(file,line))
    {
        split(line,separator,arr,size);
        if(getUsername()==arr[0])
        {
            arr[5]=totalBalance;
            str = arr[0] + "," + arr[1] + "," + arr[2] + "," + arr[3] + "," + arr[4] + "," + arr[5];
            
        }
    }
    file.close();
    usersOut.open("users.txt", ofstream::out | ofstream::trunc);
    usersOut.close();
    usersOut.open("users.txt",ios::app);
    for(int i=0;i<data.size();i++)
    {
        usersOut << data.at(i) << endl;
    }
    usersOut << str << endl;
    usersOut.close();
}

int createUser::split(string line, char separtator, string myLine[], int size)
{
    int i=0;
    int j=0;
    string temp="";
    if(line=="")
    {
        return 0;
    }
    line = line + separtator;
    int lineSize = line.length();
    for(i=0;i<lineSize;i++)
    {
        if(line[i]!=separtator)
        {
            temp+=line[i];
        }
        else
        {
            myLine[j]=temp;
            j++;
            temp="";
        }
    }
    return j;
}

int createUser::findUser(string userName)
{
    string line;
    int index=0;
    char separator=',';
    int size=6;
    string myLine[size];
    ifstream usersFile;
    usersFile.open("users.txt");
    if(usersFile.is_open())
    {
        while(getline(usersFile,line))
        {
            split(line,separator,myLine,size);
            if(myLine[0]==userName)
            {
                usersFile.close();
                return index;
            }
            index++;
        }
    }
    else
    {
        usersFile.close();
        return -1;
    }
    usersFile.close();
    return -1;
}

bool createUser::isNumber(string temp)
{
    int count=0;
    for(int i=0;i<temp.length();i++)
    {
        if(isdigit(temp[i]))
        {
            count++;
        }
    }
    if(count==temp.length())
    {
        return true;
    }
    else
        return false;
}

int createUser::getNumUsers()
{
    string line;
    int userCount=0;
    ifstream usersFile;
    usersFile.open("users.txt");
    if(usersFile.is_open())
    {
        while(getline(usersFile,line))
        {
            userCount++;
        }
    }
    usersFile.close();
    return userCount;
}
void createUser::depositSimulatedEarnings(int amount)
{
    int sum;
    int x;
    x=stoi(totalBalance);
    sum=x+amount;
    totalBalance=to_string(sum);
    updateSimulatedBalance();
}
void createUser::getSimulatedBalance()
{   
    ifstream file;
    file.open("usersSimulated.txt");
    char separator=',';
    string line;
    int size=6;
    string arr[size];
    while(getline(file,line))
    {
        split(line,separator,arr,size);
        if(arr[0]==getUsername())
        {
            totalBalance=arr[1];
        }
    }
    file.close();
    cout << "Your Balance: $" << totalBalance << endl;
}
string createUser::getSimulatedBalance2()
{   
    ifstream file;
    file.open("usersSimulated.txt");
    char separator=',';
    string line;
    int size=6;
    string arr[size];
    while(getline(file,line))
    {
        split(line,separator,arr,size);
        if(arr[0]==getUsername())
        {
            totalBalance=arr[1];
        }
    }
    file.close();
    return totalBalance;
}
void createUser::updateSimulatedBalance()
{
    ifstream file;
    ofstream usersOut;

    vector<string> data;

    char separator=',';
    string line;
    int size=6;
    string arr[size];
    
    int x;
    string info;
    string str;

    file.open("usersSimulated.txt");

    while(getline(file,line))
    {
        split(line,separator,arr,size);
        if(getUsername()!=arr[0]&&line.length()!=0)
        {
            info = arr[0] + "," + arr[1];
            data.push_back(info);
        }
    }
    file.close();
    file.open("usersSimulated.txt");
    while(getline(file,line))
    {
        split(line,separator,arr,size);
        if(getUsername()==arr[0])
        {
            arr[1]=totalBalance;
            str = arr[0] + "," + arr[1];
            
        }
    }
    file.close();
    usersOut.open("usersSimulated.txt", ofstream::out | ofstream::trunc);
    usersOut.close();
    usersOut.open("usersSimulated.txt",ios::app);
    for(int i=0;i<data.size();i++)
    {
        usersOut << data.at(i) << endl;
    }
    usersOut << str << endl;
    usersOut.close();
}

