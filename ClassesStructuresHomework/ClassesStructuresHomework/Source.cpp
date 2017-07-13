/*Katrhyn Rebecca Servaites
CIS 1202 N01
09/26/2014
Structure and Classes Homework
Chapter 13 page 805 Programming Problem #8*/


/* Circle Class 
Write a Circle class that has the following member variables: 
•  radius : a double
•  pi : a double initialized with the value 3.14159 (you may make it static)
The class should have the following member functions: 
•  Default Constructor. A default constructor that sets radius to 0.0. 
•  Constructor. Accepts the radius of the circle as an argument. 
•  setRadius. A mutator function for the radius variable. 
•  getRadius. An accessor function for the radius variable. 
•  getArea. Returns the area of the circle, which is calculated as 
area = pi * radius * radius 
•  getDiameter. Returns the diameter of the circle, which is calculated as 
diameter = radius * 2 
•  getCircumference. Returns the circumference of the circle, which is calculated as 
circumference = 2 * pi * radius 
Write a program that demonstrates the Circle class by asking the user for the circle’s 
radius, creating a Circle object, and then reporting the circle’s area, diameter, and 
circumference.*/

#include "Circle.h"

#include <iostream>

using namespace std;

int main() {
	double inputRadius, calculatedArea, calculatedCicumference, calculatedDiameter;
	Circle circleObject; //Object to use class methods

	cout << "Please enter the radius: " << endl; //Get radius from user
	cin >> inputRadius;
	circleObject.setRadius(inputRadius); //Set object radius

	/*Get the calculations and assign them to variables*/
	calculatedDiameter = circleObject.getDiameter();
	calculatedCicumference = circleObject.getCircumference();
	calculatedArea = circleObject.getArea();

	/*Print calculations to screen*/
	cout << "If a circle has a radius of " << inputRadius << " \n"
		<< "The diameter is: " << calculatedDiameter << " \n"
		<< "The circumference is: " << calculatedCicumference << " \n"
		<< "The area is: " << calculatedArea << " \n" << endl;




	system("pause");
	return(0);
}
