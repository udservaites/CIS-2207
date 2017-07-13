#pragma once

#include <iostream>
using namespace std;

class FeetInches;
/*Friend operator */
ostream &operator<< (ostream &stm, FeetInches &obj);
/*must have <iostream> and namespace to use ostream.
You have to prototype the class before prototyping the operator<<*/

class FeetInches
{
private:
	int feet; /*A common way to name the attributes is to put m_ in front: m_inches, m_feet. Or
				you can put the type in front too: m_i_feet, m_i_inches*/
	int inches; //Find out what naming convention is when you get a job
	void simplify(); //Lets implement our method
public:
	FeetInches(void);
	FeetInches(int feet, int inches);
	FeetInches(FeetInches &obj);
	~FeetInches(void);
	
	//mutators -- setters
	void setFeet(int feet) {this->feet = feet;} /*It is common to implete these in the header file because they are 
							only one line of code. You need to use the braces when you do this. */
	void setInches(int inches) {this->inches = inches;}
	//accessors -- gettors

	int getFeet() {return feet;}
	int getInches() {return inches;}

	//operators
	FeetInches operator- (const FeetInches &); //Implement a - that takes arguement FeetInches)
	FeetInches operator --();
	FeetInches operator --(int); //int is a dummy operator
	FeetInches operator ++();
	FeetInches operator ++(int); //int is a dummy operator
	bool operator<(const FeetInches &); //On the right hand side
	bool operator == (const FeetInches &);
	FeetInches operator*(const FeetInches &obj);
	double operator* (double cost);

	
	
	friend ostream &operator<< (ostream &stm, FeetInches &obj);
};

