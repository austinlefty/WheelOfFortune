#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include "GamePhrases.h"
#ifndef GAME_STATE_H
#define GAME_STATE_H
using namespace std;

class GameState
{
private:
	GamePhrases word;

	int money;
	int prize1 = 0;
	int prize2 = 0;

	char letter;
	char guess;

	string puzzle;
	string name1;
	string name2;

	vector <char> letterList;
	vector <vector<char>> hide;
	vector <int> moneyList;
	vector <char> guessedLetters;

public:
	GameState(); //Default Constructor

	void startGame(); //Starts game
	void startRound(); //Starts round

	void setPuzzle(); //Creates the layout of puzzle
	void printPuzzle();

	void setWheel(); //Reads money values from txt file
	int spinWheel(); //Randomly chooses a value

	void setName(string name1, string name2); //Sets names of players
	string getName1(); //Gets player 1's name
	string getName2(); //Gets player 2's name

	void takeTurnPlayer1(); //Has player 1 take his turn
	void takeTurnPlayer2(); //Has player 2 take his turn

	int guessLetter(char l); //Checks to see if letter is in puzzle
	void setGuess(char letter); //Stores guessed letter in vector
	bool getGuesses(char letter); //Checks to see if letter has already been guessed

	void addMoneyPlayer1(int prize); //Adds money to player 1
	void addMoneyPlayer2(int prize); //Adds money to player 2
	int getMoneyPlayer1(); //returns player 1's total money
	int getMoneyPlayer2(); //returns player 2's total money

	bool puzzleSolved(); //Checks to see if puzzle has been solved
	bool nextRound(); //Asks user if they want to play another round
	void finishGame(); //Prints final results and ends game
};
#endif // !GAME_STATE_H