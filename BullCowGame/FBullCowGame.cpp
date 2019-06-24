#pragma once

#include "FBullCowGame.hpp"
#include <map>

// to make the syntax Unreal friendly
#define TMap std::map
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

// getters
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return static_cast<int>(MyHiddenWord.length()); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const
{
    TMap<int32, int32> WordLengthToMaxTries { {3,5}, {4,7}, {5,10}, {6,15} };
    return WordLengthToMaxTries[GetHiddenWordLength()];
}

// public methods
void FBullCowGame::Reset()
{
    const FString HIDDEN_WORD = "plan"; // this MUST be an isogram
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
    else if (!IsLowercase(Guess)) // if the guess isnt all lowercase
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
        // for each letter in hidden word, loop through guess
        for (int32 GChar = 0; GChar < WordLength; GChar++)
        {
            // if they match then
            if (MyHiddenWord[MHWChar] == Guess[GChar]) {
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
    if (BullCowCount.Bulls == WordLength) { bGameIsWon = true; }
    else { bGameIsWon = false; }
    return BullCowCount;
}


bool FBullCowGame::IsIsogram(FString Word) const
{
    // treat 0 and 1 letter strings as isogram
    if (Word.length() <= 1) { return true; }
    
    TMap<char, bool> LetterSeen; // map to keep track of the characters in the guess
    for (auto Letter : Word)
    {
        Letter = tolower(Letter); // handle mixed case
        if (LetterSeen[Letter]) // if the letter was seen then
        {
            return false; // it is not an isogram
            
        }
        else
        {
            LetterSeen[Letter] = true; // add the letter to the map as seen
        }
    }
    return true; // for example when /0 is entered
}


bool FBullCowGame::IsLowercase(FString Word) const
{
    for (auto Letter : Word)
    {
        if (!islower(Letter)) { return false; } // if not a lower case, return false
    }
    return true;
}
