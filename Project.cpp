#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "ctime"


using namespace std;

#define DELAY_CONST 100000

objPos myPos;
objPos foodInfo;


GameMechs* myGM;
Player* myPlayer;
Food* myFood;
objPosArrayList* myList;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{
    
    Initialize();

    
    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{   
    srand(time(NULL));
    MacUILib_init();
    
    myGM = new GameMechs(X_SIZE,Y_SIZE);
    myFood = new Food();
    myPlayer = new Player(myGM, myFood);
    myList = new objPosArrayList();
    myPos = {0,0,'@'};
    myFood->generateFood(myList);
    myFood->getFoodPos(foodInfo);
    
    
} 

void GetInput(void)
{
   myGM->getInput();
}

void RunLogic(void)
{   
    
    objPos test;
    test = {1,2,'o'};
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myFood->getFoodPos(foodInfo);
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    int i, j, ID;// x, y;
    objPos Playerinfo;
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    for (i = 0; i<myGM->getBoardSizeY(); i++) //Rows
    {   
        for(j = 0; j<myGM->getBoardSizeX(); j++){//Columns

            bool drawn = false; //drawn flag
            for(ID = 0; ID<playerBody->getSize(); ID++){

                playerBody->getElement(tempBody, ID);

                if(tempBody.x == j && tempBody.y == i){
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }
            if(drawn) continue;

            else if(i == foodInfo.y && j == foodInfo.x){ //draw food symbol
                putchar(foodInfo.symbol);
                
            }
            else if(i%(myGM->getBoardSizeY()-1) == 0){ //draw borders
                putchar('#');
                if(j == (myGM->getBoardSizeX()-1)){
                    putchar('\n');
                }
            }
            else if(j%(myGM->getBoardSizeX()-1) == 0){
                putchar('#');
                if(j == (myGM->getBoardSizeX()-1)){
                    putchar('\n');
                }
            }
            else{
                putchar(' '); //fill rest of board
            }
        }
    }
    
    MacUILib_printf("Current Score: %d\n", (myGM->getScore()));
    if(myGM->getExitFlagStatus()){
        MacUILib_clearScreen();
        MacUILib_printf("*** Game Has Been Exited ***");
        
    }
    
    if(myGM->getLoseFlagStatus()){
        MacUILib_clearScreen();
        MacUILib_printf("*** You Lost - Score: %d ***", myGM->getScore()); // Loss message
    
       
    }
    //PRINTING THE STATIC DISPLAY:
    MacUILib_printf("Controls: W - UP A- LEFT\nS - DOWN D - RIGHT\nPress 'Space' to exit game.");
    
}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST/2); // 0.1s delay
}


void CleanUp(void)
{
    // delete myGM;
    delete myFood;
    delete myPlayer;
    delete myList;
    MacUILib_uninit();
}
