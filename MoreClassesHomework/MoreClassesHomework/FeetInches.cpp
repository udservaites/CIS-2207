#include "FeetInches.h"



FeetInches::FeetInches(void)
{
	feet = inches = 0;
}

FeetInches::FeetInches(int f, int i)
{
	feet = f;
	inches = i;
	simplify();
}

FeetInches::FeetInches(FeetInches &obj)
{
	inches = obj.inches;
	feet = obj.feet;
	simplify();
}

FeetInches::~FeetInches(void)
{
}


void FeetInches::simplify()
{
	if (inches >= 12)
	{
		feet += inches / 12;
		inches = inches % 12;
	}
	else if (inches < 0)
	{
		feet -= ((abs(inches) / 12) + 1);
		inches = 12 - (abs(inches) % 12);
	}
}
//Collaborated with Shanika Merritt for this function
void FeetInches :: simplifyArea(int inchesInput) {
	//1 ft squared = 144 in squared
	this->feet = inchesInput / 144;

	//Rounds feet up by one if there are any inches remaining
	if (inchesInput % 144 > 0) {
		this->feet++;
	}

}

FeetInches FeetInches::operator - (const FeetInches &obj)
{
	FeetInches temp;

	temp.inches = inches - obj.inches;
	temp.feet = feet - obj.feet;
	temp.simplify();

	return temp;
}

FeetInches FeetInches::operator--()
{
	--inches;
	simplify();
	return *this;
}

FeetInches FeetInches::operator--(int)
{
	FeetInches temp(feet, inches);

	inches--;
	simplify();

	return temp;
}

FeetInches FeetInches::operator + (const FeetInches &obj)
{
	FeetInches temp;

	temp.inches = inches + obj.inches;
	temp.feet = feet + obj.feet;
	temp.simplify();

	return temp;
}

FeetInches FeetInches::operator++()
{
	++inches;
	simplify();
	return *this;
}

FeetInches FeetInches::operator++(int)
{
	FeetInches temp(feet, inches);

	inches++;
	simplify();

	return temp;
}

bool FeetInches::operator<(const FeetInches &obj)
{
	bool status;

	if (feet < obj.feet)
		status = true;
	else if (feet > obj.feet)
		status = false;
	else if (inches < obj.inches)
		status = true;
	else
		status = false;

	return status;
}

bool FeetInches::operator==(const FeetInches &obj)
{
	bool status;

	if (feet == obj.feet && inches == obj.inches)
		status = true;
	else
		status = false;

	return status;
}

/*I collaborated with Shanika Merritt to rewrite this function and
to find an accurate value for area by using the simplifyArea() that
we also collaborated on*/
FeetInches FeetInches::operator*(const FeetInches &obj)
{
	FeetInches totalFeetSquared;
	totalFeetSquared.feet = 0;
	totalFeetSquared.inches = 0;

	int totalInches1 = feet * 12 + inches;
	int totalInches2 = obj.feet * 12 + obj.inches;
	int totalInches12 = totalInches1 * totalInches2;

	totalFeetSquared.simplifyArea(totalInches12);
	/*temp.inches = totalInches1 * totalInches2;*/
	//temp.simplify();

	

	return totalFeetSquared;
}


double FeetInches::operator*(double cost)
{
	double totalCost;

	totalCost = cost * (feet + inches / 12.0);

	return totalCost;
}

ostream &operator<< (ostream &strm, FeetInches &obj)
{
	strm << "Feet: " << obj.feet << " Inches: " << obj.inches;

	return strm;
}
