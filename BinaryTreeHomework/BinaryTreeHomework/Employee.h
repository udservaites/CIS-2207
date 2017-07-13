#pragma once
#include <iostream>
#include <string>
using namespace std;


class Employee
{
private:
	int employeeID;
	string employeeName;
public:
	Employee();
	Employee(int empID, string empName);
	~Employee();

	void print();

	//getters
	int getEmployeeID() { return employeeID; }
	string getEmployeeName() { return employeeName; }

	//setters
	void setEmployeeID(int empID) { employeeID = empID; }
	void setEmployeeName(string empName) { employeeName = empName; }

	//operators
	bool operator>(Employee &obj) { return employeeID > obj.employeeID; }
	bool operator<(Employee &obj) { return employeeID < obj.employeeID; }
	bool operator==(Employee &obj) { return employeeID == obj.employeeID; }
};

