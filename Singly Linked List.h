#include<stdio.h>
#include <assert.h>
#include <stdlib.h>
#include<malloc.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

typedef struct LinkList
{
	struct Node head;
	int count;
}LinkList, *pList;

static Node *BuyNode(ElemType val, Node *next)
{
	Node *s = (Node *)malloc(sizeof(Node));
	assert(s != NULL);

	s->data = val;
	s->next = next;

	return s;
}

void InitLinkList(pList list)
{
	list->count = 0;

	list->head.next = NULL;
}

void InsertElemToList(pList list, ElemType val, int pos)
{
	if (pos < 0 || pos > list->count)
	{
		printf("insert pos is error\n");
		return;
	}

	Node *s = (Node *)malloc(sizeof(Node));
	assert(s != NULL);

	s->data = val;

	Node *p = &list->head;

	while (pos > 0)
	{
		p = p->next;
		pos--;
	}

	s->next = p->next;
	p->next = s;

	list->count++;
}

Node* Nodefind(pList list, int k)
{
	if (k == 0)
	{
		return NULL;
	}

	Node *p1 = &list->head;
	Node *p2 = &list->head;
	for (int i = 0; i < k - 1; i++)
	{
		p1 = p1->next;
	}

	while (p1->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

void Inversion(pList list)
{
	Node *p, *q, *t;
	p = &list->head;  
	q = p->next; 

	while (q->next != NULL)  
	{
		t = q->next; 
		q->next = p; 
		p = q; 
		q = t; 
	}
	p->next = NULL;
	p->next = q;

}

void Intersect(pList list1, pList list2)
{
	Node *p = &list1->head;
	Node *q = &list2->head;
	
	while (p->next != NULL)
	{
		p = p->next;
	}

	while (q->next != NULL)
	{
		q = q->next;
	}

	if (p == q)
	{
		printf("两个链表相交\n");
	}

}
void Findnode(pList list)
{
	Node *p, *q;
	p = q = &list->head;
	q = q->next;

	while ( p!=q )
	{
		q = q->next;
		if (q->next == NULL)
		{
			printf("链表没有环\n");
			return;
		}
		q = q->next;
		if (q->next == NULL)
		{
			printf("链表没有环\n");
			return;
		}
		p = p->next;
	}
	p =  &list->head;
	while (p != q)
	{
		p = p->next;
		q = q->next;
	}
	printf("找到环的第一个节点：");
	printf("%d\n",p->data);
	
}