//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Abin Alex Pothen on 2018-12-22.
//  Copyright © 2018 Abin Alex Pothen. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <string>

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
    
    void Reset(); // TODO return a more rich return value
    FBullCowCount SubmitValidGuess(FString);
    
// please try and ignore this and focus on interface ^^
private:
    // see constructor for initialization
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    bool bGameIsWon;
    
    // private member function
    bool IsIsogram(FString) const;
};

#endif /* FBullCowGame_hpp */
