#include "EmployeeTree.h"
#include <algorithm>

EmployeeTree::EmployeeTree()
{
	root = nullptr;
}


EmployeeTree::~EmployeeTree()
{
	deleteTree(root);
}

//Recursive method to insert a node into the tree

void EmployeeTree::insert(Node *&current, Node *newNode) {

	//base case 1: current is null
	if (current == nullptr) {
		current = newNode;
	}
	//base case 2: current->value == newNode->value
	else if (current->value == newNode->value) {
		throw "That employee ID already exists. ";
	}
	//general case 1: current->value < newNode->value
	else if (current->value < newNode->value) {
		/*will go to left node and then keep calling function and going through the tree
		until it hits a nullptr*/
		insert(current->left, newNode);
	}
	//general case 2: current->value > newNode->value
	else if (current->value > newNode->value) {
		/*will go to right node and then keep calling function and going through the tree
		until it hits a nullptr*/
		insert(current->right, newNode);
	}
}

//Non-recursive method that calls recursive method insert to insert iteminto tree

void EmployeeTree::insert(int empNum, string empName) {
	//new employee object 
	Employee *newEmployee = new Employee(empNum, empName);
	//create a node to add to tree
	Node *newNode = new Node;
	//set value of newEmployee to value of newNode
	newNode->value = *newEmployee;
	//set left and right inside newNode
	newNode->left = nullptr;
	newNode->right = nullptr;

	//now insert into tree
	insert(root, newNode);

}

//Non-recursive method that calls recursive method insert to insert an item into the tree

void EmployeeTree::insert(Employee &emp) {

	//create new node
	Node *newNode = new Node;
	//set value to emp
	newNode->value = emp;
	//set left and right pointers to nullptr
	newNode->left = nullptr;
	newNode->right = nullptr;

	insert(root, newNode);
}

int EmployeeTree::getTreeHeight(Node *current) {

	//base case:
	if (current == nullptr) {
		return 0;
	}
	else {
		int leftHeight = getTreeHeight(current->left);
		int rightHeight = getTreeHeight(current->right);

		return max(leftHeight, rightHeight) + 1;
	}
}

int EmployeeTree::getTreeHeight() {

	return getTreeHeight(root);
}
//Recursive function to tell you how many nodes wide the tree is
//I can't figure this one out. Too hard!!! :)
void EmployeeTree::getTreeWidth(Node *current, int level, vector <int> levelVector) {

	int height = getTreeHeight();
	int max = 0;

	//base case
	if (current == nullptr) {
		//do nothing
	}
	//General case
	else if (current->left) {
		levelVector[level + 1]++;
		getTreeWidth(current->left, level + 1, levelVector);
	}
	else if (current->right) {
		levelVector[level + 1]++;
		getTreeWidth(current->right, level + 1, levelVector);
	}
		/*
	{

		
		getTreeWidth(current->left, level + 1, levelVector);
		levelVector[level]++;		
		getTreeWidth(current->right, level + 1, levelVector);
		levelVector[level]++;
		
	}*/

	
	
	
}
int EmployeeTree::getTreeWidth() {
	int size = getTreeHeight();
	
	int max = 0;
	vector <int> widthVector(size);

	getTreeWidth(root, 0, widthVector);
	
	for (int i = 0; i < size; i++) {
		if (max < widthVector[i]) {
			max = widthVector[i];
		}
	}

	return max;
}

Employee *EmployeeTree::find(Node *current, int empNum) {
	//Base case 1:
	if (current == nullptr) {
		return nullptr;
	}
	//Base case 2:
	else if (current->value.getEmployeeID() == empNum) {
		return &current->value;
	}
	//General case:
	else {
		//go right or left
		if (empNum < current->value.getEmployeeID()) {
			return find(current->right, empNum);
		}
		else {
			return find(current->left, empNum);
		}
	}
}

//wrapper for find

void EmployeeTree::find(int empNum) {

	Employee *found = find(root, empNum);

	if (found == nullptr) {
		cout << "That employee does not exist." << endl;
	}
	else {
		cout << " Employee Number: " << found->getEmployeeID() << endl;
		cout << "Employee Name: " << found->getEmployeeName() << endl;
	}
}

void EmployeeTree::deleteTree(Node *current) {
	//base case
	if (current == nullptr) {
		//do nothing
	}
	else {
		deleteTree(current->left);
		deleteTree(current->right);
		delete current;
	}
}


/*I know the following functions were't required for the assignment. I just wanted some more practice with them. :)*/

//Prints left nodes, current node, right nodes. Prints in descending order.
void EmployeeTree::printInOrder(Node *current) {

	//Base case: If null, do nothing

	//General case
	if (current != nullptr) {
		//prints the left nodes
		printInOrder(current->left);
		//prints the current node
		cout << current->value.getEmployeeID() << endl;
		//prints the right nodes
		printInOrder(current->right);
	}
}

void EmployeeTree::printInOrder() {

	printInOrder(root);
}

//Prints curent node, left nodes, right nodes
/*Prints the current node, then the left side of the tree. Goes the the left side first,
then gets the right side. In each subtree, the left nodes are printed first.*/
void EmployeeTree::printPreOrder(Node *current) {

	//Base case: Do nothing

	//General case:
	if (current != nullptr) {

		//prints current node
		cout << current->value.getEmployeeID() << endl;
		//prints left node
		printPreOrder(current->left);
		//prints right node
		printPreOrder(current->right);

	}
}

void EmployeeTree::printPreOrder() {

	printPreOrder(root);
}

/*Prints the leftmost node first, then right nodes. Then it will
print the right side of the tree starting with the leftmost nodes, then the rightmost nodes.
Current(the first node) is printed last.*/
void EmployeeTree::printPostOrder(Node *current) {

	//Base case: do nothing

	//General Case:
	if (current != nullptr) {

		printPostOrder(current->left);
		printPostOrder(current->right);
		cout << current->value.getEmployeeID() << endl;

	}
}

void EmployeeTree::printPostOrder() {

	printPostOrder(root);
}

void EmployeeTree::remove(Node *&current, int empNum) {

	//Base Case 1: Does the node exist?
	if (current == nullptr) {
		//do nothing
	}
	//Base Case 2: Item was found
	else if (current->value.getEmployeeID() == empNum) {

		//Create a temp node pointer and set it equal to current
		Node *tempPtr = current;

		//Check every case of nodes that may be attached to current node
		//Left and right point to null
		if (current->left == nullptr && current->right == nullptr) {
			current = nullptr;
		}
		//Left points to null, right points to somthing
		else if (current->left == nullptr && current->right != nullptr) {
			current = current->right;
		}
		//Left points to something, right points to null
		else if (current->left != nullptr && current->right == nullptr) {
			current = current->left;
		}
		//Left and right both point to something
		else {
			Node *leftMost = current->right;
			while (leftMost->left != nullptr) {
				leftMost = leftMost->left;
			}
			leftMost->left = current->left;
			current = current->right;
		}
		delete tempPtr;
	}
	//General Case:
	else {
		if (empNum < current->value.getEmployeeID()) {
			remove(current->left, empNum);
		}
		else {
			remove(current->right, empNum);
		}
	}

}

void EmployeeTree::remove(int empNum) {

	remove(root, empNum);
}

