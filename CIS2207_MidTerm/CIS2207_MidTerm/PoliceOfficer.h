#pragma once
#include "ParkingTicket.h"
#include <iostream>
#include<string>
using namespace std;

//Class prototypes
class ParkedCar;
class ParkingMeter;
class ParkingTicket;
class PoliceOfficer;
ostream &operator<<(ostream &strm, PoliceOfficer &officer);

class PoliceOfficer
{
private:
	string name;
	string badgeID;



public:
	PoliceOfficer();
	PoliceOfficer(string name, string badgeID);
	~PoliceOfficer();

	//getters
	string getName() { return name; }
	string getbadgeID() { return badgeID; }
	

	//setters
	void setName(string newName) { name = newName; }
	void setBadgeID(string newBadge) { badgeID = newBadge; };
	

	//other methods
	bool examineCar(ParkedCar &car, ParkingMeter &meter);

	ParkingTicket *issueTicket(PoliceOfficer &officer, ParkedCar &car, ParkingMeter &meter);

	friend ostream &operator<<(ostream &strm, PoliceOfficer &officer);
};

