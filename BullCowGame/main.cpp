//
//  main.cpp
//  BullCowGame
//
//  Created by Abin Alex Pothen on 2018-12-01.
//  Copyright © 2018 Abin Alex Pothen. All rights reserved.
//

#include <iostream>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();


// entry point of the code
int main()
{
    bool bPlayAgain = false;
    do
    {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while(bPlayAgain);
    return 0; // exit game
}


// introduce the game
void PrintIntro()
{
    constexpr int WORD_LENGTH = 5;
    cout << "Welcome to bulls and Cows, a fun word game!\n";
    cout << "Can you think of an " << WORD_LENGTH;
    cout << " letter isogram that I am thinking of?\n";
    return;
}


// play game
void PlayGame()
{
    constexpr int NUMBER_OF_TURNS = 5;
    // loop for the number of turns to guess the word
    for(int count = 1; count <= NUMBER_OF_TURNS; count++)
    {
        string Guess = GetGuess();
        
        // print the guess back to them
        cout << "Your guess was: " << Guess << endl;
        cout<<endl;
    }
}


// get a guess from the player
string GetGuess()
{
    string Guess = "";
    getline(cin, Guess);
    return Guess;
}

bool AskToPlayAgain()
{
    cout << "Do you want to play again? (y/n) " << endl;
    string Response = "";
    getline(cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}
