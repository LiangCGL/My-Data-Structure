#ifndef _SQLIST_H
#define _SQLIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

typedef int ElemType;

typedef struct SqList
{
	ElemType *elem; // 保存内存的起始位置
	int size;   // 保存当前内存的总大小 -- 能存储数据元素的总个数
	int count;  // 已存储的元素个数
}SqList, *pSqList;

void InitSqList(pSqList list);

void DestroySqList(pSqList list);

void InsertElem(pSqList list, ElemType val, int pos);

void InsertHead(pSqList list, ElemType val);

void InsertTail(pSqList list, ElemType val);

void DeleteElem(pSqList list, int pos);

void DeleteHead(pSqList list);

void DeleteTail(pSqList list);

void ShowList(pSqList list);



#endif // !__SQLIST_H
