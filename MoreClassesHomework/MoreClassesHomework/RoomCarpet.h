#pragma once
#include "RoomDimension.h"
#include "FeetInches.h"



class RoomCarpet
{

private:
	RoomDimension measurements;
	double carpetCost;
public:
	RoomCarpet();
	RoomCarpet(RoomDimension &roomDimensionObject, double cost);
	~RoomCarpet();

	void setRoomDimension(RoomDimension &roomDimensionObject);
	void setCarpetCost(double cost);
	double getCarpetCost();
	RoomDimension getMeasurements();
	double RoomCarpet::calculateTotalCost();
};

