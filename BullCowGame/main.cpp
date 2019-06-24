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
void PrintGameSummary();

FBullCowGame BCGame; // instantiate a new game

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
    std::cout << "\n\nWelcome to Bulls and Cows, a fun word game!\n";
    std::cout << "Can you think of a " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram that I am thinking of?\n\n";
    return;
}


// play game
void PlayGame()
{
    BCGame.Reset();
    
    int32 MaxTries = BCGame.GetMaxTries();
    
    // loop while the game is NOT won and there are tries still remaining
    while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
    {
        FText Guess = GetValidGuess();
        
        // submit valid guess and receive counts
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
    }
    
    PrintGameSummary();
    
    return;
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
    std::cout << "Do you want to play again with the same hidden word? (y/n) " << std::endl;
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary()
{
    if (BCGame.IsGameWon())
    {
        std::cout << "Congratulations! You won the game!";
    }
    else
    {
        std::cout << "Oops ... You ran out of tries. Better luck next time.";
    }
    std::cout << "\n\n";
    
}

