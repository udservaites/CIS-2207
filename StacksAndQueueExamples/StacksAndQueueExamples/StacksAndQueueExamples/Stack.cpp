#include "Stack.h"


Stack::Stack(void)
{
	//sets topNode = null
	topNode = nullptr;
}


Stack::~Stack(void)
{
	while(!isEmpty()) {
		pop();
	}
}

/*bool isEmpty() {
	if (topNode == nullptr) {
		return true;
	}
}*/

void Stack::push(InventoryBin item) {

	Node *newNode = new Node; //Create a new node
	//Allocate the node
	newNode->data = item;
	/*The next line does not have to be entered. It is good practice
	to write it and then comment it out*/
	//newNode->next = nullptr;

	newNode->next = topNode;
	topNode = newNode;
}

void Stack::pop() {
	Node *tempNode;
	if(!isEmpty()) {
		tempNode = topNode;
		topNode = topNode->next;
		/*This will work, but the memory is still allocated.
		Take care of this problem by using a tempNode and then delete it*/
		//After it has been removed from the stack, delete it.
		delete tempNode;
	}
}

InventoryBin Stack::top() {

	if(isEmpty()) {
		throw "Stack is Empty";
	}
	return topNode->data;
}