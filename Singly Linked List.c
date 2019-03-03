#include"k.h"

int main()
{
	LinkList list1;
	InitLinkList(&list1);
	for (int i = 0; i < 5; i++)
	{
		InsertElemToList(&list1, i * 10,i);
	}
	Node* p=Nodefind(&list1, 2);

	printf("%d\n",p->data);
		

	LinkList list2;
	InitLinkList(&list2);
	for (int i = 0; i < 5; i++)
	{
		InsertElemToList(&list2, i * 10, i);	
	}
	Inversion(&list2);
	Node *q = &list2.head;
	while (q->next != NULL)
	{
		printf("%d\n",q->data);
		q = q->next;
	}

	/*LinkList list3;
	LinkList list4;
	InitLinkList(&list3);
	for (int i = 0; i < 5; i++)
	{
		InsertElemToList(&list3, i * 10, i);
	}
	InitLinkList(&list4);
	for (int i = 0; i < 5; i++)
	{
		InsertElemToList(&list4, i * 10, i);
	}
	Intersect(&list3, &list4);


	LinkList list5;
	InitLinkList(&list5);
	for (int i = 0; i < 5; i++)
	{
		InsertElemToList(&list5, i * 10, i);
	}*/

	return 0;
}