#include "objPosArrayList.h" 
#include <iostream>

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
objPosArrayList::objPosArrayList()
{
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
    
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{   
    if(sizeArray == sizeList){
        //cout<< "List and array same size cannot add head\n";
        return;
    }
    for(int i = sizeList; i>0; i--){
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeArray == sizeList){
        //cout<< "List and array same size cannot add tail\n";
        return;
    }
    aList[sizeList] = thisPos;
    sizeList++;
}

void objPosArrayList::removeHead()
{
    if(sizeList==0){
        //cout<<"List size 0 cannot remove head\n";
        return;
    }
    for(int i = 0; i<sizeList-1; i++){
        aList[i] = aList[i+1];
    }
    sizeList--;
}

void objPosArrayList::removeTail()
{
    if(sizeList == 0){
        //cout<<"List Empty. No removal allowed!"<<endl;
        return;
    }
    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos = aList[0];
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos = aList[sizeList-1];
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos = aList[index];
}