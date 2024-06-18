#include "Player.h"
//#include "GameMechs.h"
#include <iostream>
using namespace std;

 
Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef; //deal with later
    mainFoodRef = thisFoodRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    //objPos foodStuff;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2, '@');
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    // adding more to make the snake move
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);

    //thisFoodRef->generateFood(tempPos);
    //thisFoodRef->getFoodPos(foo);
    
}


Player::~Player()
{
    //leave empty for now iteation 3 will use
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos 
    return playerPosList;  
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    // Copy the switch satement here from PPA3 can remove the speed?
    // will be a fucntion in game mechs to check input and store most
    // recnt input need to find how to get
    // think i figured this jawn out lol

    switch(mainGameMechsRef->getInput()){
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
            case 32:
                mainGameMechsRef->setExitTrue();
    }       
}

void Player::movePlayer()
{   
    objPos currHead; //objPos instance holding head info
    objPos currFood; //objPos instance holding current food info
    playerPosList->getHeadElement(currHead); // getting head element
    //mainFoodRef->getFoodPos(currFood);

    switch(myDir){
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

    mainFoodRef->getFoodPos(currFood); //storing the position of object food
    cout << "currFood.x:"<< currFood.x <<"currFood.y:"<< currFood.y << endl;
    cout << "currHead.x:"<< currHead.x << "currHead.y:" << currHead.y << endl;
    if(currFood.x == currHead.x && currFood.y == currHead.y){ //equality check
        playerPosList->insertHead(currHead); //insert head
        mainFoodRef->generateFood(playerPosList);//generate new food
        mainFoodRef->getFoodPos(currFood);
        return;
    }
    // PPA3 Finite State Machine logic
    //snake movement
    cout << "Failure";
    playerPosList->insertHead(currHead); //insert head at updated position
    playerPosList->removeTail(); // removes tail to ensure movement of snake
}

// bool Player::checkFoodConsumption(){

// }