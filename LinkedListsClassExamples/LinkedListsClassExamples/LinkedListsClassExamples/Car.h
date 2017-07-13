#pragma once
#include <string>
class Car
{

private:
	string make;
	string model;
	string licensePlate;
public:
	Car(void);
	Car(string, string, string);
	~Car(void);

	string getMake() {return make;}
	string getModel();
	string getLicensePlate();
};

