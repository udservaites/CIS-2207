#pragma once
#include<iostream>
#include<string>
using namespace std;

class ParkedCar;
ostream &operator<< (ostream &strm, ParkedCar &car);

class ParkedCar
{
private:
	string make;
	string model;
	string color;
	string licenseNumber;
	int minutesCarParked;

public:
	ParkedCar();
	ParkedCar(string make, string model, string color, string licenseNumber, int minutesParked);

	~ParkedCar();
	//getters
	string getMake() { return make; }
	string getModel() { return model; }
	string getColor() { return color; }
	string getLicenseNumber() { return licenseNumber; }
	int getMinutesCarParked() { return minutesCarParked; }
	//setters
	void setMake(string newMake) { make = newMake; }
	void setModel(string newModel) { model = newModel; }
	void setColor(string newColor) { color = newColor; }
	void setLicenseNumber(string newLicenseNumber) { licenseNumber = newLicenseNumber; }
	void setMinutesCarParked(int newMinutes) { minutesCarParked = newMinutes; }

	//other methods

	friend ostream &operator<< (ostream &strm, ParkedCar &car);

};

