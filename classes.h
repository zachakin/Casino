// CS1300 Fall 2020
// Author: Zach Akin-Amland
// Recitation: 511 - Calista Nguyen
// Project 3 - Classes
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <unistd.h>
#ifndef classes_h
#define classes_h
using namespace std;

class createUser
{
    public:
        createUser();
        createUser(string userName, string passWord, int day, int month, int year, int balance);
        createUser(string userName, string passWord);

        int split(string line, char separator, string myLine[], int size);
        int findUser(string userName);
        bool isNumber(string temp);
        int getNumUsers();

        void setUsername(string usernameInput);
        void setPassword(string passwordInput);
        void setBirthDay(int day); 
        void setBirthMonth(int month);
        void setBirthYear(int year);

        string getUsername();
        string getPassword();
        int getBirthDay();
        int getBirthMonth();
        int getBirthYear();

        void createUsername(string temp, createUser newUser);
        void createPassword(string temp, createUser newUser);
        void createBirthDay(string temp, createUser newUser, int x);
        void createBirthMonth(string temp, createUser newUser, int x);
        void createBirthYear(string temp, createUser newUser, int x);

        void getBalance();
        string getBalance2();
        void setBalance(string balance);
        void depositBalance(int amount);
        void withdrawBet(int amount);
        void updateBalance();

        void getSimulatedBalance();
        string getSimulatedBalance2();
        void depositSimulatedEarnings(int amount);
        void updateSimulatedBalance();
        
    private:
        string username;
        string password;
        int birthDay;
        int birthMonth;
        int birthYear;
        string totalBalance;
};

class Cards
{
    public:
        Cards(char cardInput, int suitInput);
        char getCard();
        int getNum();
        int getSuit();
        string getSuitName();
        bool isGiven();
        void setGiven(bool givenInput);
        void nameCard();
    private:
        char card; // 'A' ,'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'
        int num; //1 or 11 , 2 , 3 , 4, 5 , 6 , 7 , 8 , 9, 10, 10, 10, 10
        int suit; //1 hearts, 2 spades, 3 diamonds, 4 clubs
        string nameSuit;
        bool given; //Check if it's been wether given or not. works as an index
        int assignNum();
};

class Deck
{
    public:
        Deck();
        void fill(); //fills Deck
        void shuffle(); //shuffles Deck
        Cards giveCard();
        void readDeck();
    private:
        vector<Cards> deck;
};

class Hand
{
    public:
        void cardIn(Cards,Cards);
        void showCard();
        void showDealerCard();
        void addCard(Cards card);
        void addSimulatedCard(Cards card);
        int numCards();
        int total();
    private:
        vector<Cards> hand;
        int totalSum;
};

class Player
{
    public:
        Player();
        Player(Deck deck);
        void showCards();
        int total();
        void stay();
        void hit();
        bool win();
        bool lose();
        void hitSimulated();
        void staySimulated();
    protected:
        Deck deck;
        Hand playerHand;
        bool draw;
        int totalSum;

};

class Dealer: public Player
{
    public:
        Dealer(Player) : Player(Deck()){};
        void dealerCard();
        int play(Player);
        int playSimulated(Player);
};

class slotsWheel
{
    public:
        slotsWheel();
        int slot1();
        int slot2();
        int slot3();
    private:
        int rev[3];
        int index;
};

class rouletteSpin
{
    public:
        rouletteSpin(int randomNum);
        int getNum();
        void showNum();
        string getColor();
        int getHalf();
        int getDozen();
        int getRow();
        bool isRed();
        bool isBlack();
        bool isGreen();
        bool isHalf1();
        bool isHalf2();
        bool isDozen1();
        bool isDozen2();
        bool isDozen3();
        bool isRow1();
        bool isRow2();
        bool isRow3();
    private:
        int num;
        string color;
        int row;
        int half;
        int dozen;
};

class Game
{
    public:
        Game();
        Game(int numUsers);

        void run();
        
        int findUser(string userName);
        bool isNumber(string temp);
        int getNumUsers();
        createUser logIn(createUser currentUser);
        createUser createNewUser(createUser currentUser);
        createUser createSimulatedUser(createUser currentUser, int numUsersStored);
        bool slotMachine();
        int blackjack();
        int intro();
        int roulette();
        void showLeaderboard();
        void printMenu(createUser currentUser);

        void play();
        void simulate(int numUsersInput);
        void simulatePlay(createUser currentUser);
        int slotMachineSimulate();
        int blackjackSimulate();
        int rouletteSimulate();
        void showSimulatedLeaderboard(int numUsersInput);


    private:
        int numUsers;
        createUser users[100];
};

#endif