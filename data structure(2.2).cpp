
#include "2.2.h"


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
	Node *s = BuyNode(val,p->next);
	s->next = p->next;
	p->next = s;

	list->count++;
}

void DeleteElemOfList(pList list, int pos)
{
	if (pos < 1 || pos > list->count)
	{
		printf("delete pos is error\n");
		return;
	}

	Node *p = &list->head;

	
	while (pos > 1)
	{
		p = p->next;
		pos--;
	}

	Node *q = p->next;
	p->next = q->next;

	free(q);

	list->count--;
}


int FindKAfter(pList list, int k, ElemType *res)
{
	assert(list != NULL);

	if (k <= 0 || k > list->count)
	{
		return 0;
	}

	struct Node *p = list->head.next;
	struct Node *q = p;

	while (k > 0)
	{
		k--;
		p = p->next;
	}

	while (p != NULL)
	{
		p = p->next;
		q = q->next;
	}

	*res = q->data;

	return 1;
}


int DeleteNode(pList list, struct Node *p)
{
	assert(list != NULL && p != NULL);

	if (p->next == NULL)
	{
		struct Node *q = &list->head;
		while (q->next != p)
		{
			q = q->next;
		}
		q->next = NULL;
		list->count -= 1;
		free(p);

		return 1;
	}

	struct Node *q = p->next;
	p->data = q->data;
	p->next = q->next;
	list->count -= 1;

	free(q);

	return 1;
}

int TwoListMeet(pList list1, pList list2)
{
	assert(list1 != NULL && list2 != NULL);
	struct Node *p = list1->head.next;
	struct Node *q = list2->head.next;
	if (list1->count > list2->count)
	{
		for (int i = 0; i < list1->count - list2->count; ++i)
		{
			p = p->next;
		}
	}
	else
	{
		for (int i = 0; i < list2->count - list1->count; ++i)
		{
			q = q->next;
		}
	}

	while (p != NULL && p != q)
	{
		p = p->next;
		q = q->next;
	}

	if (p == NULL)
	{
		return 0;
	}

	return 1;
}

void Reverse(pList list)
{
	assert(list != NULL);
	struct Node *p = NULL;
	struct Node *q = list->head.next;
	if (q == NULL)  // 只有一个头结点
	{
		return;
	}
	struct Node *m = q->next;

	while (q != NULL)
	{

		q->next = p;

		p = q;
		if (m == NULL)
		{
			break;
		}
		q = m;
		m = q->next;
	}

	list->head.next = p;
}

void Show(pList list)
{
	assert(list != NULL);
	struct Node *p = list->head.next;

	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}

	printf("\n");
}

void Reverse2(pList list)
{
	assert(list != NULL);

	if (list->head.next == NULL)
	{
		return;
	}

	struct Node *p = list->head.next;
	list->head.next = NULL;
	struct Node *q = p->next;

	while (1)
	{
		p->next = list->head.next;

		list->head.next = p;
		if (q == NULL)
		{
			break;
		}
		p = q;
		q = q->next;
	}
}

int main()
{
	LinkList list; 
	InitLinkList(&list);
	for (int i = 0; i < 10; ++i)
	{
		InsertElemToList(&list, i, 0);
	}

	Show(&list);

	Reverse2(&list);
	Show(&list);
}
