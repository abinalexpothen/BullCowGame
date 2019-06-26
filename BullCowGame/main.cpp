/*This is the console executable that makes use of the BullCow class.
 This acts as the view in an MVC pattern, and is responsible for all
 user interation. For full details, see the FBullCowGame class.
 */
//  Created by Abin Alex Pothen on 2018-12-01.

#include <iostream>
#include "FBullCowGame.hpp"

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// function prototypes as outside a class
void PrintIntro();
void InitGame();
void PlayGame();
int32 GetValidLength();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // instantiate a new game which we reuse across plays

// entry point of the application
int main()
{
    bool bPlayAgain = false;
    do
    {
        PrintIntro();
        InitGame();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while(bPlayAgain);
    return 0; // exit the application
}

void PrintIntro()
{
    std::cout << "\n\nWelcome to Bulls and Cows, a fun word game!\n\n";
    std::cout << "     BULLS   'N'    COWS  \n";
    std::cout << "   __    __               \n";
    std::cout << "  (  )  (  )              \n";
    std::cout << "   \\      /        (     )\n";
    std::cout << " <= ~----~ =>     <= ---- =>\n";
    std::cout << "  ( o    o )       \\ o o /\n";
    std::cout << "   \\      /         \\   /\n";
    std::cout << "    \\    /           \\ /\n";
    std::cout << "     (__)            (_) \n";
    std::cout << std::endl;
    return;
}

// obtains a valid word length from user and updates hidden word in BCGame
void InitGame()
{
    BCGame.Reset();
    BCGame.SetHiddenWord(GetValidLength());
}


int32 GetValidLength()
{
    int32 WordLength = 0;
    
    do {
        // ask user to enter the word length between 3 to 6
        std::cout << "Choose a word length between 3 to 6 for the hidden word: ";
        std::cin >> WordLength;
        std::cin.get(); // catch the '\n'
        std::cout << "\n";
    } while( WordLength < 3 || WordLength > 6 );
    
    return WordLength;
}

// plays a single game to completion
void PlayGame()
{
    std::cout << "Can you enter a " << BCGame.GetHiddenWordLength() << " letter word I am thinking of?\n\n";
    
    int32 MaxTries = BCGame.GetMaxTries();
    // loop while the game is NOT won and there are tries still remaining
    while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
    {
        FText Guess = GetValidGuess();
        
        // submit valid guess to the game and receive bull and cow counts
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
    }
    
    PrintGameSummary();
    return;
}


// get a valid guess from the player
FText GetValidGuess()
{
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    
    // keep looping until the Guess is valid or OK
    do {
        // get a guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
        std::getline(std::cin, Guess);
        
        //check status and give feedback
        Status = BCGame.CheckGuessValidity(Guess);
        switch(Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << " Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n\n";
                break;
                
            case EGuessStatus::Not_Isogram:
                std::cout << " Please enter a word without repeating letters. \n\n";
                break;
                
            case EGuessStatus::Not_Lowercase:
                std::cout << " Please enter all lower case letters. \n\n";
                break;
                
            default:
                // assuming the guess is valid
                break;
        }
    } while(Status != EGuessStatus::OK);
    
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n) " << std::endl;
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
    return;
}
