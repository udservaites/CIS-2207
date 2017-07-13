//#include "PoliceOfficer.h"
#include "ParkingTicket.h"


//Constructors
PoliceOfficer::PoliceOfficer()
{
	name = "";
	badgeID = "";
}

PoliceOfficer::PoliceOfficer(string name, string badgeID) {
	setName(name);
	setBadgeID(badgeID);
}

PoliceOfficer::~PoliceOfficer()
{
}

//Checks if the car has been parked at an expired meter. Returns true if a ticket needs to be issued.
bool PoliceOfficer::examineCar(ParkedCar &car, ParkingMeter &meter) {
	bool issueTicket = false;
	if (meter.getMeterMinutes() < car.getMinutesCarParked()) {
		issueTicket = true;
	}
	return issueTicket;
}

//Creates a parking ticket
ParkingTicket* PoliceOfficer::issueTicket(PoliceOfficer &officer, ParkedCar &car, ParkingMeter &meter) {
	ParkingTicket *ticket = new ParkingTicket(car, officer, meter);
	(*ticket).setFineAmount(meter, car);

	return ticket;
}

//Prints a PoliceOfficer object in cout
ostream &operator<< (ostream &strm, PoliceOfficer &officer) {
	strm << "\nReporting Officer's name: " << officer.name <<
		"\nReporting Officer's badge ID: " << officer.badgeID;

	return strm;

}
