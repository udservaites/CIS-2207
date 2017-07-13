#include "Circle.h"

/*Constuctors*/
Circle::Circle() {
	radius = 0.0;
	pi;
}

Circle::Circle(double radiusArg) {
	radius = radiusArg;
	pi;
}

/*Set method for radius*/
void Circle::setRadius(double radiusArg){
	radius = radiusArg;
}

/*Get method for radius*/
double Circle::getRadius() {
	return radius;
}

/*Calculates the area of a circle*/
double Circle::getArea() {
	double area;
	area = pi * radius * radius;
	return area;
}

/*Claculates the circumference of a circle*/
double Circle::getCircumference() {
	double circumference;
	circumference = 2 * radius * pi;
	return circumference;
}

/*Calculates the diameter of a circle*/
double Circle::getDiameter() {
	double diameter;
	diameter = 2 * radius;
	return diameter;
}



