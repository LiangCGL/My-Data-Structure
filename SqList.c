#include "SqList.h"

/*
typedef int ElemType;

typedef struct SqList
{
	ElemType *elem; // 保存内存的起始位置
	int size;   // 保存当前内存的总大小 -- 能存储数据元素的总个数
	int count;  // 已存储的元素个数
}SqList, *pSqList;

*/

//内部函数

void ExpandSpace(pSqList list)
{
	ElemType *s = (ElemType *)malloc(sizeof(ElemType)* list->size * 2);
	assert(s != NULL);

	for (int i = 0; i < list->count; ++i)
	{
		s[i] = list->elem[i];
	}

	free(list->elem);
	list->elem = s;
	list->size *= 2;
}

//

// 初始化 -- 对传递的结点进行初始赋值
void InitSqList(pSqList list)
{
	list->elem = (ElemType *)malloc(sizeof(ElemType)* SIZE);
	assert(list->elem != NULL);

	list->size = SIZE;
	list->count = 0;
}

void DestroySqList(pSqList list)
{
	free(list->elem);
	list->elem = NULL; // 防止出现野指针  方式同一块空间被释放两次

	list->size = 0;
	list->count = 0;
}

void InsertElem(pSqList list, ElemType val, int pos)
{
	if (pos < 0 || pos > list->count)
	{
		printf("insert pos is error\n");
		return;
	}

	if (list->count == list->size)
	{
		ExpandSpace(list);
	}

	int i = 0;
	for (i = list->count; i > pos; --i)
	{
		list->elem[i] = list->elem[i - 1];
	}

	list->elem[i] = val;
	list->count++;
}

void InsertHead(pSqList list, ElemType val)
{
	InsertElem(list, val, 0);
}

void InsertTail(pSqList list, ElemType val)
{
	InsertElem(list, val, list->count);
}

void DeleteElem(pSqList list, int pos)
{

}

void DeleteHead(pSqList list)
{

}

void DeleteTail(pSqList list)
{

}

void ShowList(pSqList list)
{
	for (int i = 0; i < list->count; ++i)
	{
		printf("%d  ", list->elem[i]);
	}

	printf("\n");
}
