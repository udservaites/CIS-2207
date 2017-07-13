/*Kathryn Rebecca Servaites
CIS 2207.N01
Pointers Homework
09/14/2014
Chapter 9 Page 546 #11

Array Expander
Write a function that accepts an int array and the array’s size as arguments. The function should create a new array that is twice the size 
of the argument array. The function should copy the contents of the argument array to the new array and initialize the
unused elements of the second array with 0. The function should return a pointer to
the new array. */

#include <iostream>

using namespace std;

int* expandArray(int* array_p, int size);

int main() {
	int arraySize;
	int* pointerReturn;

	/*Asks user for the size of the array*/
	cout << "Please enter the size of the array: ";
	cin >> arraySize;

	/*Creates a pointer to use for array and to pass through
	function*/
	int* initialArray_p = new int[arraySize];

	/*Asks user to enter ints to fill array*/
	cout << "Please enter " << arraySize << " intergers, seperated by a space: ";
	for (int i = 0; i < arraySize; i++) {
		cin >> initialArray_p[i];
	}
	
	/*Set pointer in main equal to the one returned by the function. 
	This will direct us to the expanded array created in expandArray*/
	 pointerReturn = expandArray(initialArray_p, arraySize);

	 /*Print the expanded array*/
	 cout << "The expanded array is: " << endl;
	 for (int i = 0; i < (arraySize * 2); i++) {
		 cout << pointerReturn[i] << endl;
	 }

	delete [] pointerReturn;
	system("pause");
	return(0);
}

/*Function to expand the array to twice its size, copy
elements into it, and fill remaining slots with zeros.*/
int* expandArray(int* array_p, int size) {

	int newSize;
	newSize = size * 2; //New size of array
	int* expandedArray_p = new int[newSize]; //New array pointer, twice size of original array

	for (int i = 0; i < size; i++) { //Copy from original array to new array
		expandedArray_p[i] = array_p[i];
	}
	for (int i = size; i < newSize; i++) { //Fill remaing array slots with 0
		expandedArray_p[i] = 0;
	}

	return expandedArray_p; //Return pointer to main
}