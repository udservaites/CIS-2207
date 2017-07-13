/*Kathryn Rebecca Servaites
CIS 2207.N01
11/23/2014
Recursion Homework Chapter 19 Problem #7
*/

/*Write a function that accepts an integer argument and returns the sum of all the integers from 
1 to the number passed as an argument.  For example, if 50 is passed as an argument, the function 
will return the sum of 1, 2, 3, ... 50.  use recursion to calculate the sum.  Demonstrate the 
function in a program.*/

#include <iostream>

using namespace std;

int sumOfNumber(int number);

int main() {
	int number, numberSum;
	bool negFlag = false;

	cout << "Please enter an ineger: " << endl;
	cin >> number;
	/*If negative number is entered, change into positive number for function,
	change back into negative after function by checking flag*/
	if (number < 0) {
		negFlag = true;
		number *= -1;
	}
	numberSum = sumOfNumber(number);

	if (negFlag == true) {
		numberSum *= -1;
	}

	cout << numberSum << endl;
	





	system("pause");
	return(0);
}

//Recursive function to find sum of all integers of 50
int sumOfNumber(int number) {
		
	if (number < 0) {
		return 0;
	}	
	else {
		//cout << number << endl; //for testing
		return (number + sumOfNumber(number - 1));
		
		
	}
}