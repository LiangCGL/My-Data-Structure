#include "queue.h"

static void InitStack(pStack st)
{
	assert(st != NULL);

	st->data = (int *)malloc(sizeof(int)* SIZE);
	assert(st->data != NULL);

	st->top = 0;
}

static int IsEmptyStack(pStack st)
{
	assert(st != NULL);

	if (st->top == 0)
	{
		return 1;
	}

	return 0;
}

static int IsFullStack(pStack st)
{
	assert(st != NULL);

	if (st->top == SIZE)
	{
		return 1;
	}

	return 0;
}

void InitQue(pQue que)
{
	assert(que != NULL);

	InitStack(&que->sta);
	InitStack(&que->stb);
}

// 队列满：  sta满，并且stb非空
static int IsFullQue(pQue que)
{
	assert(que != NULL);

	if (IsFullStack(&que->sta) && !IsEmptyStack(&que->stb))
	{
		return 1;
	}

	return 0;
}

int IsEmptyQue(pQue que)
{
	assert(que != NULL);

	if (IsEmptyStack(&que->sta) && IsEmptyStack(&que->stb))
	{
		return 1;
	}

	return 0;
}

static void PushStack(pStack st, int val)
{
	assert(st != NULL);

	if (!IsFullStack(st))
	{
		st->data[st->top++] = val;
	}
}

static int GetTop(pStack st)
{
	assert(st != NULL);

	if (IsEmptyStack(st))
	{
		return -1;
	}

	return st->data[st->top - 1];
}

static int PopStack(pStack st)
{
	assert(st != NULL);

	if (IsEmptyStack(st))
	{
		return -1;
	}

	st->top--;

	return 1;
}

int PushQue(pQue que, int val)
{
	assert(que != NULL);

	if (IsFullQue(que))
	{
		return -1;
	}

	if (IsFullStack(&que->sta))
	{ 
		// 先将A中的数据全部导入到B中
		while (!IsEmptyStack(&que->sta))
		{
			int elem = GetTop(&que->sta);
			PopStack(&que->sta);
			PushStack(&que->stb, elem);
		}
	}

	PushStack(&que->sta, val);

	return 1;
}

int PopQue(pQue que)
{
	assert(que != NULL);

	if (IsEmptyQue(que))
	{
		return -1;
	}

	if (IsEmptyStack(&que->stb))
	{
		// 把A中的数据导入到B中
		while (!IsEmptyStack(&que->sta))
		{
			int elem = GetTop(&que->sta);
			PopStack(&que->sta);
			PushStack(&que->stb, elem);
		}
	}

	int elem = GetTop(&que->stb);
	PopStack(&que->stb);

	return elem;
}