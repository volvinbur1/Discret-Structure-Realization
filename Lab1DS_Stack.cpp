#include <iostream>

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
	//Stack *temprorary_stack = _stack->head;
	
	while (_stack->head != NULL)
	{
		printf("%d ", _stack->head->element);
		Stack *temprorary_stack = _stack->head->next_elemnt;
		delete(_stack->head);
		_stack->head = temprorary_stack;
		//temprorary_stack = _stack->next_elemnt;
	}
}

int main()
{
	Stack *stack = new Stack();

	stack->head = NULL; // nullptr ??? size_t ???
	stack->next_elemnt = NULL;

	int number_of_elements = 5;

	for (int i = 0; i < number_of_elements; i++)
		push(i, stack);

	pop(stack);
	system("pause");
}
