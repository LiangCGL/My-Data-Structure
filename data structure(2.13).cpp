//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
////不定长顺序表，自动增长
//#define INITSIZE 10
//
//typedef struct DSeqList
//{
//	int *elem;//指向存放数据的动态数组
//	int length;//有效数据个数
//	int listsize;//总容量，总格子数
//}DSeqList, *PDSeqList;
//
//void InitSeqList(PDSeqList ps)
//{
//	assert(ps != NULL);
//	if (ps == NULL)
//	{
//		return;
//	}
//	ps->elem = (int *)malloc(INITSIZE*sizeof(int));
//	ps->length = 0;
//	ps->listsize = INITSIZE;
//}
//
//static bool IsFull(PDSeqList ps)
//{
//	return ps->length == ps->listsize;
//}
//
////将总容量扩大到原来的2倍
//static void Inc(PDSeqList ps)
//{
//	ps->elem = (int *)realloc(ps->elem, ps->listsize * 2 * sizeof(int));
//	ps->listsize *= 2;
//}
//
//bool Insert(PDSeqList ps, int pos, int val)
//{
//	if (pos<0 || pos>ps->length)
//	{
//		return false;
//	}
//
//	if (IsFull(ps))
//	{//return false;//定长顺序表
//		Inc(ps);
//	}
//
//	for (int i = ps->length - 1; i >= pos; i--)//移动后面的数据
//	{
//		ps->elem[i + 1] = ps->elem[i];
//	}
//	ps->elem[pos] = val;
//
//	ps->length++;
//
//	return true;
//}
//
//bool DeletePos(PDSeqList ps, int pos)
//{
//	if (pos<0 || pos >= ps->length)
//	{
//		return false;
//	}
//
//	for (int i = pos; i<ps->length - 1; i++)
//	{
//		ps->elem[i] = ps->elem[i + 1];
//	}
//
//	ps->length--;
//
//	return true;
//}
//
///*13、已知A，B和C为三个递增有序的线性表，现要求对A表作如下操作：
//删去那些既在B表中出现又在C表中出现的元素。编写实现上述操作的算法
//（注意：题中没有特别指明同一表中的元素值各不相同）。*/
//void DeleteBC_same(PDSeqList ps1, PDSeqList ps2, PDSeqList ps3)
//{
//	int i;
//	int j;
//	int k;
//
//	for (j = 0; j < ps2->length; j++)
//	{
//		for (k = 0; k < ps3->length; k++)
//		{
//			if (ps2->elem[j] == ps3->elem[k])
//			{
//				for (i = 0; i < ps1->length; i++)
//				{
//					if (ps1->elem[i] == ps2->elem[j])
//					{
//						DeletePos(ps1, i);
//					}
//				}
//			}
//		}
//	}
//}
//
//void Show(PDSeqList list)
//{
//	for (int i = 0; i < list->length; ++i)
//	{
//		printf("%d  ", list->elem[i]);
//	}
//
//	printf("\n");
//}
//
//int main()
//{
//	DSeqList ds1;
//	DSeqList ds2;
//	DSeqList ds3;
//
//	InitSeqList(&ds1);
//	InitSeqList(&ds2);
//	InitSeqList(&ds3);
//	for (int i = 0; i < 10; i++)
//	{
//		Insert(&ds1, i, i);
//		Insert(&ds2, i, i);
//	}
//
//	for (int i = 0; i < 15; i++)
//	{
//		Insert(&ds3, i, 2 * i);
//	}
//	Show(&ds1);
//	Show(&ds2);
//	Show(&ds3);
//
//	
//	DeleteBC_same(&ds1, &ds2, &ds3);
//	Show(&ds1);
//
//	return 0;
//}
