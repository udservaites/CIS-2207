#pragma once
#include "Customer.h"
#include <fstream>
#include<vector>
class BinaryTree
{
private:

	struct BinaryTreeNode{

		Customer value;
		BinaryTreeNode *left;
		BinaryTreeNode *right;
	};

	BinaryTreeNode *root;


	//basic tree functions
	void insert(BinaryTreeNode *&currentPtr, BinaryTreeNode *newNode);
	void remove(BinaryTreeNode *&currentPtr, string empNum); //Remove by employee num
	void deleteTree(BinaryTreeNode *current);
	//search
	void searchCustomerNumber(BinaryTreeNode *current, string empNum, bool &foundIt);
	void searchCustomerName(BinaryTreeNode *current, string empName, bool &foundIt);
	//print
	void listPreFix(BinaryTreeNode *current);
	void printCustomers(BinaryTreeNode *current);
	void listPostFix(BinaryTreeNode *current);
	//save
	void saveArray(Customer *customer, BinaryTreeNode *current, int &i);
	void countNodes(BinaryTreeNode *current, int &i);

public:
	BinaryTree();
	~BinaryTree();
	//print
	void listPreFix();
	void printCustomers();
	void listPostFix();
	//basic tree functions
	void addCustomer(Customer newCustomer);
	void deleteCustomer(string empNum);
	//search functions
	void searchCustomerName(string empName, bool &foundIt);
	void searchCustomerNumber(string empNum, bool &foundIt);
	void countNodes(int &i);
	//save
	void saveArray(Customer *customer);

};

