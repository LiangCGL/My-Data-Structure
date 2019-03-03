#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int  ElemType;

#define SIZE 10
#define TRUE 1
#define FALSE 0


typedef struct stack
{
	ElemType *data;
	int size;
	int top;
}Stack, *pStack;

void InitStack(pStack stack);

void DestoryStack(pStack stack);

int Push(pStack stack, ElemType val);

int Pop(pStack stack, ElemType *res);





#endif