/*
Name: Austin Krause
Class: CSCE 306
Description: Wheel Of Fortune - A game where 
two users guess phrases and earn money to win
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GamePhrases.h"

using namespace std;

int main()
{
    GamePhrases word;
    word.storeWords();
    word.printWords();
}
