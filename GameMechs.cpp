#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false; //default
    loseFlag = false;
    score = 0;
    boardSizeX = 20;
    boardSizeY = 10;
    //foodPos.setObjPos(-1, -1, 'o'); //initialize out game board
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false; //default
    loseFlag = false;
    score = 0;
    boardSizeX = boardX; //board of preference
    boardSizeY = boardY;
}

// do you need a destructor? not rn
// GameMechs::~GameMechs(){
//     delete
// }

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    if(MacUILib_hasChar()){
        input = MacUILib_getChar();
    }
    return input;

    
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

 
void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}
//added
void GameMechs::setLoseFlag(){
    loseFlag = true;
}
void GameMechs::incrementScore(){ // test by printing and incrementing each repetition
    score++;
}
bool GameMechs::getLoseFlagStatus(){
    return loseFlag;
}
int GameMechs::getScore(){
    return score;
}

// Provide definitions of more member functions as required
// See Project Manual
// void GameMechs::generateFood(objPos blockoff){
//     //generate random x and y coords
//     //make sure not on:
//     //border
//     //on player (blockoff)
//     //remember in object position class you have is posequal method.
// }
// void GameMechs::getFoodPos(objPos &returnPos){

// }