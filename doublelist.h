#ifndef __DOUBLELIST_H
#define __DOUBLELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int ElemType;


typedef struct Node
{
	struct Node *prev;
	ElemType  data;
	struct Node *next;
}Node;

typedef struct DoubleList
{
	Node head;
	int count;
}DoubleList, *pList;

void InitDoubleList(pList list);

void ShowDoubleList(pList list);

void ReverseShow(pList list);

void InsertDoubleList(pList list, ElemType val, int pos);

void DeleteDoubleList(pList list, int pos);

void DestroyList(pList list);



#endif