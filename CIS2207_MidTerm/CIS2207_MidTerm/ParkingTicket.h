#pragma once
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"
#include <iostream>
#include <string>
using namespace std;
//Prototype classes
/*class ParkedCar;
class ParkingMeter;
class PoliceOfficer;*/
class ParkingTicket;
ostream &operator<< (ostream &stm, ParkingTicket &obj);

class ParkingTicket
{
private:
	ParkedCar illegalParkedCar;
	PoliceOfficer reportingOfficer;
	ParkingMeter timePurchased;
	double fineAmount;

public:
	const int HOUR = 60;
	const double FIRST_HOUR_FINE = 25.00;
	const double ADDITIONAL_HOUR_FINE = 10.00;
	ParkingTicket();
	ParkingTicket(ParkedCar &parkedCar, PoliceOfficer &policeOfficer, ParkingMeter &time);
	ParkingTicket(ParkedCar &car, PoliceOfficer &officer, ParkingMeter &time, double fine);
	~ParkingTicket();

	//getters
	ParkedCar getIllegalParkedCar() { return illegalParkedCar; }
	PoliceOfficer getReportingOfficer() { return reportingOfficer; }
	ParkingMeter getTimePurchased() { return timePurchased; }
	double getFineAmount() { return fineAmount; }

	//setters
	void setIllegalParkedCar(ParkedCar &car);
	void setReportingOfficer(PoliceOfficer &officer);
	void setTimePurchased(ParkingMeter &meterTime);
	void setFineAmount(double newFine) { fineAmount = newFine; }

	//other methods
	void setFineAmount(ParkingMeter &meter, ParkedCar &car);

	void printTicket();
	//friend ostream &operator<< (ostream &stm, ParkingTicket ticket);
};

