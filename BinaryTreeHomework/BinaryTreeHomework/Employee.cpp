#include "Employee.h"


Employee::Employee()
{
	employeeID = 0;
	employeeName = "";
}

Employee::Employee(int empID, string empName) {

	employeeID = empID;
	employeeName = empName;
}

Employee::~Employee()
{
}


void Employee::print() {

	cout << "Employee Number: " << employeeID << endl;
	cout << "Employee Name: " << employeeName << endl; 
}