//Chapter 14 problem examples
// Implement feetInches from the book
#include "FeetInches.h"

#include <iostream>

using namespace std;

int main() {

	int feet, inches;

	cout << "Please enter number feet: ";
	cin >> feet;

	cout << "Please enter number inches: ";
	cin >> inches;

	FeetInches *distance = new FeetInches(feet, inches);
	const FeetInches oneInch(0, 1);

	

	//distance->setInches(5);

	cout << distance << endl; //This will print becuase it is a refence to the object. It knows how to print pointers

	cout << *distance << endl; //It doesn't know how to print this. Let's overload it. 

	cout << (*distance) - oneInch << endl;

	cout << --(*distance) << endl;
	cout << (*distance)-- << endl;
	cout << (*distance)-- << endl;


	FeetInches *distance2 = new FeetInches(*distance); //Uses copy constructor
	distance2++;

	cout << "Original : " << *distance << endl;
	cout << "A copy.." << *distance2 << endl;

	if (*distance < oneInch)
	cout << "It is too small..." << endl;
	

	delete distance2; //When you use a new, you should always put in a delete at the bottom. 
	delete distance;
	system("pause");

	return(0);
}