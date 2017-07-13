/*Kathryn Rebecca Servaites
CIS 2207.N01
10/22/2014
Chapter 16 Homework
Chapter 16 Programming Challenge #13 page 1023
(Chapter 7 Programming Challenge #2 Page 448)
*/
/* Rainfall vector
Modify Programming Challenge 2 in Chapter  7  (Rainfall Statistics) to use an
STL vector instead of an array. Refer to the information in Tables 16-5 and 16-6 if you wish
to use any of the member functions. */

/* Rainfall Statistics
Write a program that lets the user enter the total rainfall for each of 12 months into
an array of double s. The program should calculate and display the total rainfall for
the year, the average monthly rainfall, and the months with the highest and lowest
amounts.
Input Validation: Do not accept negative numbers for monthly rainfall figures.*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MONTHS = 12;

//Prototypes
void validateRainfall(vector<double> rainfall, int i);
double calculateTotalRainfall(vector<double> rainfall);
double calculateAverageMonthlyRainfall(double totalRainfall);
int maxMonthlyRainfall(vector<double> rainfall);
int minMonthlyRainfall(vector<double> rainfall);

int main() {
	vector <double> rainfall(MONTHS);
	string months[] = { "January", "February", "March", "April", "May", "June", "July", "August",
		"September", "October", "November", "December" };
	int minRainfallIndex, maxRainfallIndex;
	double totalRainfall, averageRainfall;
	bool validated = false;


	for (int i = 0; i < MONTHS; i++) {
		validated = false; //reset condition for exception handling
		//Get data from user
		cout << "Please enter the amount of rainfall for the month of " << months[i] << ": ";
		cin >> rainfall[i]; 
		//User will be asked to reenter data until a non-negative number is entered
		while (!validated) {
			try {
				validateRainfall(rainfall, i);
				validated = true;
			}
			catch (string msg) {
				cout << msg << endl;
				cin >> rainfall[i];
				
			}
		}
	}
	//Calculates all statistics for printout
		totalRainfall = calculateTotalRainfall(rainfall);
		averageRainfall = calculateAverageMonthlyRainfall(totalRainfall);
		minRainfallIndex = minMonthlyRainfall(rainfall);
		maxRainfallIndex = maxMonthlyRainfall(rainfall);
		
		//Statistics print out
		cout << "The total rainfall for the year was: " << totalRainfall << " inches." << endl;
		cout << "The average rainfall per month was: " << averageRainfall << " inches." << endl;
		cout << "The month with the least amount of rain was " << months[minRainfallIndex] <<
			" with " << rainfall[minRainfallIndex] << " inches." << endl;
		cout << "The month with the largest amount rain was " << months[maxRainfallIndex] << " with " <<
			rainfall[maxRainfallIndex] << " inches." << endl;



		system("pause");
		return(0);
	}

//For validating user entered data. No negative numbers. 
	void validateRainfall(vector<double> rainfall, int i) {

		if (rainfall[i] < 0) {
			throw string("Invalid entry. Please enter a positive number: ");
		}
	}

//Calculates the total rainfall for the year
double calculateTotalRainfall(vector<double> rainfall) {
	double totalRainfall = 0;

	for (int i = 0; i < MONTHS; i++) {
		totalRainfall += rainfall[i];
	}

	return totalRainfall;
}
//Calculates the average rainfall per month
double calculateAverageMonthlyRainfall(double totalRainfall) {
	double averageRainfall = 0;

	averageRainfall = totalRainfall / MONTHS;

	return averageRainfall;
}
//Finds the maximum amount of rainfall and its month
int maxMonthlyRainfall(vector<double> rainfall) {
	//return index to match up with array and vector in main
	double maxRainfall = 0;
	int maxRainfallIndex = 0;
	/*Checks each mnth rainfall to see if it is larger than the current maxRainfall.
	If compared month is larger, it becomes the new maxRainfall*/
	for (int i = 0; i < MONTHS; i++) {
		if (maxRainfall < rainfall[i]) {
			maxRainfall = rainfall[i];
			maxRainfallIndex = i;
		}
	}
	return maxRainfallIndex;
}
//Finds the month with minumum amount of rainfall
int minMonthlyRainfall(vector<double> rainfall) {
	double minRainfall = rainfall[0]; //Current minimum becuase it is the first month
	int minRainfallIndex = 0;
	/*Checks each month's rainfall against the month with the current minimum. If
	one month has less rainfall than the previous, the smaller moth will become
		the new minRainfall*/
	for (int i = 0; i < MONTHS; i++) {
		if (minRainfall > rainfall[i]) {
			minRainfall = rainfall[i];
			minRainfallIndex = i;
		}
	}
	return minRainfallIndex;
}