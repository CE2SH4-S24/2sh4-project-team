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


GameMechs::~GameMechs()
{
    
}

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

void GameMechs::setLoseFlag(){
    loseFlag = true;
}
void GameMechs::incrementScore(){ 
    score++;
}
bool GameMechs::getLoseFlagStatus(){
    return loseFlag;
}
int GameMechs::getScore(){
    return score;
}

