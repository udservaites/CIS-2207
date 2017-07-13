
#include <iostream>
#include <string>
using namespace std;

void printDate(int day, int month, int year);

int main()
{
	/*This will throw an error because it is thorwing an c++ style string, 
	(char[]) and you need it to handle it as a pointer. */
	try {
	printDate(-1, 0, 12);
	}
	catch (string msg) {

	}
	
//Try doing it like this. We have to be careful of what we throw,
//because of what we catch.
try {
	printDate(-1, 0, 12);
	}
catch(char *msg) {
	cout << msg << endl;
}
	catch (string *msg) {
		cout << msg << endl;
	}


	system("pause");
	return(0);
}
//This throws a string
void printDate(int day, int month, int year) {

	if (day < 1 || day > 31) {
		throw "Invalid Day";
		if (month < 1 || month > 12) {
			throw "Invalid Month";

			cout << month << "/" << day << "/" << year;
		}

	}
}

//This is throwing a pointer to a c++ style string
void printDate(int day, int month, int year) {

	if (day < 1 || day > 31) {
		throw new string ("Invalid Day");
		if (month < 1 || month > 12) {
			throw new string ("Invalid Month");

			cout << month << "/" << day << "/" << year;
		}

	}
}

int times10 (