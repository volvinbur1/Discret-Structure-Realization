#include <iostream>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

struct Stack
{
	int element;
	Stack *next_elemnt, *head;
};

void push(int _value, Stack *_stack)
{
	Stack *temprorary_stack = new Stack();
	temprorary_stack->element = _value;
	temprorary_stack->next_elemnt = _stack->head;
	_stack->head = temprorary_stack;
}

void pop(Stack *_stack)
{
	while (_stack->head != NULL)
	{
		printf("%d ", _stack->head->element);
		Stack *temprorary_stack = _stack->head->next_elemnt;
		delete(_stack->head);
		_stack->head = temprorary_stack;
	}
}

int main()
{
	Stack *stack = new Stack();

	stack->head = NULL; // nullptr ??? size_t ???
	stack->next_elemnt = NULL;

	fstream file;
	
	file.open("stack_data.txt");

	clock_t startTime = clock();	

	while (!file.eof())
	{
		string data;
		getline(file, data);
		push(stoi(data), stack);
	}

	file.close();

	/*int number_of_elements = 100;
	for (int i = 0; i < number_of_elements; i++)
		push(i, stack);*/
	

	pop(stack);

	printf_s("\nThe code was running for %.2fs\n", (double)(clock() - startTime) / CLOCKS_PER_SEC);

	system("pause");
}