#pragma once
#include "Parentheses.h"

class ParenthesesStack
{
	struct Node {

		Parentheses openParenthesis;
		Node *next_ptr;
	};

private: 
	Node *topNode; //Pointer to first in stack

public:
	ParenthesesStack();
	~ParenthesesStack();

	void push(Parentheses newParentheses);
	bool pop();
	Parentheses top();

	//Helper Functions

	bool isEmpty() { return topNode == nullptr; };
	bool isFull() { return false; }
};

