#pragma once
#include "Employee.h"
#include <vector>
class EmployeeTree
{
private:

	struct Node {

		Employee value;
		Node *left;
		Node *right;
	};

	Node *root;

	void insert(Node *&currentPtr, Node *newNode);
	void remove(Node *&currentPtr, int empNum);
	void printInOrder(Node *currentPtr);
	void printPreOrder(Node *currentPtr);
	void printPostOrder(Node *currentPtr);
	void getTreeWidth(Node *current, int level, vector <int> levelArray);
	int getTreeHeight(Node *current);
	Employee *find(Node *current, int empNum);

	void deleteTree(Node *currentPtr);
	
public:
	EmployeeTree();
	~EmployeeTree();

	void insert(int empNum, string empName);
	void insert(Employee &item);
	void remove(int empNum);
	bool search(int empNum);
	

	int EmployeeTree::getTreeWidth();
	int EmployeeTree::getTreeHeight();
	void find(int empNum);

	void printInOrder();
	void printPreOrder();
	void printPostOrder();
};

