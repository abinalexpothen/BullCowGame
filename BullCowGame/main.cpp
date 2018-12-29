//
//  main.cpp
//  BullCowGame
//
//  Created by Abin Alex Pothen on 2018-12-01.
//  Copyright © 2018 Abin Alex Pothen. All rights reserved.
//

#include <iostream>
#include "FBullCowGame.hpp"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
    std::cout << "Welcome to bulls and Cows, a fun word game!\n";
    std::cout << "Can you think of an " << WORD_LENGTH;
    std::cout << " letter isogram that I am thinking of?\n";
    return;
}


// play game
void PlayGame()
{
    FBullCowGame Player1Game; // instantiate a new game
    FBullCowGame Player2Game;
    
    constexpr int NUMBER_OF_TURNS = 5;
    // loop for the number of turns to guess the word
    for(int count = 1; count <= NUMBER_OF_TURNS; count++)
    {
        std::string Guess = GetGuess();
        
        // print the guess back to them
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout<<std::endl;
    }
}


// get a guess from the player
std::string GetGuess()
{
    std::string Guess = "";
    std::getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n) " << std::endl;
    std::string Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}
