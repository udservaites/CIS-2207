
#include "Car.h"
#include "CarLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	Car *newCar= new Car("Geo", "Metro", "ARD-1121"); //Dynamic declaration
	CarLinkedList list;
	Car car2("Chevy", "Colorado", "ABC 123"); //Static declariation

	cout << "Car: " << (*newCar).toString() << endl;

	//Append
	cout << "List prior to any append" << endl;
	list.display();

	list.appendNode(*newCar);

	cout << "List after first append: " << endl;
	list.display();

	//Insert
	Car car3;
	cout << "List prior to any insert" << endl;
	list.display();

	list.appendNode(*newCar);

	cout << "List after second insert: " << endl;
	list.display();
	//last
	list.deleteNode("ZZZ 123");
	list.display();
	//center
	list.deleteNode("ARD-1121");
	list.display();
	//first
	list.deleteNode("ABC 123");
	list.display();


	system("pause");
	return(0);

}