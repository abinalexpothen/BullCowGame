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

class FBullCowGame {
public:
    FBullCowGame(); // constructor
    
    int GetMaxTries() const; // TODO print out the maximum number of tries
    int GetCurrentTry() const; // TODO print the current try
    bool IsGameWon() const;
    
    void Reset(); // TODO make a more rich return value
    bool CheckGuessValidity(std::string) const; // TODO return a more rich return value
    
    
// please try and ignore this; focus on iterface
private:
    int MyCurrentTry;
    int MyMaxTries;
    
    bool IsIsogram(std::string) const;
};

#endif /* FBullCowGame_hpp */
