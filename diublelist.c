#include "doubleList.h"

static Node *BuyNode(ElemType val, Node *prev, Node *next)
{
	Node *s = (Node *)malloc(sizeof(Node));
	assert(s != NULL);

	s->data = val;
	s->next = next;
	s->prev = prev;

	return s;
}

void InitDoubleList(pList list)
{
	assert(list != NULL);

	list->count = 0;
	list->head.next = list->head.prev = NULL;
}

void InsertDoubleList(pList list, ElemType val, int pos)
{
	assert(list != NULL);

	if (pos < 0 || pos > list->count)
	{
		printf("insert pos is error\n");
		return;
	}

	Node *p = &list->head;
	while (pos > 0)
	{
		p = p->next;
		pos--;
	}


	Node *s = BuyNode(val, p, p->next);

	if (p->next != NULL)
	{
		p->next->prev = s;
	}

	p->next = s;

	list->count++;
}

void DeleteDoubleList(pList list, int pos)
{
	assert(list != NULL);

	if (pos < 1 || pos > list->count)
	{
		printf("delete pos is error\n");
		return;
	}

	Node *p = &list->head;

	while (pos > 0)
	{
		p = p->next;
		pos--;
	}

	
	p->prev->next = p->next;
	if (p->next != NULL)
	{
		p->next->prev = p->prev;
	}

	free(p);
	list->count--;
}

void ShowDoubleList(pList list)
{
	assert(list != NULL);

	Node *p = list->head.next;

	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}

	printf("\n");
}

void ReverseShow(pList list)
{
	assert(list != NULL);

	Node *p = &list->head;

	while (p->next != NULL)
	{
		p = p->next;
	}

	while (p->prev != NULL)
	{
		printf("%d  ", p->data);
		p = p->prev;
	}

	printf("\n");

}

void DestroyList(pList list)
{
	assert(list != NULL);

	while (list->count != 0)
	{
		DeleteDoubleList(list, 1);
	}
}
/*int main()
{
	DoubleList list;

	InitDoubleList(&list);

	for (int i = 0; i < 5; ++i)
	{
		InsertDoubleList(&list, i * 10, i);
	}
}*/