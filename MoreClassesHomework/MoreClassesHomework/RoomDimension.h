#pragma once
#include "FeetInches.h"
class RoomDimension
{

private:
	FeetInches length;
	FeetInches width;

public:
	RoomDimension();
	RoomDimension(FeetInches &lengthObject, FeetInches &widthObject);
	~RoomDimension();

	//setters
	void setLength(FeetInches &lengthObject);
	void setWidth(FeetInches &widthObject);

	//getters
	FeetInches getWidth();
	FeetInches getLength();

	FeetInches calculateArea();
};

