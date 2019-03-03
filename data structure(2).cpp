//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//#define SIZE 10
//
//typedef int ElemType;
//
//typedef struct SqList
//{
//	ElemType *elem;
//	int size;
//	int count;
//}SqList, *pSqList;
//
//
//void ExpandSpace(pSqList list)
//{
//	ElemType *s = (ElemType *)malloc(sizeof(ElemType)* list->size * 2);
//	assert(s != NULL);
//
//	for (int i = 0; i < list->count; ++i)
//	{
//		s[i] = list->elem[i];
//	}
//
//	free(list->elem);
//	list->elem = s;
//	list->size *= 2;
//}
//
//void InitSqList(pSqList list)
//{
//	list->elem = (ElemType *)malloc(sizeof(ElemType)* SIZE);
//	assert(list->elem != NULL);
//
//	list->size = SIZE;
//	list->count = 0;
//}
//
//
//void DestroySqList(pSqList list)
//{
//	free(list->elem);
//	list->elem = NULL;
//
//	list->size = 0;
//	list->count = 0;
//}
//
//void Reverse(pSqList list)
//{
//	  int i = 0;
//    ElemType temp;
//	
//    for (i; i < (list->size / 2); i++)
//    {
//        temp = list->elem[i];
//		list->elem[i] = list->elem[list->size - i - 1];
//		list->elem[list->size - i - 1] = temp;
//    }
//
//}
//
