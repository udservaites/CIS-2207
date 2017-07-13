#include "ParkedCar.h"



//Constructors
ParkedCar::ParkedCar()
{
	/*make = "";
	model = "";
	color = "";
	licenseNumber = "";
	minutesCarParked = 0;*/
}

ParkedCar::ParkedCar(string make, string model, string color, string licenseNumber, int miutesParked) {
	this->make = make;
	this->model = model;
	this->color = color;
	this->licenseNumber = licenseNumber;
	this->minutesCarParked = miutesParked;
}
ParkedCar::~ParkedCar()
{
}

//Prints a ParkedCar object in cout
ostream &operator<< (ostream &strm, ParkedCar &car) {
	strm << "\nMake: " << car.make << "\nModel: " << car.model <<
		"\nColor: " << car.color << "\nLicense Number: " << car.licenseNumber <<
		"\nMinutes Parked: " << car.minutesCarParked;

	return strm;
}