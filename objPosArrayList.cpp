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
    if(sizeArray == sizeList)
    {
        
        return;
    }
    for(int i = sizeList; i>0; i--)
    {
       aList[i].setObjPos(aList[i-1]);
    }
    aList[0].setObjPos(thisPos);
    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeArray == sizeList)
    {
        
        return;
    }
    aList[sizeList].setObjPos(thisPos);
    sizeList++;
}

void objPosArrayList::removeHead()
{
    if(sizeList==0)
    {
        
        return;
    }
    for(int i = 0; i<sizeList-1; i++)
    {
        aList[i].setObjPos(aList[i + 1]);
    }
    sizeList--;
}

void objPosArrayList::removeTail()
{
    if(sizeList == 0)
    {
        
        return;
    }
    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList - 1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}