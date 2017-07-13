#pragma once
#include "Address.h"
using namespace std;

class Customer;
ostream &operator<<(ostream &strm, Customer &obj);

class Customer
{
private:
	string number;
	string name;
	Address address;

public:
	Customer();
	Customer(string newNumber, string newName, string newStreet, string newCity, string newState, string newZip);
	~Customer();

	//getters
	string getEmployeeNumber() { return number; }
	string getEmployeeName() { return name; }
	Address getEmployeeAddress() { return address; }

	//setters
	void setEployeeNumber(string newNumber) { number = newNumber; }
	void setEmployeeName(string newName) { name = newName; }
	void setAddress(string newStreet, string newCity, string newState, string newZip);

	//operators
	bool operator>(Customer &obj) { return number > obj.number; }
	bool operator<(Customer &obj) { return number < obj.number; }
	bool operator==(Customer &obj) { return number == obj.number; }
	
	//output and input
	friend ostream &operator<<(ostream &strm, Customer &obj);
	//friend istream &operator>>(istream strm, Customer &obj); //I did not know what to write for this overload. 
};

