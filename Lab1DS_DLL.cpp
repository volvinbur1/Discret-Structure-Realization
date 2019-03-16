//Doubly linked list
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

struct DLL // the structure of every certain node in DLL
{
	int data;
	DLL *prev, *next;
};

void insertToFront(int _element, DLL *_DLlist) // insert element to the front of doubly linked list
{
	DLL *temp_DLL = new DLL();

	temp_DLL = _DLlist;
	while (temp_DLL->prev != NULL) // find a pointer to first node
		temp_DLL = temp_DLL->prev;

	DLL *insertToFront_Node = new DLL(); // create new node for the first place

	insertToFront_Node->data = _element; 
	insertToFront_Node->prev = NULL;
	insertToFront_Node->next = temp_DLL;

	temp_DLL->prev = insertToFront_Node;
}

void insertToEnd(int _data, DLL **_DLlist) // insert element to the end of doubly linked list
{
	DLL *temprorary_DLlist = new DLL();

	temprorary_DLlist->data = _data;

	temprorary_DLlist->prev = *(_DLlist);

	if ((*_DLlist)->data == NULL) // make previous node adress for the first node equal to NULL 
	{
		temprorary_DLlist->prev = NULL;
	}

	temprorary_DLlist->next = NULL;
	(*_DLlist)->next = temprorary_DLlist;
	(*_DLlist) = temprorary_DLlist;
}

void insertElemnt(int _element, int _after_which, DLL *_DLlist) // insert element after certain one 
{
	DLL *temp_DLL = new DLL();

	temp_DLL = _DLlist;
	
	while (temp_DLL->data != _after_which) // find a pointer to an appropriate element after which new one will be placed
		temp_DLL = temp_DLL->prev;

	DLL *insert_Node = new DLL(); // create a new node for a new element

	insert_Node->data = _element;
	insert_Node->prev = temp_DLL;
	insert_Node->next = temp_DLL->next;

	temp_DLL->next->prev = insert_Node;
	temp_DLL->next = insert_Node;
}

void printList(DLL *_DLlist, bool _is_from_end_to_front) // output list
{
	DLL *temp_DLL = new DLL();

	temp_DLL = _DLlist;

	if (_is_from_end_to_front) // in which referal output a sequence of the list 
		while (temp_DLL != NULL) // from end to front
		{
			printf("%d ", temp_DLL->data);
			temp_DLL = temp_DLL->prev;
		}
	else // from front to end
	{
		while (temp_DLL->prev != NULL) // find pointer to first node
			temp_DLL = temp_DLL->prev;

		while (temp_DLL != NULL) // print values until the list ends
		{
			printf("%d ", temp_DLL->data);
			temp_DLL = temp_DLL->next;
		}
	}
	delete temp_DLL;

	printf("\n");
}

void deleteDLL(DLL **_DLlist) // delete all elements from list
{
	while ((*_DLlist)->prev != NULL) // do deletion until every element will be removed 
	{
		DLL *temp_DLL = new DLL(); // create temprorary node 

		temp_DLL = (*_DLlist)->prev;

		delete (*_DLlist); // empty certain memory cell

		(*_DLlist) = temp_DLL;
		//delete temp_DLL;
	}

	(*_DLlist)->data = NULL;
	(*_DLlist)->next = NULL;
	(*_DLlist)->prev = NULL;
}

int main()
{
	DLL *DLlist = new DLL(); // pointer to a head node in DLL

	DLlist->data = NULL;
	DLlist->next = NULL;
	DLlist->prev = NULL;

	fstream file;

	file.open("DLL_data.txt");
	
	clock_t startTime = clock();

	while (!file.eof())
	{
		string data;
		getline(file, data);
		insertToEnd(stoi(data), &DLlist);
	}

	file.close();

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
