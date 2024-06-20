#include "Food.h"
#include "ctime"
#define X 26 
#define Y 13
Food::Food(){
    
    foodPos.setObjPos(-1, -1, 'o');  
}
Food::~Food(){
    
}
void Food::generateFood(objPosArrayList* blockOff)
{
    mainListRef = blockOff;
    objPos temp;
    bool flag; 
    do{
    xCandidate = (rand()%(X-2))+1;      //generate random x-y coordinates
    yCandidate = (rand()%(Y-2))+1;
    for(int i = 0; i<mainListRef->getSize(); i++){
        flag = true;
            mainListRef->getElement(temp, i);
            
            if(temp.x == xCandidate && temp.y == yCandidate){
                flag = false;
                break;
            }
        }
    }while(!flag); //checking if they are equal if they are repeat

    do{
    cCandidate = (rand())%(93);
    cCandidate = '!' + cCandidate; // no space characters
    
     
    }while(cCandidate == '#' || cCandidate == '@');
    foodPos.setObjPos(xCandidate, yCandidate, cCandidate); 
}

void Food::getFoodPos(objPos &returnPos){
    returnPos = foodPos;
}
