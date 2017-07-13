#include "ParkingTicket.h"

#include <iomanip>



//Constructors
ParkingTicket::ParkingTicket()
{
}

ParkingTicket::ParkingTicket(ParkedCar &car, PoliceOfficer &officer, ParkingMeter &time) {
	setIllegalParkedCar(car);
	setReportingOfficer(officer);
	setTimePurchased(time);
}

ParkingTicket::ParkingTicket(ParkedCar &car, PoliceOfficer &officer, ParkingMeter &time, double fine) {
	setIllegalParkedCar(car);
	setReportingOfficer(officer);
	setTimePurchased(time);
	fineAmount = fine;
}


ParkingTicket::~ParkingTicket()
{
}

//setters

void ParkingTicket::setIllegalParkedCar(ParkedCar &car) {
	illegalParkedCar.setMake(car.getMake());
	illegalParkedCar.setModel(car.getModel());
	illegalParkedCar.setColor(car.getColor());
	illegalParkedCar.setLicenseNumber(car.getLicenseNumber());
	illegalParkedCar.setMinutesCarParked(car.getMinutesCarParked());
}

void ParkingTicket::setReportingOfficer(PoliceOfficer &officer) {
	reportingOfficer.setName(officer.getName());
	reportingOfficer.setBadgeID(officer.getbadgeID());

}

void ParkingTicket::setTimePurchased(ParkingMeter &meterTime) {
	timePurchased.setMeterMinutes(meterTime.getMeterMinutes());
}

//Calculates the fine amount for the ticket
void ParkingTicket::setFineAmount(ParkingMeter &meter, ParkedCar &car) {

	double tempFine;
	int meterMinutes = meter.getMeterMinutes();
	int parkedMinutes = car.getMinutesCarParked();

	if (meterMinutes < parkedMinutes) {
		tempFine = FIRST_HOUR_FINE;
		parkedMinutes -= HOUR;
		while (parkedMinutes > 0) {
			tempFine += ADDITIONAL_HOUR_FINE;
			parkedMinutes -= HOUR;
		}
		fineAmount = tempFine;
	}


}
//Prints the parking ticket
void ParkingTicket::printTicket() {
	cout << "\n\t*****PARKING TICKET******" << endl;
	cout << "\n\tREPORTING OFFICER "
		<< reportingOfficer <<
		"\n\n\tVEHICLE INFORMATION "
		<< illegalParkedCar <<
		"\n\n\tMETER INFORMATION "
		<< timePurchased <<
		"\n\n\tFINE " << endl;
		cout << setprecision(2) << fixed;
		cout << "Pay this amount: $ " << fineAmount << 
			"\n\n\t************************" <<endl;
 
}
