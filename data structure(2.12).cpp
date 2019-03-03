//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//#include<stdlib.h>
//typedef int ElemType;
//
//// 一个结点类型
//typedef struct Node
//{
//	ElemType data;
//	struct Node *next;
//}Node;
//
//typedef struct LinkList
//{
//	struct Node head; 
//	int count;
//}LinkList, *pList;
//
//
//
//void InitLinkList(pList list)
//{
//	list->head.data = NULL;
//	list->count = 0;
//	
//}
//void InsertElemToList(pList list, ElemType val, int pos)
//{
//	if (pos < 0 || pos > list->count)
//	{
//		return;
//	}
//
//
//	Node *s = (Node*)malloc(sizeof(Node));
//	assert(s != NULL);
//	s->data = val;
//	Node *p = &list->head;
//
//	while (pos > 0)
//	{
//		p = p->next;
//		pos--;
//	}
//
//	s->next = p->next;
//	p->next = s;
//
//	list->count++;
//}
//void Show(pList list)
//{
//	assert(list != NULL);
//	struct Node *p = list->head.next;
//
//	while (p != NULL)
//	{
//		printf("%d  ", p->data);
//		p = p->next;
//	}
//
//	printf("\n");
//}
//
//
//
//int main()
//{
//	LinkList a, b, c;
//	int i;
//	InitLinkList(&a);
//	InitLinkList(&b);
//	InitLinkList(&c);
//	
//	for (i = 0; i <= 3; i++)
//	{
//		InsertElemToList(&a, 2 * i ,i);
//		InsertElemToList(&b,  2 * i,i);
//	}
//	Show(&a);
//	Show(&b);
//
//}