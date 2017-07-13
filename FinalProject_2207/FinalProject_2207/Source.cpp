/*KAthryn Rebecca Servaites
CIS 2207.N01
FInal Project
12/10/2014*/

/*Problem Statement:
You will need to implement an application that will hold the customer list for Acme Anvil Supply.  This list will be
read from a file and stored in a binary tree.  The customer file contains fields with the customer number, name, and address
(street, city, state and zip).  Each field will be in a separate line in the file, thus a given record will be 6 lines in length.
The file will be named Customers.txt.

The application will provide the user with a menu to allow them to:

·         Load the tree from the file
·         Save the tree to the file
·         Add a customer to the tree
·         Remove a customer from the tree
·         Display the list of customers in: (display customer number and name)
o   In-order

o   Pre-order

o   Post-order

·         Search the tree for a given: (display customer number, name and address)
o   Customer Number

o   Customer Name

·         Quit the application
Detail Requirements
You will need to have the following classes:

·         Customer – This class will hold the information for a customer (in files name Customer.cpp and Customer.h):
o   Number

o   Name

o   Address

o   Various setters, getters, operators, including, but not limited to (comparison operators based on the Customer Number):

§  Operator<

§  Operator>

§  Operator==

§  Operator <<

§  Operator >>

·         Address – This class will hold the information for a customer’s address (in files named Address.cpp and Address.h):
o   Street (i.e., 33 N. Main)

o   City

o   State

o   Zip

o   Various setters, getters, operators, including, but not limited to:

§  Operator <<

§  Operator >>

·         BinaryTree – This is the binary tree class holding the information.  Do not use a Template or a Standard
Template to implement this.  Write a custom tree.  Minimally, you will need to implement the following public methods
(in files named BinaryTree.cpp and BinaryTree.h):
o   addCustomer(Customer *)

o   removeCustomer(string customerNumber)

o   searchCustomer(string customerNumber) : Customer*

o   printCustomers() – print a list of customers (in order by customer number) showing all information about the customer.

o    listPreFix() – print a list of customer numbers and names

o   listPostFix() – print a list of customer numbers and names

·         BinaryTreeNode – the nodes used in the binary tree (In files named BinaryTreeNode.h and optionally,
BinaryTreeNode.cpp, you may implement this as a struct or a class)


Sample input file:

00001
Wilee Caytote
123 E. Fifth St.
Phynox
AZ
12345-1234
00002
Dave Wells
444 W. Third St.
Dayton
OH
45402
00012
Robert U. McKey
4986 Boundary St.
Jacksonville
AZ
12345
00123
Ruby B. Edwards
4861 Spring Ave.
Philadelphia
PA
19108*/

#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const string FILENAME = "Customers.txt";
//prototype
char menu();

int main() {

	char choice = ' ';
	string number, name, street, city, state, zip;
	string inFileLine;

	//for testing
	/*
	Customer cust1("00001", "Wilee Caytote", "123 E. Fifth St.", "Phynox", "AZ", "12345-1234");
	Customer cust2("00002", "Dave Wells", "444 W. Third St.", "Dayton", "OH", "45402");
	Customer cust3("00012", "Robert U. McKey", "4986 Boundary St.", "Jacksonville", "AZ", "12345");
	Customer cust4("00123", "Ruby B. Edwards", "4861 Spring Ave.", "Philadelphia", "PA", "19108");
	Customer cust5("00017", "Bart Simpson", "742 Evergreen Terrace", "Spingfield", "Ohio", "45505");
	Customer cust6("00006", "Homer Simpson", "742 Evergreen Terrace", "Spingfield", "Ohio", "45505");
	Customer cust7("00003", "Maggie Simpson", "742 Evergreen Terrace", "Spingfield", "Ohio", "45505");
	Customer cust8("00004", "Marge Simpson", "742 Evergreen Terrace", "Spingfield", "Ohio", "45505");
	Customer cust9("00016", "Lisa Simpson", "742 Evergreen Terrace", "Spingfield", "Ohio", "45505");



	tree1->addCustomer(cust3);
	tree1->addCustomer(cust5);
	tree1->addCustomer(cust1);
	tree1->addCustomer(cust2);
	tree1->addCustomer(cust6);
	tree1->addCustomer(cust9);
	tree1->addCustomer(cust7);
	tree1->addCustomer(cust4);
	tree1->addCustomer(cust8);

	*/
	BinaryTree *tree1 = new BinaryTree;

	//for testing
	//tree1->searchCustomerNumber("00006");
	//tree1->searchCustomerName("Bart Simpson");

	while (choice != 'Q') {
		choice = menu();
		choice = toupper(choice);

		switch (choice) {
		case '1': //add new customer
		{
					  string number, name, street, city, state, zip;
					  char getChar; //Get customer info, store in variables.
					  cout << "Enter Customer Number: ";
					  cin.ignore(100, '\n');
					  getline(cin, number);
					  cout << "Enter Customer Name: ";
					  getline(cin, name);
					  cout << "Enter Customer Street Address: ";
					  getline(cin, street);
					  cout << "Enter Customer City: ";
					  getline(cin, city);
					  cout << "Enter Customer State: ";
					  getline(cin, state);
					  cout << "Enter Customer Zip: ";
					  getline(cin, zip);
					  Customer *custObj = new Customer(number, name, street, city, state, zip); //construct new customer object with variables
					  try {
						  tree1->addCustomer(*custObj);//insert customer into the tree
						  cout << "Customer entered into the tree! " << endl; //success message
					  }
					  catch (string str) { //catches exception
						  cout << str << endl;
					  }
					  
		}
			break;

		case '2': //delete customer
		{
					  string number;
					  cout << "Enter the Customer Number:";
					  cin.ignore(100, '\n'); //get the customer number
					  getline(cin, number);
					  tree1->deleteCustomer(number);//delete node from tree that has that customer number
					  cout << "Customer: " << number << " has been removed from the database." << endl; //success message
		}
			break;

		case '3': //load from file
		{

					  string number, name, street, city, state, zip;//variables to hold file information
					  ifstream infile(FILENAME);//open file


					  getline(infile, inFileLine);//initial condition for while loop
					  if (!infile == true) {
						  cout << "Could not find file." << endl; //if computer can't find file
					  }
					  else { //Yea! File found!
						  cout << "Loading file..." << endl;
						  while (!infile.eof()) {
							  number = inFileLine; //reads in all lines for customer object fields
							  getline(infile, inFileLine);
							  name = inFileLine;
							  getline(infile, inFileLine);
							  street = inFileLine;
							  getline(infile, inFileLine);
							  city = inFileLine;
							  getline(infile, inFileLine);
							  state = inFileLine;
							  getline(infile, inFileLine);
							  zip = inFileLine;

							  Customer *customer = new Customer(number, name, street, city, state, zip); //create a customer object with data from text file
							  try {
								  tree1->addCustomer(*customer); //Insert customer object into binary tree
							  }
							  catch (string str) {
								  cout << str << endl;
							  }
							 // cout << *customer << endl; //for testing

							  getline(infile, inFileLine); //set up for next loop iteration
						  }
					  }
					  infile.close(); //close file
					  cout << "Done" << endl; //file has loaded into binary tree
		}
			break;

		case '4': //save to file
		{
					  int count = 0;
					  tree1->countNodes(count); //get count of nodes for array
					  // cout << count << endl; //for testing

					  Customer *customer = new Customer[count]; //create new array the size of count
					  tree1->saveArray(customer); //Put Customer objects from nodes into array

					  /*for (int i = 0; i < count; i++) { //for testing
						  cout << customer[i] << endl;
						  }*/

					  ofstream outfile(FILENAME); //open file
					  cout << "Opening file to write data..." << endl;

					  if (!outfile == true) {//check if file exists
						  cout << "Could not open file" << endl;
					  }
					  else {//if file exists, write to it
						  cout << "Writing..." << endl;
						  for (int i = 0; i < count; i++) { //loops through array and puts each object into text file, one line for each field
							  outfile << customer[i].getEmployeeNumber() << endl;
							  outfile << customer[i].getEmployeeName() << endl;
							  outfile << customer[i].getEmployeeAddress().getStreet() << endl;
							  outfile << customer[i].getEmployeeAddress().getCity() << endl;
							  outfile << customer[i].getEmployeeAddress().getState() << endl;
							  outfile << customer[i].getEmployeeAddress().getZip() << endl;
						  }
						  outfile.close();
						  cout << "Done" << endl; //file written
					  }
		}
			break;

		case '5': //Display in PreOrder

			tree1->listPreFix();
			break;

		case '6'://Display In-Order
			tree1->printCustomers();
			break;

		case '7': //Display in Post-Order

			tree1->listPostFix();
			break;

		case '8': //search by customer name;
		{
					  string name;
					  char getChar;
					  bool foundIt = false;

					  cout << "Enter the customer's name: " << endl;
					  cin.ignore(100, '\n');
					  getline(cin, name); //user inputs name to search
					   
					  tree1->searchCustomerName(name, foundIt);//if found, foundIt will be changed to true and function will print customer data
					  if (foundIt == false) {//customer not found
						  cout << "That name was not found in the database. \nPlease check your spelling and try again. " << endl;
					  }
					  
		}
			break;
		case '9': //search by customer number
		{
					string number;
					bool foundIt = false;
					cout << "Enter the customer's number: ";
					cin.ignore(100, '\n');
					getline(cin, number); //user inputs customer number to search
					tree1->searchCustomerNumber(number, foundIt); //if found, function will set foundIt to true and print customer data
					
					if (foundIt == false) {//customer not found
						cout << "That customer number was not found in the database." << endl;
					}
		}
			break;
		case 'Q': //quit the application
			return(0);
			break;
		default: //for erronous menu entries
			cout << "That is an invalid entry. Please enter a choice from the menu." << endl;
		}

	}
	delete tree1; //delete tree
	//system("pause");
	//return(0);
}

char menu() { //menu for program
	char choice = ' ';
	cout << "\n\nMenu" << endl;
	cout << "1. Add new customer " << endl; //Add fields into object. Pass object through addCustomer function
	cout << "2. Delete customer " << endl;
	cout << "3. Load from file " << endl;
	cout << "4. Save to file " << endl;
	cout << "5. Display customer list Pre-Fix " << endl;
	cout << "6. Display customer list " << endl;
	cout << "7. Display customer list Post-Fix " << endl;
	cout << "8. Search by customer name " << endl;
	cout << "9. Search by customer number " << endl;
	cout << "Q. Quit " << endl;
	cin >> choice;

	return choice;
}