#pragma once
#include <iostream>
#include <string>
using namespace std;

class Address; 
ostream &operator<< (ostream &strm, Address &obj);

class Address
{
private:
	string street;
	string city;
	string state;
	string zip;

public:
	Address();
	~Address();

	//getters
	string getStreet() { return street; }
	string getCity() { return city; }
	string getState() { return state; }
	string getZip() { return zip; }

	//setters
	void setStreet(string newStreet) { street = newStreet; }
	void setCity(string newCity) { city = newCity; }
	void setState(string newState) { state = newState; }
	void setZip(string newZip) { zip = newZip; }

	//output and input
	friend ostream &operator<<(ostream &strm, Address &obj);
	//friend istream &operator>>(istream &strm, Address &obj); //Not sure what to overload this function with

};

