#include "ParkingMeter.h"



//Constructors
ParkingMeter::ParkingMeter()
{
	meterMinutes = 0;
}

ParkingMeter::ParkingMeter(int minutes) {
	meterMinutes = minutes;
}

ParkingMeter::~ParkingMeter()
{
}

//Prints a ParkingMeter object in cout
ostream &operator<<(ostream &strm, ParkingMeter &meter) {
	strm << "\nMinutes Purchased: " << meter.meterMinutes;

	return strm;
}