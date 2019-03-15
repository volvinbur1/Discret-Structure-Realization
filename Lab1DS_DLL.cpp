//Doubly linked list
#include <iostream>

using namespace std;

struct DLL
{
	int data;
	DLL *prev, *next;
};

void insertToFront(int _element, DLL *_DLlist)
{
	DLL * temp_DLL = new DLL();

	temp_DLL = _DLlist;
	while (temp_DLL->prev != NULL)
		temp_DLL = temp_DLL->prev;

	DLL * insertToFront_Node = new DLL();

	insertToFront_Node->data = _element;
	insertToFront_Node->prev = NULL;
	insertToFront_Node->next = temp_DLL;

	temp_DLL->prev = insertToFront_Node;
}

void insertToEnd(int _data, DLL **_DLlist)
{
	DLL *temprorary_DLlist = new DLL();

	temprorary_DLlist->data = _data;

	if (*_DLlist != NULL)
	{
		temprorary_DLlist->prev = *(_DLlist);
	}
	temprorary_DLlist->next = NULL;
	(*_DLlist)->next = temprorary_DLlist;
	(*_DLlist) = temprorary_DLlist;
}

void insertElemnt(int _element, int _after_which, DLL *_DLlist)
{
	DLL * temp_DLL = new DLL();

	temp_DLL = _DLlist;
	
	while (temp_DLL->data != _after_which)
		temp_DLL = temp_DLL->prev;

	DLL * insert_Node = new DLL();

	insert_Node->data = _element;
	insert_Node->prev = temp_DLL;
	insert_Node->next = temp_DLL->next;

	temp_DLL->next->prev = insert_Node;
}

void printList(DLL *_DLlist)
{
	DLL * temp_DLL = new DLL();

	temp_DLL = _DLlist;
	while (temp_DLL->prev != NULL)
	{
		printf("%d ", temp_DLL->data);
		temp_DLL = temp_DLL->prev;
	}
}

int main()
{
	DLL *DLlist = new DLL(); // declare a head element

	DLlist->data = NULL;
	DLlist->next = NULL;
	DLlist->prev = NULL;

	for (int i = 1; i <= 5; i++)
	{
		insertToEnd(i, &DLlist);
	}

	printList(DLlist);

	insertElemnt(10, 3, DLlist);

	printf("\n");

	printList(DLlist);

	insertToFront(17, DLlist);

	printf("\n");

	printList(DLlist);
	system("Pause");
}
