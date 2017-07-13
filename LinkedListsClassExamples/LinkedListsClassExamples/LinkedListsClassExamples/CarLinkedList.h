#pragma once
#include "Car.h"
#include <string>
#include <iostream>

using namespace std;

class CarLinkedList
{

private:
	struct Node {
		Car value;
		Node *next;
	};

	Node *head;

public:
	CarLinkedList(void);
	~CarLinkedList(void);

	void appendNode(Car car);
	void insertNode(Car car);
	void deleteNode(string plateNumber);
	void display();
	void deleteList();
};

