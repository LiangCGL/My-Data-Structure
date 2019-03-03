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
	ElemType *elem; // �����ڴ����ʼλ��
	int size;   // ���浱ǰ�ڴ���ܴ�С -- �ܴ洢����Ԫ�ص��ܸ���
	int count;  // �Ѵ洢��Ԫ�ظ���
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
