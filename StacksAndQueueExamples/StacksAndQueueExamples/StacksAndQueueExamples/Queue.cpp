#include "Queue.h"


Queue::Queue(void)
{
	front = rear = nullptr;
}


Queue::~Queue(void)
{
	while(!isEmpty()) {
		dequeue();
	}
}

void Queue::enqueue(InventoryBin item) {
	Node *newNode = new Node; //Create a new node
	//Allocate the node
	newNode->data = item;
	newNode->next = nullptr; //We need this this time

	if(!isEmpty()) {
		front = rear = newNode; //They are both the same when empty
	}else {
		rear->next = newNode; /*rear->next should be pointing to nullptr. Now it
							  points to the newNode. NewNode->next points to nullptr*/
	}
}

void Queue::dequeue() {

	if(isEmpty) {
		throw "Queue is empty!!!!";
	}

	Node *tempPtr = front;

	front = front->next; /*This takes whatever is the first item in the queue off. 
						 If we took the last item off and the queue is empty, set rear to null*/
	if(isEmpty()) {

		rear = nullptr;
	}
	
}

InventoryBin Queue:: getFront() {

}