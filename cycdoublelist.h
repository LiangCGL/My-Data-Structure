#ifndef __CYCDOULIST_H
#define __CYCDOULIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int ElemType;

typedef struct CycNode
{
	struct CycNode *prev;
	ElemType data;
	struct CycNode *next;
}CycNode;



typedef struct CycDouList
{
	CycNode *head;
	int count;
}CycDouList, *pCycList;

void InitCycDouList(pCycList list);

void InsertCycDouList(pCycList list, ElemType value, int pos);


#endif