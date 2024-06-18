#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class Food{

    private:
        objPos foodPos;
        int xCandidate, yCandidate;
        char cCandidate;
    public:
        Food();
        ~Food();

        void generateFood(objPos blockOff);//update this somehow
        void getFoodPos(objPos &returnPos);
        //void setFoodPos();
};


#endif