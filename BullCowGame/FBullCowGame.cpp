//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Abin Alex Pothen on 2018-12-22.
//  Copyright © 2018 Abin Alex Pothen. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <map>
#define TMap std::map

// getters
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return static_cast<int>(MyHiddenWord.length()); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

// methods
FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "plant";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (!IsIsogram(Guess)) // if the guess isnt an isogram
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (false) // if the guess isnt all lowercase
    {
        return EGuessStatus::Not_Lowercase; // TODO write function
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
            if (MyHiddenWord[MHWChar] == Guess[GChar]) {
                if (MHWChar == GChar) { // if they are in the same place
                    BullCowCount.Bulls++; // increment bulls
                }
                else {
                    BullCowCount.Cows++; // must be a cow
                }
            }
        }
    }
    if (BullCowCount.Bulls == WordLength) {
        bGameIsWon = true;
    }
    else {
        bGameIsWon = false;
    }
    return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
    // treat 0 and 1 letter strings as isogram
    if (Word.length() <= 1) { return true; }
    
    TMap<char, bool> LetterSeen; // setup our map
    for (auto Letter : Word) // for all letters of the word
    {
        Letter = tolower(Letter); // handle mixed case
        if (LetterSeen[Letter]){ // if the letter is in the map
            return false; // we do not have an isogram
        }
        else {
            LetterSeen[Letter] = true; // add the letter to the map as seen
        }
    }
    return true; // for example when /0 is entered
}

