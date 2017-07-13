#pragma once
class MyTree
{
private:
	struct Node 
	{
		int value;
		Node *left;
		Node *right;
	};

	Node *root;

	int getHeight(Node *current);
	void calcLevels(Node *current, int level, int *levels);
	void insert(Node *&current,Node *newNode);

public:
	MyTree(void);
	~MyTree(void);

	void insert(int item);
	int getHeight();
	int getWidth();
};

