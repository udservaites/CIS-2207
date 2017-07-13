/*Kathryn Rebecca Servaites
CIS 2207.N01
11/08/2014
Chapter 18 Stacks and Queues
Programming Problem 14*/

/* Balanced Parentheses
A string of characters has balanced parentheses if each right parenthesis occurring
in the string is matched with a preceding left parenthesis, in the same way that each
right brace in a C++ program is matched with a preceding left brace. Write a program
that uses a stack to determine whether a string entered at the keyboard has balanced
parentheses.

Samples:

this is a test : OK, no parentheses

this ( is a ) test) : bad, an extra right parentheses

this (is a test) : OK

this ) is a test ( : bad, the right parentheses is not preceeded with a left parentheses*/
#include "Parentheses.h"
#include "ParenthesesStack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	ParenthesesStack stack;
	string statement;
	int stringLength;
	bool stopLoop = false;
	bool addedOpenParentheses = false; /*Use this to check if any open parentheses were ever added to stack. 
									   The balanced parenthese message will print only if any open 
									   parentheses were added to begin with.*/
	//For printing a message if no parentheses were used in the string
	bool addedRightParentheses = false;
	bool addedLeftParentheses = false;

	cout << "Please enter a string with parenetheses: " << endl;
	cin >> statement;
	stringLength = statement.length();

	//cout << statement[2] << endl;

	for (int i = 0; i < stringLength && !stopLoop; i++) {

		if (statement[i] == '(') {
			//then add to stack
			Parentheses newParentheses;
			stack.push(newParentheses);
			//cout << "Success!" << endl; //for testing
			addedOpenParentheses = true;
			addedLeftParentheses = true;
			/*if (stack.isEmpty() == false) {
				//cout << "Not Empty" << endl; //for testing
			}*/
		}

		if (statement[i] == ')') { //then remove from stack
			addedRightParentheses = true;
			if (stack.isEmpty() == false) {
				stack.pop();
				//cout << "Awesome" << endl; //for testing
			}
			else
			if (stack.isEmpty() == true) {
				cout << "Error. You have extra right parentheses. " << endl;
				stopLoop = true;
			}
		}
	}

	/*if at the end of the string, the stack
	is not empty, return an error message*/

	if (stack.isEmpty() == false) {
		cout << "Error. You have extra left parentheses. " << endl;
	}
	else if ((stack.isEmpty() == true) && (addedOpenParentheses == true) && (stopLoop == false)) {
		cout << "The parentheses in your string are balanced! " << endl;
	}
	
	//Message if no parentheses were added
	if (addedLeftParentheses == false && addedRightParentheses == false) {
		cout << "You didn't use any parentheses. You string is okay!!" << endl;
	}





	system("pause");
	return(0);
}
