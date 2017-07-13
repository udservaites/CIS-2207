#include "FeetInches.h"


FeetInches::FeetInches(void)
{
	feet = 0;
	inches = 0;
	//You can write it like this:
	//feet = inches = 0;
}

FeetInches::FeetInches(int f, int i) {
	//Constructors retun nothing!!!
	feet = f;
	inches = i;
	simplify();

}

FeetInches::FeetInches(FeetInches &obj) {

	inches = obj.inches;
	feet = obj.feet;
	simplify();

}

FeetInches::~FeetInches(void)
{//Destructors return nothing!!!
}



void FeetInches::simplify() { //Converts inches into feet if over 12 inches

	if(inches >= 12) {

		feet += inches / 12;
		inches = inches % 12;
	} else if (inches < 0) {

		feet -= ((abs(inches) / 12) + 1);
		inches = 12 - (abs(inches) % 12);
	}
	
}

FeetInches FeetInches::operator- (const FeetInches &obj) {
	FeetInches temp; //No arguement constructer, feet = 0, inches = 0

	temp.inches = inches - obj.inches;
	temp.feet = feet - obj.feet;
	temp.simplify();

	return temp;
}

FeetInches FeetInches :: operator --() {

	--inches;
	simplify(); //In case we go negative on our inches
	return *this;
}

FeetInches FeetInches :: operator--(int) {

	//We are going to return the existing size of our FeetInches
	FeetInches temp(feet, inches); //Make another object same as the current object
	inches --; //Modify inches
	simplify();


	return temp;//Returning what the original was. 
}

FeetInches FeetInches :: operator++() {
	++inches;
	simplify();

	return *this;
	//Error here
}

FeetInches FeetInches :: operator++(int) {
	FeetInches temp(feet, inches); //Make another object same as the current object
	inches ++; //Modify inches
	simplify();


	return temp;//Returning what the original was. 

}

bool FeetInches::operator<(const FeetInches &obj) {

	bool status;
	if (feet < obj.feet) {
		status = true;
	}else if (feet > obj.feet) {
		status = false;
	}else if (inches < obj.inches) {
		status = true;
	}else {
		status = false;
	}

	return status;
}

bool FeetInches::operator==(const FeetInches &obj) {

	bool status;
	if (feet == obj.feet && inches == obj.inches) {
		status = true;
	}else {
		status = false;
	}

	return status;
}

FeetInches FeetInches::operator*(const FeetInches &obj) {

	FeetInches temp;

	int totalInches1 = (feet * 12) + inches; //From base object
	int totalInches2 = (obj.feet * 12) + obj.inches; //From object being passed in

	temp.inches = totalInches1 * totalInches2;
	temp.simplify();


	return temp;

}

double FeetInches::operator*(double cost) {

	double totalCost;

	totalCost = cost * (feet + (inches/12.0));

	return totalCost;

}

ostream &operator<< (ostream &strm, FeetInches &obj) {
	/*Red squiggles becuase the attributes are private. To get around this,
	make them public or make it a friend*/
	strm << "Feet: " << obj.feet << " Inches: " << obj.inches;

	return strm;
}
