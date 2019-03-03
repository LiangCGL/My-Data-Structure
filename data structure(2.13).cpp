//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
////������˳����Զ�����
//#define INITSIZE 10
//
//typedef struct DSeqList
//{
//	int *elem;//ָ�������ݵĶ�̬����
//	int length;//��Ч���ݸ���
//	int listsize;//���������ܸ�����
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
////������������ԭ����2��
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
//	{//return false;//����˳���
//		Inc(ps);
//	}
//
//	for (int i = ps->length - 1; i >= pos; i--)//�ƶ����������
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
///*13����֪A��B��CΪ����������������Ա���Ҫ���A�������²�����
//ɾȥ��Щ����B���г�������C���г��ֵ�Ԫ�ء���дʵ�������������㷨
//��ע�⣺����û���ر�ָ��ͬһ���е�Ԫ��ֵ������ͬ����*/
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
