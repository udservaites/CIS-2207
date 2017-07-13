#pragma once
#include "InventoryBin.h"


class Queue
{
	struct Node {

		InventoryBin data;
		Node *next;
	};

private:
	Node *front; /*Points to the front of the queue (top, head)*/
	Node *rear; /*Points to the rear of the queue. When we add, we add it after here
				We could just have the head of the linked list we are using for the 
				queue and cycle though until the end of the list and append*/
public:
	Queue(void);
	~Queue(void);

	void enqueue(InventoryBin item);
	void dequeue();
	InventoryBin getFront();

	bool isEmpty() {return front == nullptr;}
	bool isFull() {return false;}
};

