#include "BinaryTree.h"


BinaryTree::BinaryTree()
{
	root = nullptr;
}


BinaryTree::~BinaryTree()
{
	deleteTree(root);
}

//Recursive method to insert a node into the tree
void BinaryTree::insert(BinaryTreeNode *&current, BinaryTreeNode *newNode) {

	//base case 1: current is null
	if (current == nullptr) {
		current = newNode;
	}
	//base case 2: current->value == newNode->value
	else if (current->value == newNode->value) {
		string exceptionString = "That employee ID already exists.";
		throw exceptionString;
	}
	//genereal case 1: current->value < newNode
	else if (current->value > newNode->value) {
		insert(current->left, newNode);
	}
	//general case 2: current->value > newNode
	else if (current->value < newNode->value) {
		insert(current->right, newNode);
	}
}

//Wrapper function for insert
void BinaryTree::addCustomer(Customer newCustomer) {
	//create new node
	BinaryTreeNode *newNode = new BinaryTreeNode;

	//put customer into newNode
	newNode->value = newCustomer;

	//set left and right pointers
	newNode->left = nullptr;
	newNode->right = nullptr;

	//insert into tree
	insert(root, newNode);
}

//removes a customer from the tree based on customer number
void BinaryTree::remove(BinaryTreeNode *&current, string empNum) {

	//Base case 1: Does node exist?
	if (current == nullptr) {
		//do nothing
		cout << "That customer is not in the database" << endl;
	}
	//base case 2: Match found
	else if (current->value.getEmployeeNumber() == empNum) {
		//create node to hold node to be deleted
		BinaryTreeNode *tempNode = new BinaryTreeNode;
		tempNode = current;

		//check for left and right nodes
		if (current->left == nullptr && current->right == nullptr) {
			current = nullptr;
		}
		//left points to null, right points to something
		else if (current->left == nullptr && current->right != nullptr) {
			current = current->right;
		}
		//left points to something, right points to nullptr
		else if (current->left != nullptr && current->right == nullptr) {
			current = current->left;
		}
		//left and right both point to something
		else {
			BinaryTreeNode *leftMost = current->right;
			while (leftMost->left != nullptr) {
				leftMost = leftMost->left;
			}
			leftMost->left = current->right;
			current = current->right;
		}
		delete tempNode;

	}
	//general case
	else {
		if (empNum < current->value.getEmployeeNumber()) {
			remove(current->left, empNum);
		}
		else {
			remove(current->right, empNum);
		}
	}

}

//wrapper function for remove
void BinaryTree::deleteCustomer(string empNum) {

	remove(root, empNum);
}


//recursive function to search each node for matching customer name. Uses boolean reference to output not found message in main.
void BinaryTree::searchCustomerName(BinaryTreeNode *current, string empName, bool &foundIt) {

	//base case 1: current = nullptr
	if (current == nullptr) {
		//do nothing
		
	}
	//base case 2
	else if (current->value.getEmployeeName().compare(empName) == 0) {
		cout << current->value << endl;
		foundIt = true;
	}
	//general case
	else {
		searchCustomerName(current->left, empName, foundIt);
		searchCustomerName(current->right, empName, foundIt);
	}
}

//wrapper function for searchCustomerName
void BinaryTree::searchCustomerName(string empName, bool &foundIt) {
	searchCustomerName(root, empName, foundIt);
}

//recursive function to find a customer by their number. Uses a boolean reference to output not found message in main.
void BinaryTree::searchCustomerNumber(BinaryTreeNode *current, string empNum, bool &foundIt) {

	//base case 1:
	if (current == nullptr) {
		//do nothing
	}
	//base case 2: found it!
	else if (current->value.getEmployeeNumber() == empNum) {
		cout << current->value << endl;
		foundIt = true;
	}
	//general case
	else {
		if (empNum > current->value.getEmployeeNumber()) {
			searchCustomerNumber(current->right, empNum, foundIt);
		}
		else {
			searchCustomerNumber(current->left, empNum, foundIt);
		}
	}
}

//wrapper function for searchCustomerNumber
void BinaryTree::searchCustomerNumber(string empNum, bool &foundIt) {

	 searchCustomerNumber(root, empNum, foundIt);

}

//recursive function to print tree in pre-order
void BinaryTree::listPreFix(BinaryTreeNode *current) {

	//base case: If nullptr do nothing
	if (current == nullptr) {
		//do nothing
	}
	//general case
	else {
		cout << current->value.getEmployeeNumber() << "\n" << current->value.getEmployeeName() << "\n" << endl;
		listPreFix(current->left);
		listPreFix(current->right);
	}
}

//wrapper function for printPreOrder
void BinaryTree::listPreFix() {

	listPreFix(root);
}

//recursive function to print tree in-order
void BinaryTree::printCustomers(BinaryTreeNode *current) {
	//base case: if null do nothing
	if (current == nullptr) {
		//do nothing
	}
	//general case
	else {
		printCustomers(current->left);
		cout << current->value.getEmployeeNumber() << "\n" << current->value.getEmployeeName() << "\n" << endl;
		printCustomers(current->right);
	}
}

//wrapper function for printInOrder
void BinaryTree::printCustomers() {

	printCustomers(root);
}

//recursive function to print binary tree in post-order
void BinaryTree::listPostFix(BinaryTreeNode *current) {

	//base case
	if (current == nullptr) {
		//do nothing
	}
	//general case
	else {
		listPostFix(current->left);
		listPostFix(current->right);
		cout << current->value.getEmployeeNumber() << "\n" << current->value.getEmployeeName() << "\n" << endl;
	}
}

//wrapper function fot printPostOrder
void BinaryTree::listPostFix() {

	listPostFix(root);
}

//recursive method to delete the tree
void BinaryTree::deleteTree(BinaryTreeNode *current) {

	//base case: if nullptr do nothing
	if (current == nullptr) {
		//do nothing
	}
	//general case: deletes left, right, then current
	else {
		deleteTree(current->left);
		deleteTree(current->right);
		delete current;
	}
}

/*Recursive function to finid total number of nodes in binary tree. 
Used to determine the array size for the array in saveArray*/

void BinaryTree::countNodes(BinaryTreeNode *current, int &i) {
	//base case
	if (current == nullptr) {
		//do nothing
	}
	//general case
	else {
		i++;
		countNodes(current->left, i);
		countNodes(current->right, i);
	}
}

//wrapper function for countNodes
void BinaryTree::countNodes(int &i) {
	countNodes(root, i);
}

//Recursive function that puts BinaryTreeNode->value into an array in preorder sort for saving to a file
void BinaryTree::saveArray(Customer *customer, BinaryTreeNode *current, int &i) {

	//base case
	if (current == nullptr) {
		//do nothing
	}
	
	else {
		customer[i++] = current->value;
		saveArray(customer, current->left, i);		
		saveArray(customer, current->right, i);
		
	}
	
}

//Wrapper function for save array
void BinaryTree::saveArray(Customer *customer) {
	int i = 0;
	saveArray(customer, root, i);
}


