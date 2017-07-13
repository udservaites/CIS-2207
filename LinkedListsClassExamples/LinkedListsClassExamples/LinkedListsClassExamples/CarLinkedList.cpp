#include "CarLinkedList.h"



CarLinkedList::CarLinkedList(void)
{
	head = nullptr;
}


CarLinkedList::~CarLinkedList(void)
{
	deleteList();
	//implement later
}


void CarLinkedList::appendNode(Car car) {
	Node *newNode = new Node;
	newNode->value = car;
	newNode->next = nullptr;

	//Check to make sure this works
	cout << car.toString() << endl; //Keep out of indentation to find easily

	if(head == NULL) {
		head = newNode;
	}
	else {
		Node *current = head;
		while (current->next !=NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}
void CarLinkedList:: insertNode(Car car){

	//Create a new node
	Node *newNode = new Node;
	newNode->value = car;
	newNode->next = nullptr;

	if(head == nullptr) {
		head = newNode;
	}else {

		Node *current = head;
		Node *previous = nullptr;
		/*Short cut evaluation is when the first part fo the and statement is false, 
		it will not test the rest of the statement*/
		while (current != NULL && (current->value < newNode->value))//Check if current is null
			
			previous = current;
			current = current->next;

			//If it is a null, we want ot insert at the beginning
			if(previous == NULL) {
				newNode->next = head;
				head = newNode;
			}
			else {
				newNode->next = previous->next;
				previous->next = newNode;
			}
	}
}

void CarLinkedList::deleteNode(string plateNumber){

	if (head!= NULL) {
		//If head = NULL, there is nothing to delete
		Node *current = head;
		Node *previous = nullptr;

		while (current != NULL && (current->value.getLicensePlate() != plateNumber)) {
			previous = current;
			current = current->next;
		}
		if (current == nullptr) {
			//nothing to delete
		}
		else if(previous == nullptr) {
			head = head->next;
		}
		else {
			//The node we just deleted is actually still there, we just
			//don't have any pointers to it. It is causing a memeory leak.
			//Create a temp pointer, remove node from list, then delete node
			//Do not delete node before removing it from the list. 
			//Called Race conditioning. You may not get your list to point where it needs to point. 
			Node *tempNode = current;
			previous->next = current->next;
			delete tempNode;
		}
	}
}
void CarLinkedList::display(){
	Node *current = head;
	while (current !=NULL) {
		cout << "Node: " << current->value.toString() << endl;
		current = current->next;
	}

}
void CarLinkedList:: deleteList(){

}