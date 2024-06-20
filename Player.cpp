#include "Player.h"
#include <iostream>
using namespace std;

 
Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef; 
    mainFoodRef = thisFoodRef;
    myDir = STOP;

    
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2, '@');
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    
    
}


Player::~Player()
{
    
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos 
    return playerPosList;  
}

void Player::updatePlayerDir()
{
    

    switch(mainGameMechsRef->getInput()){ //input processing logic
            case 'w': 
                if(myDir != DOWN){
                    myDir = UP;
                }
                break;
            case 'W':
                if(myDir != DOWN){
                    myDir = UP;
                }
                break;
            // Add more key processing here
            case 'a':
                if(myDir != RIGHT){
                    myDir = LEFT;
                }
                break;
            case 'A':
                if(myDir != RIGHT){
                    myDir = LEFT;
                }
                break;
            case 's':
                if(myDir != UP){
                    myDir = DOWN;
                }
                break;
            case 'S':
                if(myDir != UP){
                    myDir = DOWN;
                }
                break;
            case 'd':
                if(myDir != LEFT){
                    myDir = RIGHT;
                }
                break;
            case 'D':
                if(myDir != LEFT){
                    myDir = RIGHT;
                }
                break;
            case 32: //space bar set as exit key
                mainGameMechsRef->setExitTrue();
    }       
}

void Player::movePlayer()
{   
    objPos currHead; //objPos instance holding head info
    objPos currFood; //objPos instance holding current food info
    objPos temp;
    playerPosList->getHeadElement(currHead); // getting head element
   
    switch(myDir){ //player movement logic/FSM implementation
        case UP:
            currHead.y--;
            if(currHead.y == 0){
                currHead.y = mainGameMechsRef->getBoardSizeY()-2;
            }
            break;
        case DOWN:
            currHead.y++;
            if(currHead.y == mainGameMechsRef->getBoardSizeY()-1){
                currHead.y = 1;
            }
            break;
        case LEFT:
            currHead.x--;
            if(currHead.x == 0){
                currHead.x = mainGameMechsRef->getBoardSizeX()-2;
            }
            break;
        case RIGHT:
            currHead.x++;
            if(currHead.x == mainGameMechsRef->getBoardSizeX()-1){
                currHead.x = 1;
            }
            break;
    }
    for(int i = 1; i<playerPosList->getSize(); i++){
        playerPosList->getElement(temp, i);
        if(currHead.x == temp.x && currHead.y == temp.y){ //if head collides with any body parts, exit
            mainGameMechsRef->setLoseFlag(); 
            mainGameMechsRef->setExitTrue();
            break;
        }
    }
    
    mainFoodRef->getFoodPos(currFood); //storing the position of object food
    if(currFood.x == currHead.x && currFood.y == currHead.y){ //equality check
        playerPosList->insertHead(currHead); //insert head
        mainFoodRef->generateFood(playerPosList);//generate new food
        mainFoodRef->getFoodPos(currFood);
        mainGameMechsRef->incrementScore();
        return;
    }
    playerPosList->insertHead(currHead); //insert head at updated position
    playerPosList->removeTail(); // removes tail to ensure movement of snake
}

