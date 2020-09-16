#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class GamePhrases
{
private:
    vector <string> list; //Containter for words
    string word; //Copys word from txt file
    ifstream infile; //Opens a file

public:
    void storeWords() //Reads words from txt file and stores them in a vector
    {
        infile.open("listofwords.txt");

        if (infile.fail()) //Error occurs and exits program if file isn't found
        {
            cerr << "Error: File Not Found" << endl;
            exit(1);
        }

        while (!infile.eof()) //Pushes words in vector
        {
            infile >> word;
            list.push_back(word);
        }
    }

    void printWords() //Prints words to check if they are stored in vector
    {
        for (int i = 0; i < list.size(); i++)
        {
            cout << list.at(i) << endl;
        }
    }
};
