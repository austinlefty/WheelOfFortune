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
