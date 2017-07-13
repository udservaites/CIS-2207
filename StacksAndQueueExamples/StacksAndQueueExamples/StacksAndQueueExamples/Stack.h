#pragma once
#include "InventoryBin.h"

class Stack
{
	struct Node {

		InventoryBin data;
		Node *next;

	};
private:
	/*It's not a good idea to call the first in stack top 
	becasue there is a method called top.*/
	Node *topNode;
public:
	Stack(void);
	~Stack(void);

	void push(InventoryBin item);
	void pop(); /*It's a good idea to return something even for an empty stack. You could use
		a bool to indicate whether it is empty or not*/
	InventoryBin top();

	//helper functions

	bool isEmpty() {return topNode == nullptr;}
	bool isFull() {return false;}

};

