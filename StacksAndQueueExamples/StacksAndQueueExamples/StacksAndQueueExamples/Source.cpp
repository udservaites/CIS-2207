#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main() {

	Stack stack;
	Queue queue;


	/*try {
	cout <<"Print Top Item" << endl;
	cout << stack.top().getSerialNum() << endl;
	}
	catch (char *msg) {
	cerr << msg << endl;//cerr = Standard error
	}

	system("pause");
	return(0);*/

	char c = showMenu();

	while (c != 'Q') {

		switch (c) {
		case '1': {
					  int serialNumber, lotNumber;
					  string date;
					  cout << "Enter the serial number: ";
					  cin >> serialNumber;
					  cout << "Enter Manufacture Date: ";
					  cin >> date;
					  cout << "Enter Lot Number: ";
					  cin >> lotNumber;

					  InventoryBin ib(serialNumber, date, lotNumber);
					  if (!stack.isFull()) {
						  stack.push(ib);
					  }
		}
			break;
		case '2':
		{
					if (!stack.isEmpty()) {
						InventoryBin ib = stack.top();
						stack.pop();
						cout << "Inventory item Removed From Stack:" << endl;
						cout << "Serial Number: " << ib.getSerialNum() << endl;
						cout << "\tManufacture Date: " << ib.getManufactureDate() << endl;
						cout << "\tLot Number: " << ib.getLotNumber() << endl;
					}
		}
			break;
		case '3':
		{
					int serialNumber, lotNumber;
					string date;
					cout << "Enter the serial number: ";
					cin >> serialNumber;
					cout << "Enter Manufacture Date: ";
					cin >> date;
					cout << "Enter Lot Number: ";
					cin >> lotNumber;
					InventoryBin ib (serialNumber, date, lotNumber);
					if (!queue.isFull()) {
						queue.enqueue(ib);

					}
		}
			break;
		case '4':
		{
					if (!queue.isEmpty()) {
						InventoryBin ib = queue.getFront();
						queue.dequeue();
						cout << "Inventory item Removed From Stack:" << endl;
						cout << "Serial Number: " << ib.getSerialNum() << endl;
						cout << "\tManufacture Date: " << ib.getManufactureDate() << endl;
						cout << "\tLot Number: " << ib.getLotNumber() << endl;

					}
					break;
		case 'Q':
			break;
		default:
			cout << "Invalid entry. Please try again." << endl;
			break;
		}
		}
	}



	system("pause");
	return(0);
}


char showMenu() {
	char c;

	cout << "Welcome to Acme Inventory" << endl;
	cout << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "\t1: Push an item onto the stack" << endl;
	cout << "\t2: Print an item from the stack" << endl;
	cout << "\t3: " << endl;
	cout << "\t4: " << endl;
	cout << "\tQ: QUit" << endl;

	cin >> c;
	c = toupper(c);
	return c;

}
