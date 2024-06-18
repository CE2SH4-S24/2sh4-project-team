#include "Food.h"
#include "ctime"
#define X 26 // probably need to change this around later
#define Y 13
Food::Food(){
    //objPos foodPos;
    foodPos.setObjPos(-1, -1, 'o');  
}
Food::~Food(){
    //empty rn
}
void Food::generateFood(objPos blockOff){
    do{
    xCandidate = (rand()%(X-2))+1;
    yCandidate = (rand()%(Y-2))+1;
    }while(xCandidate == blockOff.x && yCandidate == blockOff.y); //checking if they are equal if they are repeat

    do{
    cCandidate = (rand())%(93);
    cCandidate = '!' + cCandidate; // no space characters
    //MacUILib_printf("check 3: cCand = %c\n", cCandidate);
     
    }while(cCandidate == '#' || cCandidate == '@');
    foodPos.setObjPos(xCandidate, yCandidate, cCandidate);
}
void Food::getFoodPos(objPos &returnPos){
    returnPos = foodPos;
}