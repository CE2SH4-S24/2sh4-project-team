#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
//#include "objectPosArrayList.h" 
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "ctime"

//if somebody talk to somebody need to include header file

using namespace std;

#define DELAY_CONST 100000

objPos myPos;//most likely need to move
objPos foodInfo;//most likely need to move //pof doesnt like

//bool exitFlag;
GameMechs* myGM;//most likely need to move
Player* myPlayer;//most likely need to move
Food* myFood;//most likely need to move


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{
    
    Initialize();

    //cout<<"check1\n";
    cout<<myGM->getBoardSizeY()<<"\n";
    cout<<myGM->getBoardSizeX()<<"\n";
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
{   //objPos temp = {0, 0, 'o'};
    srand(time(NULL));
    MacUILib_init();
    //MacUILib_clearScreen();
    myGM = new GameMechs(X_SIZE,Y_SIZE);//most likely need to move
    myFood = new Food();//most likely need to move
    myPlayer = new Player(myGM, myFood);//most likely need to move
    myPos = {0,0,'@'};
    myFood->generateFood(myPos);
    myFood->getFoodPos(foodInfo);
    
    //exitFlag = false;
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
    if(myGM->getInput()== 27){
        myFood->generateFood(test);
        myFood->getFoodPos(foodInfo);
        myGM->clearInput();
    }

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
        for(j = 0; j<myGM->getBoardSizeX(); j++){//use getter functiosn

            bool drawn = false;
            for(ID = 0; ID<playerBody->getSize(); ID++){

                playerBody->getElement(tempBody, ID);

                if(tempBody.x == j && tempBody.y == i){
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }
            if(drawn) continue;

            else if(i == foodInfo.y && j == foodInfo.x){
                putchar(foodInfo.symbol);
                //printf("HAHAHAHAAH\n");
            }
            else if(i%(myGM->getBoardSizeY()-1) == 0){
                putchar('#');
                if(j == (myGM->getBoardSizeX()-1)){
                    //if(i == 0) putchar('#');
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
                putchar(' ');
            }
        }
    }
    // objPos tempPos;
    // myPlayer->getPlayerPos(tempPos); // to get player position
    //MacUILib_printf("BoardSize: %dx%d, Player Pos: <%d, %d> + %c", myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempPos.x, tempPos.y, tempPos.symbol);
    //MacUILib_printf("Board Size: %dx%d, Player Pos: <%d, %d> + %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), Playerinfo.x, Playerinfo.y, Playerinfo.symbol);
    MacUILib_printf("Current Score: %d\n", myGM->getScore());
    if(myGM->getExitFlagStatus()){
        MacUILib_clearScreen();
        MacUILib_printf("*** Game Has Been Exited ***");
        //MacUILib_Delay(20*DELAY_CONST);
    }
    
    if(myGM->getLoseFlagStatus()){
        MacUILib_clearScreen();
        MacUILib_printf("*** You Lost - Score: %d ***", myGM->getScore());
        //MacUILib_Delay(20*DELAY_CONST);
    }
    //PRINTING THE FOOD POSITION:
    MacUILib_printf("Food info: <%d, %d, %c>\n", foodInfo.x, foodInfo.y, foodInfo.symbol);
    MacUILib_printf("Player Positons:\n");
    for(ID = 0; ID<playerBody->getSize(); ID++)
    {   
        playerBody->getElement(tempBody,ID);
        MacUILib_printf("ID: <%d, %d>", tempBody.x, tempBody.y);
    }
}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST/2); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
