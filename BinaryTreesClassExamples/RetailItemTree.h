#pragma once

#include "RetailItem.h"


class RetailItemTree
{
private:
	struct Node {

	RetailItem value; //Data value we are storing
	Node *left; //Left node
	Node *right; //Right node

	};

	Node *root; //never initialize variables here in the header file!!!! Only in the constructors should you initilize. 

	void insert(Node *&currentPtr, Node *newNode); //Passing a reference to current node


public:
	RetailItemTree(void);
	~RetailItemTree(void);

	//All of tehse we will eventually make recursive
	void insert(string sku, string description, int quantity, double prince); //Arguements Same as constructor for RetailItem
	void RetailItemTree::insert(Node *&current, Node *newNode);
	void RetailItemTree::insert(RetailItem &item);
	void remove(string sku);
	bool search(string sku); //Return bool or the item found. Often search returns a bool, find returns the item found
	RetailItem &find(string sku);

	//We want to be able to print the tree inorder, preorder, postorder

	void printInOrder(Node *currentPtr); //No arguement needed for these functions
	void printPreOrder(Node *currentPtr);
	void printPostOrder(Node *currentPtr);

	void deleteTree(Node *current);


};

