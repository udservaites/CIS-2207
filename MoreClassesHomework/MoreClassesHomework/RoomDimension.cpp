#include "RoomDimension.h"
#include "FeetInches.h"


//constructors, destructor
RoomDimension::RoomDimension()
{
	this->length.setInches(0);

}

//Sets roomdimension attributes equal to feetinches attributes
RoomDimension::RoomDimension(FeetInches &lengthObject, FeetInches &widthObject) {
	
	this->setLength(lengthObject);
	this->setWidth(widthObject);
}


RoomDimension::~RoomDimension()
{
}

//setters

void RoomDimension::setLength(FeetInches &lengthObject) {
	length.setFeet(lengthObject.getFeet());
	length.setInches(lengthObject.getInches());
}

void RoomDimension::setWidth(FeetInches &widthObject) {
	width.setFeet(widthObject.getFeet());
	width.setInches(widthObject.getInches());
}

//getters

FeetInches RoomDimension::getLength() {
	return length;
}

FeetInches RoomDimension::getWidth() {
	return width;
}

//Calculates the area by multipling two FeetInches objects
FeetInches RoomDimension::calculateArea() {
	FeetInches calculatedObject;
	calculatedObject = length * width;
	return calculatedObject;
}

