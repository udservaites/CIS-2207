/*Chapter 20 Example problems
Retail Inventory program*/

#include "RetailItem.h"
#include "RetailItemTree.h"

#include <iostream>
using namespace std;

void testRetailItem();
int main() {

	testRetailItem();

	system("pause"); //Don't need a pause if you use a menu driven program
	return(0);
}

void testRetailItem() {
	RetailItem *item1 = new RetailItem("S 12532", "Widget", 42, 5.25);
	RetailItem *item2 = new RetailItem("S 32523", "Anvil", 3, 45.00);

	cout << "item1 < item2: " << ((*item1) < (*item2)) << endl;
	cout << "item1 > item2: " << ((*item1) > (*item2)) << endl;
	cout << "item1 == item2: " << ((*item1) == (*item2)) << endl;
	cout << "item1 == item1: " << ((*item1) == (*item1)) << endl;

	item1->print();
	item2->print();
}

void testRetailItemTree() {

	RetailItemTree *tree = new RetailItemTree();
	RetailItem *item1 = new RetailItem("S 12532", "Widget", 42, 5.25);
	RetailItem *item2 = new RetailItem("S 32523", "Anvil", 3, 45.00);

	tree->insert(*item1);
	tree->insert(*item2);
	tree->insert("{S 00234", "Foo", 5, 3.56)
}