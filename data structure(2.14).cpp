#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#define SIZE 10
#define EXTERN 1
#define Elemtype int
#define Status
#define SUCCESS 1
#define FAIL 0

typedef struct SeqList
{
	Elemtype *base;
	int capacity;
	int size;
}List;

void initial(List *list);
void push_back(List *list, Elemtype x);
void show(List *list);
Status int  Extern(List *list);
void intersec(List *la, List *lb);



void initial(List *list)
{
	list->base = (Elemtype*)malloc(SIZE*sizeof(Elemtype));
	assert(list->base != NULL);

	list->capacity = SIZE;
	list->size = 0;
}

void push_back(List *list, Elemtype x)
{
	if (list->size == list->capacity&&!Extern(list))
		return;

	list->base[list->size] = x;
	list->size++;
}

void show(List *list)
{
	if (list->size == 0)
	{
		return;
	}

	for (int i = 0; i < list->size; ++i)
	{
		printf("%d ", list->base[i]);
	}
	printf("\n");
}

Status int Extern(List *list)
{
	Elemtype *newbase;
	newbase = (Elemtype*)realloc(list->base, (list->capacity + EXTERN)*sizeof(Elemtype));

	if (newbase)
	{
		list->base = newbase;
		list->capacity += EXTERN;
		return(SUCCESS);
	}
	else
	{
		return(FAIL);
	}
}

void intersec(List *la, List *lb)
{
	int pa = 0, pb = 0;

	while (pa<la->size)
	{
		if (pa == 0 || pa != 0 && la->base[pa] != la->base[pa - 1])
		{
			while (pb<lb->size && lb->base[pb]<la->base[pa])
				pb++;
			if (pb<lb->size && lb->base[pb] == la->base[pa])
			{
				pa++;
			}
			else
			{
				for (int i = pa; i<la->size - 1; ++i)
					la->base[i] = la->base[i + 1];
				la->size--;
			}
		}
		else
		{
			for (int i = pa; i<la->size - 1; ++i)
				la->base[i] = la->base[i + 1];
			la->size--;
		}
	}
}



int main()
{
	List la, lb;
	int x;
	initial(&la);
	initial(&lb);

	
}