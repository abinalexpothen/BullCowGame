//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Abin Alex Pothen on 2018-12-22.
//  Copyright © 2018 Abin Alex Pothen. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>

#endif /* FBullCowGame_hpp */

class FBullCowGame
{
public:
    void Reset(); // TODO make a more rich return value
    int GetMaxTries(); // TODO print out the maximum number of tries
    int GetCurrentTry(); // TODO print the current try
    void PlayGame(); // TODO play the game with the current try till the maximum try
    void ProvideClue(); // TODO provide a clue by revealing one of the minimum
    void PrintRules(); // TODO display the rules of the game
    int ModifyMaxTries(); // TODO Customize the current maximum number of tries
    
    
// please try and ignore this; focus on iterface
private:
    int MyCurrentTry;
    int MyMaxTries;
    bool IsIsogram(string);
};
