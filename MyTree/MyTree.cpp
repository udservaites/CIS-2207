#include "MyTree.h"


MyTree::MyTree(void)
{
	root = nullptr;
}


MyTree::~MyTree(void)
{
}

void MyTree::insert(Node *&current,Node *newNode)
{
	if (current == nullptr)
		current = newNode;
	else if (newNode->value < current->value)
		insert(current->left,newNode);
	else
		insert(current->right,newNode);
}

void MyTree::insert(int item)
{
	Node *newNode = new Node;
	newNode->value = item;
	newNode->left = newNode->right = nullptr;

	insert(root,newNode);
}

int MyTree::getHeight(Node *current)
{
	if (current == nullptr)
		return 0;

	int heightLeft = getHeight(current->left);
	int heightRight = getHeight(current->right);

	return 1 + ((heightLeft > heightRight)?heightLeft:heightRight);
}

int MyTree::getHeight()
{
	return getHeight(root);
}

void MyTree::calcLevels(Node *current, int level, int *levels)
{
	if (current != nullptr)
	{
		levels[level]++;
		calcLevels(current->left,level+1,levels);
		calcLevels(current->right,level+1,levels);
	}
}

int MyTree::getWidth()
{
	int height = getHeight();
	int *levels = new int[height];
	for (int level = 0; level < height; level++)
		levels[level] = 0;

	calcLevels(root,0,levels);

	int maxLevel = 0;

	for (int level = 0; level < height; level++)
	{
		if (maxLevel < levels[level])
			maxLevel = levels[level];
	}

	return maxLevel;
}
