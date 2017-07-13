/*K Rebecca Servaites
CIS 2207.N01
12-7-2014
Binary Tree Homework*/

/*On pages 1182 and 1183, do problems 8, 4 and 5

Employee Tree with Tree Height and Tree Width:

Design an EmployeeInfo class that holds the following empolyee inforamtion:

employee ID Number -- an integer
Employee Name -- a string
Next, create a tree based on a NON TEMPLETED binary tree you implement yourself 
(Do not use a template or a STL tree).  This tree will hold EmployeeInfo class.  
The node should be sorted on the Employee ID Number.

Test the binary tree by inserting nodes ith the following information:

Employee ID Number	Name
1021	John Williams
1057	Bill Witherspoon
2487	Jennifer Twain
3769	Sophia Lancaster
1017	Debbie Reece
1275	George McMullen
1899	Ashley Smith
4218	Josh Plemmons
Your program will allow the user to enter an ID number, then search the tree for the number.  
If the number is found, it should display the employee's name.  If the node is not found, it will 
display a message indicating so.

When your program is finished, it will also display the Tree Height and Width.

Write a member function for your tree that returns the height of the tree.  The height of the
tree is the number of levels it contains.  For example, the tree shown in Figure 20-10 has three levels.

Write a member function for your tree that returns the width of the tree.  The width of a tree 
is the largest number of nodes in the same level.  For exeample, the tree shown in Figure 20-10 
has a width of two.*/

#include"Employee.h"
#include"EmployeeTree.h"

#include <iostream>
#include <string>



using namespace std;

int main() {

	Employee *emp1 = new Employee(1021, "John Williams");
	Employee *emp2 = new Employee(2487, "Jennider Twain");
	Employee *emp3 = new Employee(3769, "Sophia Lancaster");
	Employee *emp4 = new Employee(1017, "Debbie Reece");
	Employee *emp5 = new Employee(1275, "George McMullen");
	Employee *emp6 = new Employee(1899, "Ashley Smith");
	Employee *emp7 = new Employee(4218, "Josh Plemmons");

	Employee *emp8 = new Employee(1000, "Becca Servaites");
	Employee *emp9 = new Employee(9, "Luke Skywalker");
	Employee *emp10 = new Employee(1015, "Han Solo");
	Employee *emp11 = new Employee(3768, "Leia Organa");
	Employee *emp12 = new Employee(4219, "Wedge Antilles");
	Employee *emp13 = new Employee(1001, "Darth Vader");

	EmployeeTree *empTree1 = new EmployeeTree();
	int search;

	empTree1->insert(*emp1);
	empTree1->insert(*emp2);
	empTree1->insert(*emp3);
	empTree1->insert(*emp4);
	empTree1->insert(*emp5);
	empTree1->insert(*emp6);
	empTree1->insert(*emp7);
	empTree1->insert(*emp8);
	empTree1->insert(*emp9);
	empTree1->insert(*emp10);
	empTree1->insert(*emp11);
	empTree1->insert(*emp12);
	empTree1->insert(*emp13);

	/*cout << "Print In-order:" << endl;
	empTree1->printInOrder();
	cout << "Print Pre-Order: " << endl;
	empTree1->printPreOrder();
	cout << "Print Post-Order: " << endl;
	empTree1->printPostOrder();*/

	cout << "Please enter the employee number you wish to search: " << endl;
	cin >> search;
	empTree1->find(search);
	

	cout << "\nHeight of tree : " << empTree1->getTreeHeight() << endl;

	cout << "Width of tree: " << empTree1->getTreeWidth() << endl;

	system("pause");
	return(0);
}
