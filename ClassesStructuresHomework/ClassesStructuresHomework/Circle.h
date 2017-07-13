#pragma once

class Circle{

private:
	double radius;
	const double pi = 3.14159;

public:
	

	Circle();
	Circle(double radiusArg); //Arg is for arguement. Needed a different and similar name to prevent confusion

	void setRadius(double radiusArg);
	double getRadius();

	double getArea();
	double getDiameter();
	double getCircumference();

};