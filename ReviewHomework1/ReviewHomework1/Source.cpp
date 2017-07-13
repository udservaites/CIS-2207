/*Kathryn Rebecca Servaites
08/24/2014
CIS 2207 N07
Chapter 1-6
Programming Challenge #4 page 367*/

/* Safest Driving Area 
Write a program that determines which of five geographic regions within a major city 
(north, south, east, west, and central) had the fewest reported automobile accidents last 
year. It should have the following two functions, which are called by main . 
•  int getNumAccidents() is passed the name of a region. It asks the user for the 
number of automobile accidents reported in that region during the last year, validates 
the input, then returns it. It should be called once for each city region. 
•  void findLowest() is passed the five accident totals. It determines which is the 
smallest and prints the name of the region, along with its accident figure. 
Input Validation: Do not accept an accident number that is less than 0.*/


#include <iostream>
#include <string>

using namespace std;



/*Prototypes*/
int getNumAccidents(string region_name);
void findLowest(int east, int south, int north, int west, int central);

int main() {
	string east_region = "East", south_region = "South", west_region = "West", north_region = "North", central_region = "Central";
	int east_accident_number, south_accident_number, west_accident_number, north_accident_number, central_accident_number;

	/*Get user input for each of the regions*/
	east_accident_number = getNumAccidents(east_region);
	south_accident_number = getNumAccidents(south_region);
	west_accident_number = getNumAccidents(west_region);
	north_accident_number = getNumAccidents(north_region);
	central_accident_number = getNumAccidents(central_region);

	/*Sort through the input to get the region with the lowest number of accidents*/
	findLowest(east_accident_number, south_accident_number, north_accident_number, west_accident_number, central_accident_number);



	system("pause");
	return(0);
}

int getNumAccidents(string region_name) {
	int accident_number;	
	//printf("\nPlease enter the number of accidents for the %s region: ", region_name);
	cout << "\nPlease enter the number of accidents for the " << region_name << " region: ";
	cin >> accident_number;
	while (accident_number < 0) { //Validate that the number entered was not negative
		cout << "The number of accidents cannot be negative. Please enter a non-negative number: ";
		cin >> accident_number;
	}
	return accident_number; 
}

void findLowest(int east, int south, int north, int west, int central) {
	
	int smallest_accident_number;
	
	string region_name;
	/*Compare each number to determine which is the lowest
	Set the lowest numbe in each comparison to smallest_accident_number and use that
	number to compar the next variable. Also set the region name to the 
	corresponding lowest number. */
	if (east < south) {
		smallest_accident_number = east;
		region_name = "East";
	}
	else {
		smallest_accident_number = south;
		region_name = "South";
	}
	if (north < smallest_accident_number) {
		smallest_accident_number = north;
		region_name = "North";
	}
	if (west < smallest_accident_number) {
		smallest_accident_number = west;
		region_name = "West";
	}
	if (central < smallest_accident_number) {
		smallest_accident_number = central;
		region_name = "Central";
	}
	
	cout << "The " << region_name << " region had only " << smallest_accident_number << " accidents, making it the region with the lowest number of accidents." << endl;

	

}