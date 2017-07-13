#pragma once
#include <iostream>
using namespace std;

class ParkingMeter;
ostream &operator<< (ostream &strm, ParkingMeter &meter);

class ParkingMeter
{
private:
	int meterMinutes;
public:
	ParkingMeter();
	ParkingMeter(int minutes);
	~ParkingMeter();

	//getters
	int getMeterMinutes() { return meterMinutes; }

	//setters
	void setMeterMinutes(int newMinutes){ meterMinutes = newMinutes; }

	//other methods
	friend ostream &operator<<(ostream &strm, ParkingMeter &meter);
};

