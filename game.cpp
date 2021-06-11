// CS1300 Fall 2020
// Author: Zach Akin-Amland
// Recitation: 511 - Calista Nguyen
// Project 3 - Game class
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>
#include "classes.h"
#include "split.cpp"
using namespace std;

Game::Game()
{
    numUsers=1;
    createUser users[1];
}
Game::Game(int numUsersInput)
{
    numUsers=numUsersInput;
    createUser users[numUsers];
}
void Game::play()
{
    users[0]=createUser();
    string option;
    int x;
    bool logInSuccess=false;
    bool newUserSuccess=false;
    string line;
    ifstream playFile;
    playFile.open("play.txt");
    while(getline(playFile,line))
    {
        cout << "                                   " << line << endl;
    }
    playFile.close();
    

    cout << "                               ___________________________________" << endl;
    cout << "                               |                                 |" << endl;
    cout << "                               |        Choose an option:        |" << endl;
    cout << "                               |                                 |" << endl;
    cout << "                               |           1. Log In             |" << endl;
    cout << "                               |                                 |" << endl;
    cout << "                               |        2. Create New User       |" << endl;
    cout << "                               |                                 |" << endl;
    cout << "                               |       3. Return to Main Menu    |" << endl;
    cout << "                               |_________________________________|" << endl;
    cout << endl;
    getline(cin,option);
    x=stoi(option);
    switch(x)
    {
        case 1:
            users[0]=logIn(users[0]);
            if(users[0].getUsername()=="")
            {
                play();
            }
            else
            {
                printMenu(users[0]);
            }    
        break;
        case 2:
            users[0]=createNewUser(users[0]);
            if(users[0].getUsername()=="")
            {
                play();
            }
            else
            {
                cout << "You get a bonus of $1000 for being a new user!" << endl;
                cout << endl;
                //Add New User bonus of $1000
                printMenu(users[0]);
            }
        break;
        case 3:
            return;
        break;
        default:
            cout << "Invalid option. Please try again." << endl;
            play();
        break;
    }
    return;
}
void Game::simulate(int numUsersInput)
{
    ofstream usersOut;
    usersOut.open("usersSimulated.txt", ofstream::out | ofstream::trunc); //clears file
    usersOut.close();
    for(int i=0;i<numUsersInput;i++)
    {
        users[i]=createSimulatedUser(users[i],i+1);
        simulatePlay(users[i]);
    }
    showSimulatedLeaderboard(numUsersInput);
}
int Game::findUser(string userName)
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

bool Game::isNumber(string temp)
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

int Game::getNumUsers()
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

createUser Game::logIn(createUser currentUser)
{
    ifstream usersFile;
    bool valid=false;
    usersFile.open("users.txt");
    if(usersFile.is_open())
    {
        while(valid==false)
        {
            usersFile.close();
            usersFile.open("users.txt");
            string temp="";
            string temp2="";
            string birthday;
            string line="";
            string option;
            string rememberPassword;
            bool correctPassword=false;
            bool correctBirthday=false;
            char separator=',';
            char separator2='/';
            int size=6;
            int x;
            string myLine[size];
            int size2=3;
            string birthdays[size2];
            cout << endl;
            temp="";
            temp2="";
            cout << "Enter username:"<< endl;
            getline(cin,temp);
            if(findUser(temp)>=0)
            { 
                cout << "Enter password:" << endl;
                getline(cin,temp2);
                line="";
                while(getline(usersFile,line))
                {
                    split(line,separator,myLine,size);
                    if(myLine[0]==temp&&myLine[1]==temp2)
                    {
                        correctPassword=true;
                    }
                }
                if(correctPassword==false)
                {
                    cout << "Incorrect password. Choose option 1 or 2:" << endl;
                    cout << "1. Try again" << endl;
                    cout << "2. Forgot password" << endl;
                    getline(cin,option);
                    x=stoi(option);
                    switch(x)
                    {
                        case 1:
                            valid=false;
                        break;
                        case 2:
                            cout << "What month, day, and year were you born? (XX/XX/XXXX)" << endl;
                            getline(cin,birthday);
                            split(birthday,separator2,birthdays,size2);
                            usersFile.clear();
                            usersFile.seekg(0);
                            while(getline(usersFile,line))
                            {
                                split(line,separator,myLine,size);
                                if(myLine[0]==temp)
                                {
                                    if(myLine[3]==birthdays[0]&&myLine[2]==birthdays[1]&&myLine[4]==birthdays[2])
                                    {
                                        correctBirthday=true;
                                    }
                                }
                            }
                            if(correctBirthday==false)
                            {
                                usersFile.close();
                                cout << endl << "Incorrect birthday. Please try again or create a new user." << endl << endl; 
                                return currentUser;
                            }
                            else
                            {
                                usersFile.clear();
                                usersFile.seekg(0);
                                while(getline(usersFile,line))
                                {
                                    split(line,separator,myLine,size);
                                    if(myLine[0]==temp)
                                    {
                                        rememberPassword=myLine[1];
                                    }
                                }
                                cout << endl << "Birthday correct. Your password is:" << endl;
                                cout << rememberPassword << endl;
                                cout << endl;
                                correctPassword=true;
                            }
                        break;
                        default:
                            cout << "Invalid option. Please try again." << endl;
                            valid=false;
                        break;
                    }
                }
                if(correctPassword==true)
                {
                    currentUser=createUser(temp,temp2);
                    usersFile.close();
                    cout << "Welcome " << currentUser.getUsername() << "!" << endl;
                    valid=true;
                    return currentUser;
                }
            }
            else
            {
                cout << "Username not found. Please try again." << endl;
                valid=false;
            }
        }
    }
    else
    {
        return currentUser;
    }
    return currentUser;
}

createUser Game::createNewUser(createUser currentUser)
{
    string temp;
    ofstream usersOut;
    int x;
    string line;
    string info;
    int numUsers=0;
    createUser newUser=createUser();

    cout << endl;
    cout << "Are you a new user? (Yes or No)" << endl;
    getline(cin,temp);
    if(temp=="Yes"||temp=="yes")
    {
        newUser.createUsername(temp,newUser);
        newUser.createPassword(temp,newUser);
        newUser.createBirthMonth(temp,newUser,x);
        newUser.createBirthDay(temp,newUser,x);
        newUser.createBirthYear(temp,newUser,x);
        cout << endl;
        cout << "User created successfully! Welcome " << newUser.getUsername() << "!" << endl;
        newUser.setBalance("1000");
        usersOut.open("users.txt", ios::app);
        info = newUser.getUsername() + "," + newUser.getPassword() + "," + to_string(newUser.getBirthDay()) + "," + to_string(newUser.getBirthMonth()) + "," + to_string(newUser.getBirthYear()) + "," + newUser.getBalance2();
        if(usersOut.is_open())
        {
            numUsers=getNumUsers();
            usersOut << info << endl;
        }
        usersOut.close();
        currentUser=newUser;
        return currentUser;
    }
    else if(temp=="No"||temp=="no"){}
    else
    {
        cout << "Invalid answer. Please try again." << endl;
        createNewUser(currentUser);
    }
    currentUser=createUser();
    return currentUser;
}

createUser Game::createSimulatedUser(createUser currentUser,int numUsersStored)
{
    string temp;
    temp="User"+to_string(numUsersStored);
    ofstream usersOut;
    string info;
    createUser newUser=createUser();
    newUser.setUsername(temp);
    newUser.setBalance("1000");
    usersOut.open("usersSimulated.txt", ios::app);
    info = newUser.getUsername()+','+newUser.getBalance2();
    if(usersOut.is_open())
    {
        usersOut << info << endl;
    }
    usersOut.close();
    currentUser=newUser;
    return currentUser;
}

bool Game::slotMachine()
{
    srand(time(0)); //randomizes combinations of numbers that appear
    slotsWheel slots[3];

    int winningNumbers[3];

    int bet=0;
    string betInput;

    for(int time=3;time>0;time--) //controls how many times the slot rolls
    {
        cout << "                                              ";
        for(int i=0;i<3;i++)
        {
            cout << slots[i].slot1() << " ";
        }
        cout << endl;
        usleep(500000);
        cout << "                                              ";
        for(int i=0;i<3;i++) 
        {
            cout << slots[i].slot2() << " "; 
        }
        cout << endl;
        cout << "                                              ";
        usleep(500000);
        for(int i=0;i<3;i++)
        {
            if(time==1)
            {
                winningNumbers[i]=slots[i].slot3();
                if(i==2)
                {
                    cout << winningNumbers[0] << "-"; 
                    cout << winningNumbers[1] << "-"; 
                    cout << winningNumbers[2];
                }
            }
            else
            {
                cout << slots[i].slot3() << " ";
            }
        }
        cout << endl;
        usleep(500000);
    }
    if (winningNumbers[0]==winningNumbers[1]&&winningNumbers[0]==winningNumbers[2])
    {
        cout << endl;
        cout << "                                          You win!" << endl;
        return true;
    }
    else
    {
        cout << endl;
        cout << "                                          You lose :(" << endl;
        return false;
    }
}

int Game::blackjack()
{
    srand(time(0));

    Deck deck=Deck();
    for(int i=0;i<rand()%100;i++)
    {
        deck=Deck();
    }
    Player player(deck);
    Dealer dealer(deck);

    int x;
    int attempt=1;
    string input;
    int result;

    player.showCards();
    while(x!=2)
    {
        cout << "Your total: " << player.total() << endl << endl;
        dealer.dealerCard(); cout << endl;
        if(attempt==1&&player.win()==true)
        {
            return 2;
        }
        if(player.win()==true)
        {
            return 1;
        }
        if(player.lose()==true)
        {
            return -1;
        }
        cout << "What would you like to do?" << endl << "1. Hit" << endl << "2. Stay" << endl;
        getline(cin,input);
        x=stoi(input);
        switch(x)
        {
            case 1:
                player.hit();
            break;
            case 2:
                player.stay();
                result = dealer.play(player);
                if(result==-1)
                {
                    return -1;
                }
                else if(result==0)
                {
                    return 0;
                }
                else if(result==1)
                {
                    return 1;
                }
            break;
            default:
                cout << "Invalid option" << endl;
            break;
        }
        attempt++;
    }
    return 0;
}

int Game::intro()
{   
    string option;
    int x;
    cout << "Here is the betting table:" << endl;
    cout << endl;
    cout << "|-------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "| Green |  Red  3  | Black  6 |  Red  9  |  Red 12  | Black 15 |  Red 18  |  Red 21  | Black 24 |  Red 27  |  Red 30  | Black 33 |  Red 36  |" << endl;
    cout << "|   0   |-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|-------| Black  2 |  Red  5  | Black  8 | Black 11 |  Red 14  | Black 17 | Black 20 |  Red 23  | Black 26 | Black 29 |  Red 32  | Black 35 |" << endl;
    cout << "| Green |-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|   00  |  Red  1  | Black  4 |  Red  7  | Black 10 | Black 13 |  Red 16  |  Red 19  | Black 22 |  Red 25  | Black 28 | Black 31 |  Red 34  |" << endl;
    cout << "|-------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;
    cout << "How you you like to bet?" << endl; cout << endl; usleep(1500000);
    cout << "1. 0 or 00 [Payout 35 to 1]" << endl; cout << endl; usleep(500000);
    cout << "2. A number 1-36 [Payout 35 to 1]" << endl; cout << endl;usleep(500000);
    /*cout << "3. Any two adjoining numbers vertical or horizontal (8,11 or 2,5 etc.) [Payout 17 to 1]" << endl; cout << endl; usleep(500000);
    cout << "4. Any three numbers in a column (1,2,3 or 4,5,6 etc.) [Payout 11 to 1]" << endl; cout << endl; usleep(500000);
    cout << "5. Any four numbers joined by a corner (1,2,4,5 or 10,11,13,14 etc.) [Payout 8 to 1]" << endl; cout << endl;usleep(500000);*/
    cout << "3. Basket (1, 2, 3, 0, or 00) [Payout 6 to 1]" << endl;cout << endl;usleep(500000);
    /*cout << "7. Any six numbers from two columns (1,2,3,4,5,6 or 28,29,30,31,32,33 etc.) [Payout 5 to 1]" << endl; cout << endl;usleep(500000);*/
    cout << "4. First row (1,4,7,10,13... etc.) [Payout 2 to 1]" << endl; cout << endl;usleep(500000);
    cout << "5. Second row (2,5,8,11,14... etc.) [Payout 2 to 1]" << endl; cout << endl;usleep(500000);
    cout << "6. Third row (3,6,9,12,15... etc.) [Payout 2 to 1]" << endl; cout << endl;usleep(500000);
    cout << "7. First dozen (1-12) [Payout 2 to 1]" << endl; cout << endl;usleep(500000);
    cout << "8. Second dozen (13-24) [Payout 2 to 1]" << endl; cout << endl;usleep(500000);
    cout << "9. Third dozen (25-36) [Payout 2 to 1]" << endl; cout << endl;usleep(500000);
    cout << "10. Odd (1,3,5,7...35) [Payout 1 to 1]" << endl; cout << endl;usleep(500000);
    cout << "11. Even (2,4,6,8...36) [Payout 1 to 1]" << endl; cout << endl;usleep(500000);
    cout << "12. Red [Payout 1 to 1]" << endl; cout << endl;usleep(500000);
    cout << "13. Black [Payout 1 to 1]" << endl; cout << endl;usleep(500000);
    cout << "14. First half (1-18) [Payout 1 to 1]" << endl; cout << endl;usleep(500000);
    cout << "15. Second half (19-36) [Payout 1 to 1]" << endl;usleep(500000);
    cout << endl;
    cout << "Choose an option 1-15:" << endl;
    getline(cin,option); cout << endl;
    x=stoi(option);
    return x;
}

int Game::roulette()
{
    srand(time(0));
    string num;
    int x;
    int randomNum=rand()%38-1;

    bool valid;

    char separator=',';
    string str;
    int size=2;
    string pair[size];

    rouletteSpin spin=rouletteSpin(randomNum);
    do
    {
        switch(intro())
        {
            case 1:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                valid=true;
                if(spin.getNum()==0||spin.getNum()==-1)
                {
                    return 35;
                }
                else
                {
                    return 0;
                }
            break;
            case 2:
                valid=true;
                cout << "Pick a number 1-36" << endl;
                getline(cin,num);
                x=stoi(num);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.getNum()==x)
                {
                    return 35;
                }
                else
                {
                    return 0;
                }
            case 3:
                valid=true;
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.getNum()==-1||spin.getNum()==0||spin.getNum()==1||spin.getNum()==2||spin.getNum()==3)
                {
                    return 6;
                }
                else
                {
                    return 0;
                }
            break;
            case 4:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.isRow1()==true)
                {
                    return 2;
                }
                else
                {
                    return 0;
                }
                valid=true;
            break;
            case 5:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.isRow2()==true)
                {
                    return 2;
                }
                else
                {
                    return 0;
                }
                valid=true;
            break;
            case 6:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.isRow3()==true)
                {
                    return 2;
                }
                else
                {
                    return 0;
                }
                valid=true;
            break;
            case 7:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.isDozen1()==true)
                {
                    return 2;
                }
                else
                {
                    return 0;
                }
                valid=true;
            break;
            case 8:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.isDozen2()==true)
                {
                    return 2;
                }
                else
                {
                    return 0;
                }
                valid=true;
            break;
            case 9:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.isDozen3()==true)
                {
                    return 2;
                }
                else
                {
                    return 0;
                }
                valid=true;
            break;
            case 10:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.getNum()%2!=0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                valid=true;
            break;
            case 11:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.getNum()%2==0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                valid=true;
            break;
            case 12:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.isRed()==true)
                {
                    return 1;
                }       
                else
                {
                    return 0;
                }
                valid=true;
            break;
            case 13:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.isBlack()==true)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                valid=true;
            break;
            case 14:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.isHalf1()==true)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                valid=true;
            break;
            case 15:
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                            Spinning..." << endl; usleep(500000);
                cout << "                                         Still Spinning..." << endl; usleep(500000);
                cout << "                                         The number is:" << endl;
                cout <<"                                             ";spin.showNum(); usleep(1000000);
                if(spin.isHalf2()==true)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                valid=true;
            break;
            default:
                cout << "Invalid option" << endl;
                valid=false;
            break;
        }
    } while (!valid);
    return 0;
}

void Game::showLeaderboard()
{
    ifstream leaderboardFile;
    string line;
    char separator=',';
    int size=6;
    string myLine[size];

    int numUsers=getNumUsers();
    int u;
    int i=0;

    vector<pair<int,string> > namesAndBalances;

    ifstream file;
    file.open("users.txt");

    while(getline(file,line))
    {
        split(line,separator,myLine,size);
        u=stoi(myLine[5]);
        namesAndBalances.push_back(make_pair(u,myLine[0]));
        i++;
    }
    sort(namesAndBalances.rbegin(),namesAndBalances.rend());
    leaderboardFile.open("leaderboard.txt");
    while(getline(leaderboardFile,line))
    {
        cout << "             " << line << endl;
    }
    cout << endl;
    leaderboardFile.close();
    for(int k=1;k<numUsers+1;k++)
    {
        cout << "                                          "<< k << ". " <<  namesAndBalances[k-1].second << " $" << namesAndBalances[k-1].first << endl;
        cout << endl;
    }
}

void Game::printMenu(createUser currentUser)
{
    string option;
    int x;
    int j;
    int n;
    string bet;
    int result;
    int rouletteResult;
    string line;
    ifstream playFile;
    ifstream slotsText;
    ifstream blackjackText;
    ifstream rouletteText;

    while(x!=5)
    {
        playFile.open("play.txt");
        while(getline(playFile,line))
        {
            cout << "                                   " << line << endl;
        }
        playFile.close();
        cout << endl; cout << "                                       "; currentUser.getBalance(); cout << endl;
        cout << "                               ___________________________________" << endl;
        cout << "                               |                                 |" << endl;
        cout << "                               |        Choose an option:        |" << endl;
        cout << "                               |                                 |" << endl;
        cout << "                               |        1. Show leaderboard      |" << endl;
        cout << "                               |                                 |" << endl;
        cout << "                               |          2. Play Slots          |" << endl;
        cout << "                               |                                 |" << endl;
        cout << "                               |        3. Play Blackjack        |" << endl;
        cout << "                               |                                 |" << endl;
        cout << "                               |         4. Play Roulette        |" << endl;
        cout << "                               |                                 |" << endl;
        cout << "                               |            5. Log Out           |" << endl;
        cout << "                               |_________________________________|" << endl;
        cout << endl;
        getline(cin,option);
        x=stoi(option);
        switch(x)
        {
            case 1:
                showLeaderboard();
            break;
            case 2:
                j=0;
                slotsText.open("slots.txt");
                while(getline(slotsText,line))
                {
                    cout << "                          " << line << endl;
                }
                slotsText.close();
                cout << endl; cout << "                                     Get 3 in a row to win!" << line << endl; 
                cout << endl; cout << "                                      "; currentUser.getBalance(); cout << endl;
                while(j!=2)
                {
                    cout << "                                 How much would you like to bet?" << endl;
                    getline(cin,bet);
                    n=stoi(bet);
                    while(n<1||n>stoi(currentUser.getBalance2()))
                    {
                        cout << "                         Invalid bet. Please enter a different ammount." << endl;
                        cout << endl; cout << "                                       "; currentUser.getBalance(); cout << endl;
                        getline(cin,bet);
                        n=stoi(bet);
                    }
                    cout << endl;
                    //getline how much they would like to bet
                    //if bet>balance ask for a lower amount
                    if(slotMachine()==true)
                    {
                        currentUser.depositBalance(n);
                        cout << endl; cout << "                                      "; currentUser.getBalance(); cout << endl;
                        cout << "                               ___________________________________" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |        Choose an option:        |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |          1. Play Again          |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |      2. Return to Play Menu     |" << endl;
                        cout << "                               |_________________________________|" << endl;
                        cout << endl;
                        getline(cin,option);
                        j=stoi(option); 
                        //double bet and add to balance
                        //print new balance
                        //give option to play again or go to main menu
                    }
                    else
                    {
                        currentUser.withdrawBet(n);
                        cout << endl; cout << "                                      "; currentUser.getBalance(); cout << endl;
                        cout << "                               ___________________________________" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |        Choose an option:        |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |          1. Play Again          |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |      2. Return to Play Menu     |" << endl;
                        cout << "                               |_________________________________|" << endl;
                        cout << endl;
                        getline(cin,option);
                        j=stoi(option); 
                        //subtract bet from balance
                        //print new balance
                        //give option to play again or go to main menu
                    }
                }
            break;
            case 3:
                j=0;
                blackjackText.open("blackjack.txt");
                while(getline(blackjackText,line))
                {
                    cout << "                        " << line << endl;
                }
                blackjackText.close();
                cout << endl; cout << "                                       "; currentUser.getBalance(); cout << endl;
                //find user that is logged in balance
                while(j!=2)
                {
                    cout << "                                 How much would you like to bet?" << endl;
                    getline(cin,bet);
                    x=stoi(bet);
                    while(x<1||x>stoi(currentUser.getBalance2()))
                    {
                        cout << "                         Invalid bet. Please enter a different ammount." << endl;
                        cout << endl; cout << "                                       "; currentUser.getBalance(); cout << endl;
                        getline(cin,bet);
                        x=stoi(bet);
                    }
                    cout << endl;
                    //getline how much they would like to bet
                    //if bet>balance ask for a lower amount
                    result=blackjack();
                    if(result==1)
                    {
                        cout << "You won $" << x << endl;
                        currentUser.depositBalance(x);
                        cout << endl; cout << "                                      "; currentUser.getBalance(); cout << endl;
                        cout << "                               ___________________________________" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |        Choose an option:        |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |          1. Play Again          |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |      2. Return to Play Menu     |" << endl;
                        cout << "                               |_________________________________|" << endl;
                        cout << endl;
                        getline(cin,option);
                        j=stoi(option); 
                        
                    }
                    else if(result==-1)
                    {
                        currentUser.withdrawBet(x);
                        cout << "You lose :(" << endl;
                        cout << endl; cout << "                                      "; currentUser.getBalance(); cout << endl;
                        cout << "                               ___________________________________" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |        Choose an option:        |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |          1. Play Again          |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |      2. Return to Play Menu     |" << endl;
                        cout << "                               |_________________________________|" << endl;
                        cout << endl;
                        getline(cin,option);
                        j=stoi(option); 
                    }
                    else if(result==0)
                    {
                        cout << endl; cout << "                                      "; currentUser.getBalance(); cout << endl;
                        cout << "                               ___________________________________" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |        Choose an option:        |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |          1. Play Again          |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |      2. Return to Play Menu     |" << endl;
                        cout << "                               |_________________________________|" << endl;
                        cout << endl;
                        getline(cin,option);
                        j=stoi(option); 
                    }
                    else if(result==2)
                    {
                        cout << "You win $" << x*2 << endl;
                        currentUser.depositBalance(x*2);
                        cout << endl; cout << "                                      "; currentUser.getBalance(); cout << endl;
                        cout << "                               ___________________________________" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |        Choose an option:        |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |          1. Play Again          |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |      2. Return to Play Menu     |" << endl;
                        cout << "                               |_________________________________|" << endl;
                        cout << endl;
                        getline(cin,option);
                        j=stoi(option);
                    }
                }
            break;
            case 4:
                j=0;
                rouletteText.open("roulette.txt");
                while(getline(rouletteText,line))
                {
                    cout << "          " << line << endl;
                }
                rouletteText.close();
                cout << endl; cout << "                                       "; currentUser.getBalance(); cout << endl;
                while(j!=2)
                {
                    cout << "                                 How much would you like to bet?" << endl;
                    getline(cin,bet);
                    x=stoi(bet);
                    while(x<1||x>stoi(currentUser.getBalance2()))
                    {
                        cout << "                         Invalid bet. Please enter a different ammount." << endl;
                        cout << endl; cout << "                                       "; currentUser.getBalance(); cout << endl;
                        getline(cin,bet);
                        x=stoi(bet);
                    }
                    cout << endl;
                    rouletteResult=roulette();
                    if(rouletteResult==0)
                    {
                        cout << "                                           You lose :(" << endl;
                        currentUser.withdrawBet(x);
                        cout << endl; cout << "                                      "; currentUser.getBalance(); cout << endl;
                        cout << "                               ___________________________________" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |        Choose an option:        |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |          1. Play Again          |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |      2. Return to Play Menu     |" << endl;
                        cout << "                               |_________________________________|" << endl;
                        cout << endl;
                        getline(cin,option);
                        j=stoi(option);
                    }
                    else
                    {
                        cout << "                                            You win!" << endl;
                        cout << "                                          You won $" << x*rouletteResult << endl;
                        currentUser.depositBalance(x*rouletteResult);
                        cout << endl; cout << "                                      "; currentUser.getBalance(); cout << endl;
                        cout << "                               ___________________________________" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |        Choose an option:        |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |          1. Play Again          |" << endl;
                        cout << "                               |                                 |" << endl;
                        cout << "                               |      2. Return to Play Menu     |" << endl;
                        cout << "                               |_________________________________|" << endl;
                        cout << endl;
                        getline(cin,option);
                        j=stoi(option); 
                    }
                }
                 
            break;
            case 5:
            break;
            default:
                cout << "                         Invalid Option. Please try again." << endl;
                printMenu(currentUser);
            break;
        }
    }
}
void Game::simulatePlay(createUser currentUser)
{
    srand(time(0));

    int rouletteResult;
    int bjResult;
    bool slotsResult;
    int winCount=0;
    int loseCount=0;
    int earnings=0;

    for(int p=0;p<3;p++)
    {
        slotsResult=false;
        slotsResult=slotMachineSimulate();
        if(slotsResult==true)
        {
            earnings+=100;
            winCount++;
        }
        else
        {
            earnings-=100;
            loseCount++;
        }
    }
    for(int j=0;j<3;j++)
    {
        bjResult=-3;
        bjResult=blackjackSimulate();
        if(bjResult==1)
        {
            earnings+=100;
            winCount++;
        }
        else if(bjResult==-1)
        {
            earnings-=100;
            loseCount++;
        }
        else if(bjResult==2)
        {
            earnings+=200;
            winCount++;
        }
    }
    for(int y=0;y<3;y++)
    {
        rouletteResult=0;
        rouletteResult=rouletteSimulate();
        if(rouletteResult==0)
        {
            earnings-=100;
            loseCount++;
        }
        else
        {
            earnings=earnings+(100*rouletteResult);
            winCount++;
        } 
    }
    int randomNum=rand()%3+1;
    if(randomNum==1)
    {
        slotsResult=false;
        slotsResult=slotMachineSimulate();
        if(slotsResult==true)
        {
            earnings+=100;
            winCount++;
        }
        else
        {
            earnings-=100;
            loseCount++;
        }
    }
    else if(randomNum==2)
    {
        bjResult=-3;
        bjResult=blackjackSimulate();
        if(bjResult==1)
        {
            earnings+=100;
            winCount++;
        }
        else if(bjResult==-1)
        {
            earnings-=100;
            loseCount++;
        }
        else if(bjResult==2)
        {
            earnings+=200;
            winCount++;
        }
    }
    else
    {
        rouletteResult=0;
        rouletteResult=rouletteSimulate();
        if(rouletteResult==0)
        {
            earnings-=100;
            loseCount++;
        }
        else
        {
            earnings=earnings+(100*rouletteResult);
            winCount++;
        } 
    }
    currentUser.depositSimulatedEarnings(earnings);
    currentUser.setBalance("1000");
}
int Game::slotMachineSimulate()
{
    srand(time(0)); //randomizes combinations of numbers that appear
    slotsWheel slots[3];
    int winningNumbers[3];

    for(int time=3;time>0;time--) //controls how many times the slot rolls
    {
        for(int i=0;i<3;i++)
        {
            slots[i].slot1();
        }
        for(int i=0;i<3;i++) 
        {
            slots[i].slot2();
        }
        for(int i=0;i<3;i++)
        {
            if(time==1)
            {
                winningNumbers[i]=slots[i].slot3();
            }
            else
            {
                slots[i].slot3();
            }
        }
    }
    if (winningNumbers[0]==winningNumbers[1]&&winningNumbers[0]==winningNumbers[2])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Game::blackjackSimulate()
{
    srand(time(0));

    Deck deck=Deck();
    for(int i=0;i<rand()%100;i++)
    {
        deck=Deck();
    }
    Player player(deck);
    Dealer dealer(deck);

    int attempt=1;
    int result;

    if(attempt==1&&player.win()==true)
    {
        return 2;
    }
    if(player.win()==true)
    {
        return 1;
    }
    if(player.lose()==true)
    {
        return -1;
    }
    while(player.total()<17)
    {
        player.hitSimulated();
        attempt++;
    }
    player.staySimulated();
    result = dealer.playSimulated(player);
    if(result==-1)
    {
        return -1;
    }
    else if(result==0)
    {
        return 0;
    }
    else if(result==1)
    {
        return 1;
    }
    return 0;
}

int Game::rouletteSimulate()
{
    srand(time(0));
    int x;
    int n=rand()%15+1;
    int randomNum=rand()%38-1;

    rouletteSpin spin=rouletteSpin(randomNum);
    switch(n)
    {
        case 1:
            if(spin.getNum()==0||spin.getNum()==-1)
            {
                return 35;
            }
            else
            {
                return 0;
            }
        break;
        case 2:
            x=rand()%36+1;
            if(spin.getNum()==x)
            {
                return 35;
            }
            else
            {
                return 0;
            }
        case 3:
            if(spin.getNum()==-1||spin.getNum()==0||spin.getNum()==1||spin.getNum()==2||spin.getNum()==3)
            {
                return 6;
            }
            else
            {
                return 0;
            }
        break;
        case 4:
            if(spin.isRow1()==true)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        break;
        case 5:
            if(spin.isRow2()==true)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        break;
        case 6:
            if(spin.isRow3()==true)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        break;
        case 7:
            if(spin.isDozen1()==true)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        break;
        case 8:
            if(spin.isDozen2()==true)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        break;
        case 9:
            if(spin.isDozen3()==true)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        break;
        case 10:
            if(spin.getNum()%2!=0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        break;
        case 11:
            if(spin.getNum()%2==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        break;
        case 12:
            if(spin.isRed()==true)
            {
                return 1;
            }       
            else
            {
                return 0;
            }
        break;
        case 13:
            if(spin.isBlack()==true)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        break;
        case 14:
            if(spin.isHalf1()==true)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        break;
        case 15:
            if(spin.isHalf2()==true)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        break;
    }
    return 0;
}
void Game::showSimulatedLeaderboard(int numUsersInput)
{
    string line;
    char separator=',';
    int size=2;
    string myLine[size];

    int numUsers=getNumUsers();
    int u;
    int i=0;

    vector<pair<int,string> > namesAndBalances;

    ifstream leaderboardFile;

    ifstream file;
    file.open("usersSimulated.txt");

    while(getline(file,line))
    {
        split(line,separator,myLine,size);
        u=stoi(myLine[1]);
        namesAndBalances.push_back(make_pair(u,myLine[0]));
        i++;
    }
    sort(namesAndBalances.rbegin(),namesAndBalances.rend());
    leaderboardFile.open("leaderboard.txt");
    while(getline(leaderboardFile,line))
    {
        cout << "             " << line << endl;
    }
    cout << endl;
    leaderboardFile.close();
    for(int k=1;k<numUsersInput+1;k++)
    {
        cout << "                                          "<< k << ". " <<  namesAndBalances[k-1].second << " $" << namesAndBalances[k-1].first << endl;
        cout << endl;
    }
}

void Game::run()
{
    Game game;
    srand(time(0));
    string option;
    string choice;
    string choice2;
    int numUsers;
    int x;
    int k;
    int n;
    string line;

    ifstream simulateFile;
    ifstream goodbyeFile;

    ifstream titleFile;
    titleFile.open("zachscasino.txt");
    while(getline(titleFile,line))
    {
        cout << line << endl;
    }
    titleFile.close();

    while(x!=3)
    {
        ifstream mainMenuFile;
        mainMenuFile.open("mainmenu.txt");
        while(getline(mainMenuFile,line))
        {
            cout << "                    " << line << endl;
        }
        mainMenuFile.close();
        cout << "                               ___________________________________" << endl;
        cout << "                               |                                 |" << endl;
        cout << "                               |        Choose an option:        |" << endl;
        cout << "                               |                                 |" << endl;
        cout << "                               |       1. Play Casino Game       |" << endl;
        cout << "                               |                                 |" << endl;
        cout << "                               |      2. Simulate Casino Game    |" << endl;
        cout << "                               |                                 |" << endl;
        cout << "                               |            3. Quit              |" << endl;
        cout << "                               |_________________________________|" << endl;
        cout << endl;
        getline(cin,option);
        x=stoi(option);
        switch(x)
        {
            case 1:
                game=Game();
                game.play();
            break;
            case 2:
                k=0;
                while(k!=3)
                {
                    simulateFile.open("simulate.txt");
                    while(getline(simulateFile,line))
                    {
                        cout << "                       " << line << endl;
                    }
                    simulateFile.close();
                    cout << "                               ___________________________________" << endl;
                    cout << "                               |                                 |" << endl;
                    cout << "                               |        Choose an option:        |" << endl;
                    cout << "                               |                                 |" << endl;
                    cout << "                               |     1. Simulate Random Number   |" << endl;
                    cout << "                               |     of users between 1 and 25   |" << endl;
                    cout << "                               |                                 |" << endl;
                    cout << "                               |      2. Pick number of users    |" << endl;
                    cout << "                               |           to simulate           |" << endl;
                    cout << "                               |                                 |" << endl;
                    cout << "                               |      3. Return to Main Munu     |" << endl;
                    cout << "                               |_________________________________|" << endl;
                    cout << endl;
                    getline(cin,choice);
                    k=stoi(choice);
                    switch(k)
                    {
                        case 1:
                            numUsers=rand()%25+1;
                            game=Game(numUsers);
                            game.simulate(numUsers);
                        break;
                        case 2:
                            cout << "How many users would you like to simulate:" << endl;
                            getline(cin,choice2);
                            n=stoi(choice2);
                            game=Game(n);
                            game.simulate(n);
                        break;
                        case 3:
                        break;
                        default:
                            cout << "Invalid option" << endl;
                        break;
                    }
                }
            break;
            case 3:
                goodbyeFile.open("goodbye.txt");
                while(getline(goodbyeFile,line))
                {
                    cout << "               " << line << endl;
                }
            break;
            default:
                cout << "Invalid option. Please try again" << endl;
            break;
        }
    }
}