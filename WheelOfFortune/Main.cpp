/*
Name: Austin Krause
Homework: Programming Assignment #1
Class: CSCE 306
Description: Wheel Of Fortune - A game where
two users guess phrases and earn money to win
*/
#include <iostream>
#include "GamePhrases.h"
#include "GameState.h"

using namespace std;

int main()
{
    GameState game; //Creates object that uses functions to play game
    bool next = true;

    game.startGame(); //Starts game

    while (next == true) //True - will keep playing rounds until user quits
    {
        game.startRound(); //Starts round
        while (game.puzzleSolved() == false) //Loops players' turns until puzzle is solved
        {
            if (game.puzzleSolved() == false)
                game.takeTurnPlayer1(); //Player 1's Turn
            if (game.puzzleSolved() == false)
                game.takeTurnPlayer2(); //Player 2's Turn
        }

        if (game.nextRound() == false) //False - User quit game
        {
            game.finishGame(); //Finishes game
            next = false; //Breaks out of loop and ends program
        }
    }

    return (0);
}