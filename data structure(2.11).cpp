//
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//typedef int ElemType;
//
//typedef struct 
//{
//	ElemType *elem;
//	int       length;
//	int       size;
//} SqList;
//
//
//
//char Compare(SqList A, SqList B)
//
//{
//	int i, j;
//	i = j = 0;
//	
//	if (A.length > A.size || B.length > B.size)
//	{
//		return 0;
//	}
//	if (A.elem && B.elem)
//	{  
//		while (i <= A.length && j <= B.length)
//		{
//			if (A.elem[i] == B.elem[j])
//			{
//				i++;
//				j++;
//			}
//			else
//			{
//				break;
//			}
//				
//		}
//		if (!A.elem[i] && !B.elem[j])
//		{
//			return '=';                       
//		}
//		if (A.elem[i] > B.elem[j])
//		{
//			return '>';                      
//		}
//		if (A.elem[i] < B.elem[j])
//		{
//			return '<';                      
//		}
//	}
//}
//
//
//int main()
//{
//
//}