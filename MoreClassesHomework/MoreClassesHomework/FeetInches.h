#pragma once

#include <iostream>
using namespace std;

class FeetInches;

ostream &operator<< (ostream &strm, FeetInches &obj);


class FeetInches
{
private:
	int feet;
	int inches;
	void simplify();

public:
	FeetInches(void);
	FeetInches(int feet, int inches);
	FeetInches(FeetInches &obj);
	~FeetInches(void);

	// mutators -- setters
	void setFeet(int feet) { this->feet = feet; }
	void setInches(int inches) { this->inches = inches; simplify(); }
	// accessors -- getters
	int getFeet() { return feet; }
	int getInches() { return inches; }

	// operators
	FeetInches operator - (const FeetInches &);
	FeetInches operator--();
	FeetInches operator--(int);
	FeetInches operator + (const FeetInches &);
	FeetInches operator ++ ();
	FeetInches operator++(int);
	bool operator<(const FeetInches &);
	bool operator==(const FeetInches &);
	FeetInches operator*(const FeetInches &obj);
	double operator*(double cost);
	void simplifyArea(int inchesSquared);

	friend ostream &operator<< (ostream &strm, FeetInches &obj);

};
