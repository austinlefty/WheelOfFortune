#include "GamePhrases.h"

GamePhrases::GamePhrases() {} //Default Constructor

GamePhrases::GamePhrases(string w) //Overload Constructor
{
    word = w;
}

void GamePhrases::setWord() //Reads words from txt file and stores in vector
{
    ifstream infile; //Opens a file
    infile.open("listofwords.txt");

    if (infile.fail()) //Error occurs and exits program if file isn't found
    {
        cerr << "Error: File Not Found" << endl;
        exit(1);
    }

    while (!infile.eof()) //Pushes words in vector
    {
        infile >> word;
        wordList.push_back(word);
    }
}

string GamePhrases::getWord() //Chooses random word to give to GameState
{
    int num;
    srand(time(0));

    if (wordList.size() == 0)
    {
        cerr << "Error: Words have not been set";
        exit(1);
    }

    num = (rand() % wordList.size()); //RNG
    word = wordList.at(num);
    return word;
}