/*This is the console executable that makes use of the BullCow class. This acts as the view in an MVC pattern, and is responsible for all user interation. For full details, see the FBullCowGame class.
 */
//
//  Created by Abin Alex Pothen on 2018-12-01.
//  Copyright © 2018 Abin Alex Pothen. All rights reserved.
//

#include <iostream>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// entry point of the code
int main()
{
    BCGame.Reset();
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
    std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
    std::cout << "Can you think of a " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram that I am thinking of?\n\n";
    return;
}


// play game
void PlayGame()
{
    int32 MaxTries = BCGame.GetMaxTries();
    
    // loop for the number of turns to guess the word
    for(int32 count = 1; count <= MaxTries; count++) // TODO: change to a while loop
    {
        FText Guess = GetValidGuess();
        
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
    }
    
    // TODO: Add a game summary
}


// get a guess from the player
FText GetValidGuess()
{
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    
    do {
        // get a guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << ". Enter your guess: ";
        std::getline(std::cin, Guess);
        
        Status = BCGame.CheckGuessValidity(Guess);
        switch(Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << " Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
                break;
                
            case EGuessStatus::Not_Isogram:
                std::cout << " Please enter a word without repeating letters. \n";
                break;
                
            case EGuessStatus::Not_Lowercase:
                std::cout << " Please enter all lower case letters. \n";
                break;
                
            default:
                // assume the guess is valid
                break;
        }
        std::cout << std::endl;
    } while(Status != EGuessStatus::OK); // keep looping until we get no errors
    
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n) " << std::endl;
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}
