#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#ifndef GAME_PHRASES_H
#define GAME_PHRASES_H
using namespace std;

class GamePhrases
{
private:
	string word;
	vector <string> wordList; //List of words

public:
	//Default Constructor
	GamePhrases();

	//Overload Constructor
	GamePhrases(string);

	//Setter
	void setWord();

	//Getter
	string getWord();

	//TEST(DELETE AFTER)
	void printWord();
};
#endif // !GAME_PHRASES_H