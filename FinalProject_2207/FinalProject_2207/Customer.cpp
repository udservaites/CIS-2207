#include "Customer.h"


Customer::Customer()
{
	number = "";
	name = "";
	
}


Customer::~Customer()
{
}

Customer::Customer(string newNumber, string newName, string newStreet, string newCity, string newState, string newZip) {
	
	number = newNumber;
	name = newName;
	setAddress(newStreet, newCity, newState, newZip);
}

void Customer::setAddress(string newStreet, string newCity, string newState, string newZip) {

	address.setStreet(newStreet);
	address.setCity(newCity);
	address.setState(newState);
	address.setZip(newZip);
}

ostream &operator<<(ostream &strm, Customer &obj) {

	strm << obj.number << "\n" << obj.name << obj.address;

	return strm;
}