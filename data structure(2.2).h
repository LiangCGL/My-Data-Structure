#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;


typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;


typedef struct LinkList
{
	struct Node head;
	int count;
}LinkList, *pList;



void InitLinkList(pList list);

void InsertElemToList(pList list, ElemType val, int pos);

void DeleteElemOfList(pList list, int pos);

void Show(pList list);

int FindKAfter(pList list, int k, ElemType *res);

int DeleteNode(pList list, struct Node *p);

int TwoListMeet(pList list1, pList list2);


void Reverse(pList list);

void Reverse2(pList list);



#endif
