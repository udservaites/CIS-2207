#include "RetailItemTree.h"

#include <iostream>
using namespace std;


RetailItemTree::RetailItemTree(void)
{
	//Set root equal to null
	root = nullptr;
	deleteTree(root);
}


RetailItemTree::~RetailItemTree(void)
{
	/*When you have a tree and you want to remove everything in the tree, 
	you call a recursive functrion that deletes every node in the tree. 
	Delete post order to get every node. You don't have to worry about temp nodes.*/


}
void RetailItemTree::insert(Node *&current, Node *newNode) { //Noed *&current is a reference to a pointer that points to root.
	//base case 1 -- current is null //This has to go first becuase if current is null and you try to access value fo current, you will egt a run time eror. 
	if (current == nullptr) {
		current = newNode;
	}
	//base case 2 -- current->value == newNode->value
	else if(current->value == newNode->value) {
		throw "Hey Stupid, that is already there...";
	}
	//general case 1 -- current_.value < newNode->value
	else if(current->value > newNode->value) {
		insert(current->left, newNode);
	}
	//general case 2 -- current->value > newNode->value
	else {
		insert(current->right, newNode);

	}
}

void RetailItemTree::insert(string sku, string description, int quantity, double price) {

	//Create the node
	RetailItem *newRetailItem = new RetailItem(sku, description, quantity, price); //Instance of retailitem
	Node *newNode = newNode; //instance of node
	newNode->value = (*newRetailItem); //
	newNode->left = newNode->right = nullptr;

	/*Base cases:
	1. Empty tree
	2. Pointing to a null(leaf)
	3. Sku already in the list
	If sku is the same and description is the same, change the price and quantity. If the description is
	different then throw an error.  and 2 are similar becuase of nullptr

	General case:
	1. If the value is less than the current node, insert it into the left subtree. greater than, right
	subtree. 


	*/
}

void RetailItemTree::insert(RetailItem &item) {

	//Create the node
	RetailItem *newRetailItem = new RetailItem(); //Instance of retailitem
	Node *newNode = newNode; //instance of node
	newNode->value = (*newRetailItem); //
	newNode->left = newNode->right = nullptr;

}

void RetailItemTree::printInOrder(Node *current){
	//base case
	if(current == nullptr) {
		//do nothing
	}
	else {
		printInOrder(current->left);
		cout << current->value.getSku() << endl;
		printInOrder(current->right);
	}
	/*
	//base case, if null, do nothing
	//general case
	if(current != nullptr) {
	printInOrder(current->left);
	cout << current->value.getSku() << endl;
	printInOrder(current->right);
	} */

	//Always point out the base case and the general case. 
}

void RetailItemTree::printInOrder(Node *currentPtr){//No arguement needed for these functions
	printInOrder(root);
}

void RetailItemTree:: printPreOrder(Node *current) {

}
void RetailItemTree::printPreOrder(){
	printPreOrder(root);
}
void RetailItemTree::printPostOrder(Node *current) {
	if(current != nullptr) {
		printPostOrder(current->left);
		printPostOrder(current->right);
		printPostOrder(current->value);
	}
}
void RetailItemTree::printPostOrder(){
	printPostOrder(root);
}
//recursive method to delete tree
void RetailItemTree::deleteTree(Node *current) {
	//base case, current is null, do nothing
	//general case, delete left, right, then current

	if(current != nullptr) {

		deleteTree(current->left);
		deleteTree(current->right);
		delete current;
	}
}


/* Recursive method to remove an item */
void RetailItemTree::remove(Node *&current, string sku)
{
	// base case 1, is does the node exist?  i.e., is current == null
	if (current == nullptr)
	{
		// do nothing, the item to delete is not in the tree
	}
	// base case 2, we found the item to remove from the tree...
	else if (current->value.getSKU() == sku)
	{
		Node *tempPtr = current;

		if (current->left == nullptr && current->right == nullptr)
		{
			current = nullptr;
		}
		else if (current->left == nullptr && current->right != nullptr)
		{
			current = current->right;
		}
		else if (current->left != nullptr && current->right == nullptr)
		{
			current = current->left;
		}
		else // current->left != nullptr && current->right != nullptr
		{
			Node *leftMost = current->right;
			while (leftMost->left != nullptr)
				leftMost = leftMost->left;

			leftMost->left = current->left;
			current = current->right;
		}

		delete tempPtr;

	}
	// general case
	else
	{
		if (sku < current->value.getSKU())
			remove(current->left, sku);
		else
			remove(current->right, sku);
	}

}


/* Wrapper method for removal of an item */
void RetailItemTree::remove(string sku)
{
	remove(root, sku);
}


/* Check if an item is in the tree */
bool RetailItemTree::search(string sku)
{
	Node *current = root;
	bool found = false;

	while (!found && current != nullptr)
	{
		if (current->value.getSKU() == sku)
			found = true;
		else if (sku < current->value.getSKU())
			current = current->left;
		else
			current = current->right;
	}

	return found;
}


RetailItem *RetailItemTree::find(Node *current, string sku)
{
	//base case 1 -- 
	if (current == nullptr)
	{
		return nullptr;
	}
	// base case 2, found it
	else if (current->value.getSKU() == sku)
	{
		return &current->value;
	}
	// general cases
	else
	{
		if (sku < current->value.getSKU())
			return find(current->left, sku);
		else
			return find(current->right, sku);
	}
}

RetailItem * const RetailItemTree::find(string sku)
{
	return find(root, sku);
}