#ifndef __CYCLINKLIST_H
#define __CYCLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int ElemType;


// 结点结构
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;


// 循环单链表结构
typedef struct CycLinkList
{
	Node *head;
	int count;
}CycLinkList, *pCyc;

void InitCycList(pCyc list);

void InsertCycList(pCyc list, ElemType val, int pos);

void DeleteCycList(pCyc list, int pos);



void ShowList(pCyc list);



#endif
