#include "RoomCarpet.h"
#include "RoomDimension.h"
#include "FeetInches.h"


RoomCarpet::RoomCarpet()
{
	carpetCost = 0;
}
/*Sets roomcarpet values equal to the ones in the passed roomdimension object 
Price of carpet is passed through with cost*/
RoomCarpet::RoomCarpet(RoomDimension &roomDimensionObject, double cost) {
	measurements.setLength(roomDimensionObject.getLength());
	measurements.setWidth(roomDimensionObject.getWidth());
	carpetCost = cost;
}


RoomCarpet::~RoomCarpet()
{
}

//Setters
//Sets roomcarpet values equal to the ones in the passed roomdimension object
void RoomCarpet::setRoomDimension(RoomDimension &roomDimensionObject) {
	measurements.setLength(roomDimensionObject.getLength());
	measurements.setWidth(roomDimensionObject.getWidth());
}

void RoomCarpet::setCarpetCost(double cost) {
	carpetCost = cost;
}

//Getters
double RoomCarpet::getCarpetCost() {
	return carpetCost;
}

RoomDimension RoomCarpet::getMeasurements() {
	return measurements;
}

//Calculate the total cost of the carpet
double RoomCarpet::calculateTotalCost() {
	double feetTotal;
	double inchesTotal;
	double totalCost;
	FeetInches area;

	area = measurements.calculateArea();
	/*Inches was rounded up to feet in calculateArea so we only 
	need to call the feet value*/
	feetTotal = area.getFeet() * carpetCost;
	
	return totalCost;

}