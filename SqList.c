#include "SqList.h"

/*
typedef int ElemType;

typedef struct SqList
{
	ElemType *elem; // �����ڴ����ʼλ��
	int size;   // ���浱ǰ�ڴ���ܴ�С -- �ܴ洢����Ԫ�ص��ܸ���
	int count;  // �Ѵ洢��Ԫ�ظ���
}SqList, *pSqList;

*/

//�ڲ�����

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

// ��ʼ�� -- �Դ��ݵĽ����г�ʼ��ֵ
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
	list->elem = NULL; // ��ֹ����Ұָ��  ��ʽͬһ��ռ䱻�ͷ�����

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
