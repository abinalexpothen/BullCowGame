//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Abin Alex Pothen on 2018-12-22.
//  Copyright © 2018 Abin Alex Pothen. All rights reserved.
//

#include "FBullCowGame.hpp"

// getters
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return static_cast<int>(MyHiddenWord.length()); }

// methods
FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "plant";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
    return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (false) // if the guess isnt an isogram
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (false) // if the guess isnt all lowercase
    {
        return EGuessStatus::Not_Lowercase;
    }
    // if the guess length is wrong
    else if (Guess.length() != GetHiddenWordLength())
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
}


// receives a VALID guess, increments turns and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 WordLength = static_cast<int>(MyHiddenWord.length()); // assuming same length as guess
    
    // loop through all letters in the hidden word
    for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
    {
        // compare letters against the guess
        for (int32 GChar = 0; GChar < WordLength; GChar++)
        {
            // if they match then
            if (MyHiddenWord[MHWChar] == Guess[GChar])
            {
                if (MHWChar == GChar)
                { // if they are in the same place
                    BullCowCount.Bulls++; // increment bulls
                }
                else
                {
                    BullCowCount.Cows++; // must be a cow
                }
            }
        }
    }
    return BullCowCount;
}
