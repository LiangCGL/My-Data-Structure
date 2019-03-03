#include "cycList.h"

static Node *BuyNode(ElemType val, Node *next)
{
	Node *s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = val;

	if (next != NULL)
	{
		s->next = next;
	}
	else
	{
		s->next = s;
	}

	return s;
}


void InitCycList(pCyc list)
{
	assert(list != NULL);        

	list->count = 0;
	list->head = NULL;
}

void InsertCycList(pCyc list, ElemType val, int pos)
{
	assert(list != NULL);
	if (pos < 0 || pos>list->count)
	{
		printf("insert error");
	}

	if (list->head == NULL)
	{
		Node *s = BuyNode(val, NULL);
		list->count++;
		return;
	}

	int pos2 = pos != 0 ? pos : list->count;   

	Node *p = list->head;
	while (pos2 > 1)
	{
		p = p->next;
		pos2--;
	}
	Node *s = BuyNode(val, p->next);
	p->next = s;

	if (pos == 0)
	{
		list->head = s;
	}
	list->count++;

}


void DeleteCycList(pCyc list, int pos)
{
	assert(list != NULL);
	if (pos < 1 || pos > list->count)
	{
		printf("delete error");
		return;
	}

	if (list->head->next == list->head)    
	{
		free(list->head);
		list->head = NULL;
		list->count--;
		return;
	}

	Node *p = list->head;
	if (pos == 1)
	{
		Node *s = p;

		while (p->next != list->head)
		{
			p = p->next;
		}

		p->next = s->next;
		list->head = s->next;
		free(s);
	}
	else
	{
		while (pos > 2)
		{
			p = p->next;
			pos--;
		}

		Node *s = p->next;
		p->next = s->next;
		free(s);
	}

	list->count--;
}


void ShowList(pCyc list)
{
	assert(list != NULL);

	if (list->head = NULL)
	{
		printf("empty\n");
		return;
	}

	Node *p = (Node*)malloc(sizeof(Node));
	while (list->head->next != list->head)
	{
		printf("%d\n", list->head->data);
		p = p->next;
	}
	printf("%d\n", list->head->data);

}

