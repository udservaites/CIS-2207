/*Kathryn Rebecca Servaites
CIS 2207.N01
MidTerm Assignment
*/

/*You will design a set of classes that work together to simulate a police officer issuing a parking ticket.
The classes you are to design are:
·         ParkedCar – This class will simulate a parked car.  The class’s responsibilities are:
o   To know the car’s make, model, color, license number and the number of minutes the car has been parked

·         ParkingMeter – This class will simulate a parking meter.  The class’s only responsibility is:
o   To know the number of minutes of parking time that has been purchased

·         ParkingTicket – This class will simulate a parking ticket.  The class’s responsibilities are:
o   To report the make, model, color and license number of the illegally parked car
o   To report the amount of the fine, which is $25 for the first hour or part of an hour that the car is illegally parked,
plus $10 for every additional hour or part of an hour the car is illegally parked.
o   To report the name and badge number of the police officer issuing the ticket

·         PoliceOfficer – This class simulates a police officer inspecting parked cars.
The class’s responsibilities are:
o   To know the police officer’s name and badge number
o   To examine a ParkedCar object and a ParkingMeter object, and determine whether
the car’s time has expired
o   To issue a parking ticket (generate a ParkingTicket object) if the car’s time has expired

Write a program that demonstrates these classes.

*/
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"

#include <iostream>
#include<string>
#include<ctype.h>

using namespace std;

//Prototypes
void generateOfficer(PoliceOfficer &officer);
ParkedCar *generateCar();
ParkingMeter *generateParkingMeter();

int main() {
	char getChar;
	bool go = true, issueTicket;
	//Create Officer		
	PoliceOfficer *officer = new PoliceOfficer(); 
	generateOfficer(*officer);


	//Menu
	while (go) {
		cout << "\n\nWelcome Officer " << (*officer).getName() << "\n"
			"PLease select an option from the menu. \n"
			"\tE: Examine a car\n"
			"\tQ: Quit\n"
			<< endl;
		cin >> getChar;
		getChar = toupper(getChar);


		switch (getChar) {
		case 'E':
		{/*Examine a car. Use methods to get information from user about car*/
					cout << "\nPlease enter information about the car: " << endl;
					ParkedCar *car = generateCar();
					cout << "\nPlease enter information about the parking meter: " << endl;
					ParkingMeter *meter = generateParkingMeter();
					
					/*Check if the car is at an expired meter*/
					issueTicket = (*officer).examineCar(*car, *meter);
					/*If meter is expired, then a ticket will be issued and printed to screen*/
					if (issueTicket) {
						ParkingTicket *ticket = (*officer).issueTicket(*officer, *car, *meter);
						(*ticket).printTicket();
					}
					else {
						cout << "\nThe car is legally parked." << endl;
					}
					//Reallocate memory
					delete car;
					delete meter;
		}
			break;
		case 'Q':
			/*Quit. Print goodbye message and set go
			conditional to false to stop menu loop*/
			cout << "\nGoodbye" << endl;
			go = false;
			break;
		default:
			/*If user enters an unvalid choice*/
			cout << "\nThat is not a valid option. Please try again." << endl;
			break;
		}
	}
	delete officer;

	system("pause");
	return(0);
}
//Gets info from user for officer object 
void generateOfficer(PoliceOfficer &officer) {
	string tempName, tempBadgeID;
	cout << "Welcome to the Automated Ticket System. \n\n"
		"To begin you will have to enter your information." << endl;
	cout << "\nEnter the police officer's name: " << endl;
	cin >> tempName;
	officer.setName(tempName);
	cout << "Enter the badge ID of the police officer: " << endl;
	cin >> tempBadgeID;
	officer.setBadgeID(tempBadgeID);
}

ParkedCar *generateCar() {
	string make, model, color, licenseNumber;
	int minutesParked;
	cout << "Enter the make of the car: ";
	cin >> make;
	cout << "Enter the model of the car: ";
	cin >> model;
	cout << "Enter the color of the car: ";
	cin >> color;
	cout << "Enter the license plate number: ";
	cin >> licenseNumber;
	cout << "Enter the number of minutes the car has been parked: ";
	cin >> minutesParked;
	//Error check the minutes parked. No negative numbers. 
	while (minutesParked < 0) {
		cout << "That is not a valid entry. Please enter a positve number: ";
		cin >> minutesParked;
	}

	ParkedCar *car = new ParkedCar(make, model, color, licenseNumber, minutesParked);
	return car;
}

ParkingMeter *generateParkingMeter() {
	int minutes;

	cout << "Please enter the number of minutes purchased on the meter: ";
	cin >> minutes;
	//Error check mintutes. No negative numbers
	while (minutes < 0) {
		cout << "That is not a valid entry. PLease enter a positve number: ";
		cin >> minutes;
	}

	ParkingMeter *meter = new ParkingMeter(minutes);

	return meter;
}