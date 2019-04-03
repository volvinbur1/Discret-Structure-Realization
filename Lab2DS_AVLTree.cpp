//AVL tree
#include <iostream>
#include <fstream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
	int value, high;
	Node *left, *right;
};

Node *insert(Node *_node, int elem_add);
Node *left_rorate(Node *prev_root);
Node *right_rorate(Node *prev_root);
Node *find_node_elem(Node *_node, int elem_find);
int max(int a, int b);
void print_tree(Node *_node);

int main()
{
	Node *tree = NULL;

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

int max(int a, int b)
{
	return a > b ? a : b;
}

Node *insert(Node *_node, int elem_add)
{
	if (_node == NULL)
	{
		_node = new Node;
		_node->value = elem_add;
		_node->high = 1;
		_node->left = NULL;
		_node->right = NULL;
	}
	else if (elem_add > _node->value)
		_node->right = insert(_node->right, elem_add);
	else if (elem_add < _node->value)
		_node->left = insert(_node->left, elem_add);
	else
		return _node;

	_node->high = max((_node->left == NULL ? 0 : _node->left->high), (_node->right == NULL ? 0 : _node->right->high)) + 1;

	int balance_coef = (_node->left == NULL  ? 0 : _node->left->high) - (_node->right == NULL ? 0 : _node->right->high);

	if (balance_coef < -1 && elem_add > _node->right->value) // right right
		return left_rorate(_node);

	if (balance_coef > 1 && elem_add < _node->left->value) // left left
		return right_rorate(_node);

	if (balance_coef > 1 && elem_add > _node->left->value) // left right
	{
		_node->left = left_rorate(_node->left);
		return right_rorate(_node);
	}

	if (balance_coef < -1 && elem_add < _node->right->value) // right left
	{
		_node->right = right_rorate(_node->right);
		return left_rorate(_node);
	}

	return _node;
}

Node *left_rorate(Node *prev_root)
{
	Node *new_root = prev_root->right;
	Node *new_right_leaf = new_root->left;

	new_root->left = prev_root;
	prev_root->right = new_right_leaf;

	prev_root->high = max((prev_root->left == NULL ? 0 : prev_root->left->high), (prev_root->right == NULL ? 0 : prev_root->right->high)) + 1;
	new_root->high = max((new_root->left == NULL ? 0 : new_root->left->high), (new_root->right == NULL ? 0 : new_root->right->high)) + 1;

	return new_root;
}

Node *right_rorate(Node *prev_root)
{
	Node *new_root = prev_root->left;
	Node *new_left_leaf = new_root->right;

	new_root->right = prev_root;
	prev_root->left = new_left_leaf;

	prev_root->high = max((prev_root->left == NULL ? 0 : prev_root->left->high), (prev_root->right == NULL ? 0 : prev_root->right->high)) + 1;
	new_root->high = max((new_root->left == NULL ? 0 : new_root->left->high), (new_root->right == NULL ? 0 : new_root->right->high)) + 1;

	return new_root;
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
