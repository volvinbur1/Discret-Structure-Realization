//Doubly linked list
#include <iostream>
#include <ctime>

using namespace std;

struct DLL
{
	int data;
	DLL *prev, *next;
};

void insertToFront(int _element, DLL *_DLlist)
{
	DLL *temp_DLL = new DLL();

	temp_DLL = _DLlist;
	while (temp_DLL->prev != NULL)
		temp_DLL = temp_DLL->prev;

	DLL *insertToFront_Node = new DLL();

	insertToFront_Node->data = _element;
	insertToFront_Node->prev = NULL;
	insertToFront_Node->next = temp_DLL;

	temp_DLL->prev = insertToFront_Node;
}

void insertToEnd(int _data, DLL **_DLlist)
{
	DLL *temprorary_DLlist = new DLL();

	temprorary_DLlist->data = _data;

	temprorary_DLlist->prev = *(_DLlist);

	if ((*_DLlist)->data == NULL)
	{
		temprorary_DLlist->prev = NULL;
	}
	temprorary_DLlist->next = NULL;
	(*_DLlist)->next = temprorary_DLlist;
	(*_DLlist) = temprorary_DLlist;
}

void insertElemnt(int _element, int _after_which, DLL *_DLlist)
{
	DLL *temp_DLL = new DLL();

	temp_DLL = _DLlist;
	
	while (temp_DLL->data != _after_which)
		temp_DLL = temp_DLL->prev;

	DLL *insert_Node = new DLL();

	insert_Node->data = _element;
	insert_Node->prev = temp_DLL;
	insert_Node->next = temp_DLL->next;

	temp_DLL->next->prev = insert_Node;
	temp_DLL->next = insert_Node;
}

void printList(DLL *_DLlist, bool _is_from_end_to_front)
{
	DLL *temp_DLL = new DLL();

	temp_DLL = _DLlist;

	if (_is_from_end_to_front)
		while (temp_DLL != NULL)
		{
			printf("%d ", temp_DLL->data);
			temp_DLL = temp_DLL->prev;
		}
	else
	{
		while (temp_DLL->prev != NULL)
			temp_DLL = temp_DLL->prev;

		while (temp_DLL != NULL)
		{
			printf("%d ", temp_DLL->data);
			temp_DLL = temp_DLL->next;
		}
	}
	delete temp_DLL;

	printf("\n");
}

void deleteDLL(DLL **_DLlist)
{
	while ((*_DLlist)->prev != NULL)
	{
		DLL *temp_DLL = new DLL();

		temp_DLL = (*_DLlist)->prev;

		delete (*_DLlist);

		(*_DLlist) = temp_DLL;
		//delete temp_DLL;
	}

	(*_DLlist)->data = NULL;
	(*_DLlist)->next = NULL;
	(*_DLlist)->prev = NULL;
}

int main()
{
	DLL *DLlist = new DLL();

	DLlist->data = NULL;
	DLlist->next = NULL;
	DLlist->prev = NULL;

	clock_t startTime = clock();

	/*for (int i = 1; i <= 5; i++)
	{
		insertToEnd(i, &DLlist);
	}*/

	printList(DLlist, false);

	insertElemnt(10, 3, DLlist);

	printList(DLlist, true);

	insertToFront(17, DLlist);
	insertToFront(8, DLlist);

	printList(DLlist, false);

	deleteDLL(&DLlist);

	for (int i = 10; i <= 15; i++)
		insertToEnd(i, &DLlist);
	
	printList(DLlist, false);

	printf_s("\nThe code was running for %.2fs\n", (double)(clock() - startTime) / CLOCKS_PER_SEC);

	system("Pause");
}
