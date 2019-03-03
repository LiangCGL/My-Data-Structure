#include "cycdoubleList.h"


void InitCycDouList(pCycList list)
{
	assert(list != NULL);
	list->head = NULL;
	list->count = 0;
}


void InsertCycDouList(pCycList list, ElemType value, int pos)
{
	assert(list != NULL);

	if (pos < 0 || pos > list->count)
	{
		printf("insert error\n");
		return;
	}

	CycNode *s = (CycNode*)malloc(sizeof(CycNode));

	if (list->head == NULL)
	{
		s->data = value;
		s->next = s;
		s->prev = s;
		list->head = s;
		list->count++;
		return;
	}

	CycNode *p = list->head;
	if (pos == 0)
	{
		s->next = p;
		p = p->prev;
		p->next = s;

		s->prev = p;
		s->next->prev = s;
		list->head = list->head->prev;
		list->count++;
		return;
	}
	else
	{
		while (pos > 1)
		{
			p = p->next;
			pos--;
		}

		s->next = p->next;
		p->next = s;
		s->next->prev = s;
		s->prev = p;

		list->count++;
		return;
	}

}


void DeleteCycDouList(pCycList list, ElemType value, int pos)
{
	assert(list != NULL && list->head != NULL);

	if (pos < 1 || pos > list->count)
	{
		printf("delete error\n");
		return;
	}

	if (list->head->next = list->head)
	{
		free(list->head);
		list->head = NULL;
		list->count--;
		return;
	}
	CycNode *p = list->head;

	if (pos == 1)
	{
		p = p->prev;
		list->head = list->head->next;
	}
	else
	{
		while (pos > 2)
		{
			p = p->next;
			pos--;
		}
	}

	CycNode *s = p->next;

	p->next = s->next;
	s->next->prev = s->prev;

	s->next = NULL;
	s->prev = NULL;
	free(s);
	list->count--;
	return;

}
