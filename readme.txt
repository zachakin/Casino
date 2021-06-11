CS1300 "Programming" Final Project Fall 2020
Author: Zach Akin-Amland

To run the game, navigate to the folder directory of the game files and run:
g++ cards.cpp createUser.cpp deck.cpp game.cpp gameDriver.cpp hand.cpp player.cpp rouletteSpin.cpp slotsWheel.cpp dealer.cpp

Project Description:
This is a casino type mini game that allows users to play or simulate players in a casino.
The user has the option to sign up, log in, or simulate play.

If the user chooses to sign up or log in, the have the option to see the users' leaderboard,
play slots, play roulette or play blackjack.
All users start with an intial balance of $1000.
When the user does not want to play anymore, they can quit the program.

If the user chooses to simulate play, the user has the option to simulate 10 players or a custom amount of players.
The program simulates $100 bets on 3 games of slots, 3 games of roulette, 3 games of blackjack, and 1 random of the three games for each player.
The program then prints the leaderboard of the simulated users' names and balances.
