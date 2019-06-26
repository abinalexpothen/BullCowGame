/* The game logic (no view code or direct user interaction)
 The game is a simple guess the word based on mastermind*/
//  Created by Abin Alex Pothen on 2018-12-22.

#pragma once

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <string>

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame {
public:
    FBullCowGame(); // constructor
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString) const;
    
    void Reset();
    FBullCowCount SubmitValidGuess(FString);
    void SetHiddenWord(int32);
    
private:
    int32 MyCurrentTry;
    FString MyHiddenWord;
    bool bGameIsWon;
    
    // private member functions
    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
};

#endif /* FBullCowGame_hpp */
