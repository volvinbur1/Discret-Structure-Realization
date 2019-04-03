#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct Node
{
	int value;
	Node *left, *right;
};

Node *insert(Node *_node, int elem_add);
Node *find_node_elem(Node *_node, int elem_find);
void print_tree(Node *_node);

int main()
{
	Node* tree = NULL;
	
	/*for (uint16_t i = 1; i <= 15; i+=3)
		tree = insert(tree, i);
	*/

	fstream file;

	file.open("BST_data.txt");

	clock_t startTime = clock();

	while (!file.eof())
	{
		string data;
		getline(file, data);
		tree = insert(tree, stoi(data));
	}

	file.close();

	tree = insert(tree, 8);

	print_tree(tree);
	
	printf_s("\nThe code was running for %.2fs\n", (double)(clock() - startTime) / CLOCKS_PER_SEC);

	system("Pause");
	delete tree;
}

Node *insert(Node *_node, int elem_add)
{
	if (_node == NULL)
	{
		_node = new Node;
		_node->value = elem_add;
		_node->left = NULL;
		_node->right = NULL;
	}
	else if (elem_add > _node->value)
		_node->right = insert(_node->right, elem_add);
	else if (elem_add < _node->value)
		_node->left = insert(_node->left, elem_add);
			
	return _node;
}

Node *find_node_elem(Node *_node, int elem_find)
{
	if (_node == NULL)
		return NULL;
	else if (elem_find > _node->value)
		return find_node_elem(_node->right, elem_find);
	else if (elem_find < _node->value)
		return find_node_elem(_node->left, elem_find);
	else
		return _node;
}

void print_tree(Node *_node)
{
	if (_node == NULL)
		return;

	print_tree(_node->left);
	
	printf("%d\t", _node->value);

	print_tree(_node->right);
}
