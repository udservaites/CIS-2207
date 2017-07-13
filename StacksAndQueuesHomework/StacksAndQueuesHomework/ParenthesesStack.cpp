#include "ParenthesesStack.h"
#include <iostream>
using namespace std;


ParenthesesStack::ParenthesesStack()
{
	topNode = nullptr;
}


ParenthesesStack::~ParenthesesStack()
{
}

/*bool ParenthesesStack::isEmpty() {

	if (topNode == nullptr) {
		return true;
	}
}*/

void ParenthesesStack::push(Parentheses newParentheses) {

	Node *newNode = new Node; //Create new Node

	newNode->openParenthesis = newParentheses; //Set the new node 
	newNode->next_ptr = nullptr;

	newNode->next_ptr = topNode; //next_ptr is the address of the old top node
	topNode = newNode; //Set topNode to the new top node which is newNode
	//cout << "added!" << endl; //for testing
}

bool ParenthesesStack::pop() {

	Node *tempNode;
	if (isEmpty() == false) {
		tempNode = topNode; //Hold address of current topNode in a safe place 
		topNode = topNode->next_ptr; //Set new topNode
		delete tempNode; //Deletes the former topNode
		
		//cout << "popped" << endl; //for testing
		return true; //If all went as planned and the stack was not empty, true will be returned
	}
	else {
		return false; //Stack was empty and nothing was popped
	}
	
}

Parentheses ParenthesesStack::top() {

	if (isEmpty()) { //If stack is empty an exception is thrown
		throw "Stack is empty";
	}

	return topNode->openParenthesis;
}
