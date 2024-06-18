#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h> // C++ time() ofr somehting

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{   
    // GameMechs is the Game Mechanism class
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        //objPos foodPos;
        char input;
        bool exitFlag;
        bool loseFlag;
        int score; //score apples eaten type beat
        int boardSizeX;
        int boardSizeY;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); //destructor might not even use this bitch
        
        bool getExitFlagStatus();
        bool getLoseFlagStatus();//For losing condition
        void setExitTrue();
        void setLoseFlag(); //added hopefully done
        char getInput();
        void setInput(char this_input);
        int getScore();
        void clearInput();
        void incrementScore(); // added
        int getBoardSizeX();
        int getBoardSizeY();
        //void generateFood(objPos blockoff);
        //void getFoodPos(objPos &returnPos);
      

};

#endif