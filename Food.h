#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class Food{

    private:
        objPos foodPos;
        objPosArrayList* mainListRef;
        int xCandidate, yCandidate;
        char cCandidate;
    public:
        Food();
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        void getFoodPos(objPos &returnPos);
};


#endif