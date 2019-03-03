#include "Stack.h"

///////////////////////////////////
static void Expand(pStack stack)
{
	assert(stack != NULL);

	ElemType *s = (ElemType*)malloc(sizeof(ElemType)* stack->size * 2);
	assert(s != NULL);

	for (int i = 0; i < stack->top; ++i)
	{
		s[i] = stack->data[i];
	}

	free(stack->data);
	stack->data = s;
	stack->size *= 2;
}

static int IsFull(pStack stack)
{
	assert(stack != NULL);

	if (stack->top == stack->size)
	{
		return TRUE;
	}

	return FALSE;
}

static int IsEmpty(pStack stack)
{
	assert(stack != NULL);

	if (stack->top == 0)
	{
		return TRUE;
	}

	return FALSE;
}

////////////////////////////////////

void InitStack(pStack stack)
{
	assert(stack != NULL);

	stack->data = (ElemType *)malloc(sizeof(ElemType)* SIZE);
	assert(stack->data != NULL);

	stack->size = SIZE;
	stack->top = 0; //  -1
}

int Push(pStack stack, ElemType val)
{
	assert(stack != NULL);

	if (IsFull(stack))
	{
		Expand(stack);
		if (IsFull(stack))
		{
			return FALSE;
		}
	}

	stack->data[stack->top++] = val;

	return TRUE;
}

int Pop(pStack stack, ElemType *res)
{
	assert(stack != NULL);

	if (IsEmpty(stack))
	{
		return FALSE;
	}

	*res = stack->data[--stack->top];

	return TRUE;
}

void DestoryStack(pStack stack)
{
	assert(stack != NULL);

	free(stack->data);
	stack->data = NULL;
	stack->size = 0;
	stack->top = 0;
}