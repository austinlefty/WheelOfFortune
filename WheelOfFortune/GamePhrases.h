#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class GamePhrases
{
private:
    vector <string> list;
    string word;
    ifstream infile;

public:
    void storeWords()
    {
        infile.open("listofwords.txt");

        if (infile.fail())
        {
            cerr << "Error: File Not Found" << endl;
            exit(1);
        }

        while (!infile.eof())
        {
            infile >> word;
            list.push_back(word);
        }
    }

    void printWords()
    {
        for (int i = 0; i < list.size(); i++)
        {
            //return list.at(i);

            cout << list.at(i) << endl;
        }
    }
};
