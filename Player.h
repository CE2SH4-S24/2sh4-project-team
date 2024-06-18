#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"
#define X_SIZE 26
#define Y_SIZE 13

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {STOP, UP, DOWN, LEFT, RIGHT};  // This is the direction state (FSM)

        Player(GameMechs* thisGMRef, Food* thisFoodRef );
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();
        // bool checkFoodConsumption();
        // void increasePlayerLength();

    private:
        objPosArrayList* playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir; //match the stuff from ppa3

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* mainFoodRef;
};

#endif