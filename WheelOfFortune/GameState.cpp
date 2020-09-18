#include "GameState.h"

GameState::GameState() {} //Default Constructor

void GameState::startGame() //Starts game
{
    word.setWord(); //Makes GamePhrases object
    setWheel(); //Reads money values from txt file

    cout << "[W.H.E.E.L  O.F  F.O.R.T.U.N.E]\n" << endl;

    cout << "Enter Player 1's Name: ";
    cin >> name1;
    cout << "\nEnter Player 2's Name: ";
    cin >> name2;
    setName(name1, name2);

    cout << "\n\"Welcome, " << name1 << " and " << name2 << "!\"" << endl;
    cout << "\n\"Let's Play!\"" << endl;
}

void GameState::startRound() //Starts round
{
    cout << endl;
    setPuzzle();
    cout << " "; printPuzzle();
}

void GameState::setPuzzle() //Generates 2D Vector
{
    word.setWord();

    puzzle = word.getWord(); //Takes random word from list
    int j = puzzle.length();
    for (int i = 0; i < j; i++) //Puts each letter in a vector
    {
        letter = puzzle.at(i);
        letterList.push_back(letter);
    }

    const int row = letterList.size();

    for (int i = 0; i < 2; i++) //Creates 2D Vector
    {
        vector <char> temp;
        for (int j = 0; j < letterList.size(); j++)
        {
            if (i == 0)
                temp.push_back(letterList.at(j)); //First row is for puzzle's solution 

            else
            {
                if (letterList.at(j) != '_') //Second row is blank dashes and spaces
                    temp.push_back('_'); //Blank Dash

                else
                    temp.push_back(' '); //Space
            }
        }
        hide.push_back(temp);
    }
}

void GameState::printPuzzle() //Prints progress of puzzle
{
    for (int i = 1; i < hide.size(); i++) //Prints each element
    {
        for (int j = 0; j < hide[i].size(); j++)
            cout << hide[i][j] << " ";
        cout << endl;
    }
}

void GameState::setWheel() //Reads money values from txt file
{
    ifstream infile; //Opens a file
    infile.open("moneyvalues.txt");

    if (infile.fail()) //Error occurs and exits program if file isn't found
    {
        cerr << "Error: File Not Found" << endl;
        exit(1);
    }

    while (!infile.eof()) //Pushes money values in vector
    {
        infile >> money;
        moneyList.push_back(money);
    }
}

int GameState::spinWheel() //Gets random money value 
{
    int num;
    srand(time(0));

    if (moneyList.size() == 0)
    {
        cerr << "Error: Money values have not been set";
        exit(1);
    }

    num = (rand() % moneyList.size()); //RNG
    money = moneyList.at(num);
    return money;
}

void GameState::setName(string n1, string n2) //Sets names of players
{
    name1 = n1;
    name2 = n2;
}

string GameState::getName1() //Gets player 1's name
{
    return name1;
}

string GameState::getName2() //Gets player 2's name
{
    return name2;
}

void GameState::takeTurnPlayer1() //Has player 1 take their turn
{
    cout << endl;
    cout << getName1() << " spun for: $" << spinWheel() << endl;
    cout << getName1() << ", guess a letter: ";

    do //Do-while loop to insist player has at least one guess
    {
        do //Do-while loop to make sure player guesses a new letter
        {
            cin >> guess;
            guessLetter(guess);
            guess = toupper(guess);
            cout << endl;

            getGuesses(guess);
            if (getGuesses(guess) == true) //True - letter has already been guessed
            {
                cout << "Letter " << guess << " has already been guessed. Try again: ";
            }
        } while (getGuesses(guess) == true); //Will have player guess again

        setGuess(guess);
        if (guessLetter(guess) != 0) //Non-zero value indicates letter is in the puzzle
        {
            cout << " "; printPuzzle(); //Prints progress
            addMoneyPlayer1(guessLetter(guess)); //Adds money to player's total
            cout << "\nCorrect! " << getName1() << " earned $" << guessLetter(guess) << "!" << endl;

            puzzleSolved(); //Checks to see if puzzle is solved
            if (puzzleSolved() == false) //False - puzzle not solved
                cout << getName1() << ", guess another letter: ";
        }
    } while (guessLetter(guess) != 0 && puzzleSolved() == false);

    puzzleSolved();
    if (puzzleSolved() == false) //Incorrect guess
    {
        guess = toupper(guess);
        cout << "There is no " << guess << " in the puzzle.\n" << endl;
        cout << " "; printPuzzle();
    }
}

void GameState::takeTurnPlayer2() //Has player 2 take their turn
{
    cout << endl;
    cout << getName2() << " spun for: $" << spinWheel() << endl;
    cout << getName2() << ", guess a letter: ";

    do //Do-while loop to insist player has at least one guess
    {
        do //Do-while loop to make sure player guesses a new letter
        {
            cin >> guess;
            guessLetter(guess);
            guess = toupper(guess);
            cout << endl;

            getGuesses(guess);
            if (getGuesses(guess) == true) //True - letter has already been guessed
            {
                cout << "Letter " << guess << " has already been guessed. Try again: ";
            }
        } while (getGuesses(guess) == true); //Will have player guess again

        setGuess(guess);
        if (guessLetter(guess) != 0) //Non-zero value indicates letter is in the puzzle
        {
            cout << " "; printPuzzle(); //Prints progress
            addMoneyPlayer2(guessLetter(guess));  //Adds money to player's total
            cout << "\nCorrect! " << getName2() << " earned $" << guessLetter(guess) << "!" << endl;
            puzzleSolved(); //Checks to see if puzzle is solved
            if (puzzleSolved() == false) //False - puzzle not solved
                cout << getName2() << ", guess another letter: ";
        }
    } while (guessLetter(guess) != 0 && puzzleSolved() == false);

    puzzleSolved();
    if (puzzleSolved() == false)  //Incorrect guess
    {
        guess = toupper(guess);
        cout << "There is no " << guess << " in the puzzle.\n" << endl;
        cout << " "; printPuzzle();
    }
}

int GameState::guessLetter(char l) //Checks to see if letter is in puzzle
{
    l = toupper(l); //Capitalizes letter
    int count = 0;
    bool correct = false;
    for (int i = 0; i < hide[0].size(); i++)
    {
        if (l == hide[0][i])
        {
            hide[1][i] = l; //Replaces underscore with correct letter
            correct = true;
            count++;
        }
    }
    return money * count; //Returns the money player has won
}

void GameState::setGuess(char l) //Stores guessed letter in vector
{
    guessedLetters.push_back(l);
}

bool GameState::getGuesses(char l) //Checks to see if letter has already been guessed
{
    bool guess = false;
    for (int i = 0; i < guessedLetters.size(); i++)
    {
        if (l == guessedLetters.at(i))
            guess = true; //True - Letter has already been guessed
    }
    return guess;
}

void GameState::addMoneyPlayer1(int prize) //Adds money to player 1
{
    prize1 = prize1 + prize;
}

void GameState::addMoneyPlayer2(int prize) //Adds money to player 2
{
    prize2 = prize2 + prize;
}

int GameState::getMoneyPlayer1() //Returns player 1's total money
{
    return prize1;
}

int GameState::getMoneyPlayer2() //Returns player 2's total money
{
    return prize2;
}

bool GameState::puzzleSolved() //Checks to see if puzzle has been solved
{
    bool solved = true;
    for (int i = 0; i < hide[0].size(); i++)
    {
        if (hide[1][i] == '_') //If underscore is found, puzzle is not solved
        {
            solved = false;
        }
    }

    return solved;
}

bool GameState::nextRound() //Asks user if they want to play another round
{
    char restart;
    cout << "Congrats! The puzzle has been solved!" << endl;
    cout << "\nWould you like to play another round? (Y/N) ";
    cin >> restart;
    while (restart != 'Y' && restart != 'N' && restart != 'y' && restart != 'n')
    {
        cout << "\nPlease enter Y for yes or N for no ";
        cin >> restart;
    }

    if (restart == 'Y' || restart == 'y')
    {
        hide.clear(); //Clears vector for new word
        letterList.clear(); //Clears vector for new word
        guessedLetters.clear(); //Clears guessed letters for next round
        return true;
    }

    else
        return false;
}

void GameState::finishGame() //Prints final results and ends game
{
    cout << "\nFinal Results: \n" << endl;
    cout << getName1() << ": $" << getMoneyPlayer1() << endl;
    cout << getName2() << ": $" << getMoneyPlayer2() << endl;
    cout << endl;

    if (getMoneyPlayer1() > getMoneyPlayer2())
    {
        cout << getName1() << " Wins!!!" << endl;
    }

    else if (getMoneyPlayer1() < getMoneyPlayer2())
    {
        cout << getName2() << " Wins!!!" << endl;
    }

    else
    {
        cout << "It's A Tie!!!" << endl;
    }

    cout << "\nThanks For Playing." << endl;
}