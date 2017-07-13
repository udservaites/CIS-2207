/*
Kathryn Rebecca Servaites
CIS 2207.N01
10/1/2014
More on Classes Homework Chapter 14 page 888 #13*/

/*  Carpet Calculator 
The Westfield Carpet Company has asked you to write an application that calculates 
the price of carpeting for rectangular rooms. To calculate the price, you multiply 
the area of the floor (width times length) by the price per square foot of carpet. 
For example, the area of floor that is 12 feet long and 10 feet wide is 120 square 
feet. To cover that floor with carpet that costs $8 per square foot would cost $960. 
(12 10 8 960.) 
First, you should create a class named RoomDimension that has two FeetInches
objects as attributes: one for the length of the room and one for the width. (You should 
use the version of the FeetInches class that you created in Programming Challenge 11 
with the addition of a multiply member function. You can use this function to calculate the area of the room.) 
The RoomDimension class should have a member function 
that returns the area of the room as a FeetInches object. 
Next, you should create a RoomCarpet class that has a RoomDimension object as an 
attribute. It should also have an attribute for the cost of the carpet per square foot. 
The RoomCarpet class should have a member function that returns the total cost of 
the carpet. */


#include "FeetInches.h"
#include "RoomCarpet.h"
#include "RoomDimension.h"

#include <iostream>
#include <iomanip>

int main() {
	int widthFeet, widthInches, lengthFeet, lengthInches;
	double cost, totalCost;

	//Get input from user
	cout << "Please enter the width feet and inches seperated by a space: ";
	cin >> widthFeet >> widthInches;
	cout << "Please enter the length feet and inches seperated by a space: ";
	cin >> lengthFeet >> lengthInches;
	cout << "Please enter the price per foot of the carpet: ";
	cin >> cost;

	//Create two FeetInches object to hold dimensions
	FeetInches *width = new FeetInches(widthFeet, widthInches);
	FeetInches *length = new FeetInches(lengthFeet, lengthInches);

	//Create RoomDimension object to hold FeetInches objects and to calculate area
	RoomDimension *rmObject = new RoomDimension(*length, *width);
	cout << "The area is: " << (*rmObject).calculateArea() << endl;

	//Create RoomCarpet object to hold RoomDimension object and calculate price
	RoomCarpet *rmCarpetObject = new RoomCarpet(*rmObject, cost);
	
	//Print/Calculate price of carpet
	cout << setprecision(2) << fixed;
	cout << "The total cost of the carpet is: $" << (*rmCarpetObject).calculateTotalCost() << endl;

	//Delete memory
	delete width;
	delete length;
	delete rmObject;
	delete rmCarpetObject;

	system("pause");
	return(0);
}