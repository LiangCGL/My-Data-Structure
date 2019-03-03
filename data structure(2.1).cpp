//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//
//#define SIZE 10
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
//void InsertElem(pSqList list, ElemType val, int pos)
//{
//	if (pos < 0 || pos > list->count)
//	{
//		printf("insert pos is error\n");
//		return;
//	}
//	 1 2 3 4 5 6 7 8 9
//
//	if (list->count == list->size)
//	{
//		ExpandSpace(list);
//	}
//
//	int i = 0;
//	for (i = list->count; i > pos; --i)
//	{
//		list->elem[i] = list->elem[i - 1];
//	}
//
//	list->elem[i] = val;
//	list->count++;
//}
//
//void ShowList(pSqList list)
//{
//	for (int i = 0; i < list->count; ++i)
//	{
//		printf("%d  ", list->elem[i]);
//	}
//
//	printf("\n");
//}
//
//
//
//int main()
//{
//	SqList list;
//	InitSqList(&list);
//
//
//	InsertElem(&list, 10, 0);
//	
//
//	ShowList(&list);
//
//}
