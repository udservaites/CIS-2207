/*K Rebecca Servaites
CIS 2207.N01
08/31/2014
Arrays and Sorting Homework Chapters 7-8
Programming Challenge #8 page 493*/

/*Sorting Benchmarks
Write a program that uses two identical arrays of at least 20 integers.It should call
a function that uses the bubble sort algorithm to sort one of the arrays in ascending
order.The function should keep a count of the number of exchanges it makes.The
program then should call a function that uses the selection sort algorithm to sort the
other array.It should also keep count of the number of exchanges it makes.Display
these values on the screen.*/
/*Search Benchmarks:

Write a program that uses two identical arrays of at least 20 integers.  It should call a function that uses the bubble sort 
algorithm to sort one of the arrays in ascending order.  The function should keep a count of the number of exchanges it makes.  
The program then should call a function that uses the selection sort algorithm to sort the other array.  It should also keep 
count of the number of exchanges it makes.  Display these values on the screen.

Errata: When the author says "should" you need to read it as "will".*/

#include <iostream>
#include <math.h>


using namespace std;

const int ARRAY_SIZE = 20;

void bubbleSort(int *bubble_list, int array_size);
void selectionSort(int *selection_list, int array_size);
void arrayPrint(int *list, int size);
void swap(int &low, int &high);

int main() {

	int bubble_sort_array[ARRAY_SIZE]; //Array used for bubble sort
	int selection_sort_array[ARRAY_SIZE]; //Array used for selection sort

	for (int i = 0; i < ARRAY_SIZE; i++) { //Generate random numbers and fill arrays
		bubble_sort_array[i] = rand() % 75;
		selection_sort_array[i] = rand() % 75;
	}

	bubbleSort(bubble_sort_array, ARRAY_SIZE);
	selectionSort(selection_sort_array, ARRAY_SIZE);


	system("pause");
	return(0);
}

void arrayPrint(int *list, int size) { //Prints arrays to screen
	for (int i = 0; i < size; i++) { //Loop through array and print each value
		cout << list[i] << endl;
	}
}

void swap(int &loser, int&winner) { //Swaps two numbers
	int temp;
	temp = loser; //Move loser into temp to keep it safe
	loser = winner; //Winner takes the loser's slot
	winner = temp; //winner's vacated slot empty. Put loser there
}

void bubbleSort(int *bubble_list, int array_size) {
	int exchange_index = 0; //Index to track number of exchanges made during sort
	int temp; //Holds a variable to make the exchange

	cout << "Before Bubble Sort: " << endl;
	arrayPrint(bubble_list, array_size);

	for (int entire_index = 0; entire_index < array_size; entire_index++) { //Loop to sort entire array
		for (int i = 0; i < array_size - 1; i++) { /*Loop to sort one number (one pass through array)
																					  Largest number goes in the last slot*/
			if (bubble_list[i] > bubble_list[i + 1]) { //Compare two numbers
				swap(bubble_list[i], bubble_list[i + 1]); //Swap if conditions are met
				exchange_index++; //Increase counter by one
			}
		}
	}
	
	cout << "After Bubble Sort: " << endl;
	arrayPrint(bubble_list, array_size);

	cout << "Total number of exchanges: " << exchange_index << endl;
	
	}




void selectionSort(int *selection_list, int array_size) {
	int exchange_index = 0;
	
	cout << "Before Selection Sort: " << endl;
	arrayPrint(selection_list, array_size);

	/*The number occuping the placement index is for the final sort. Each comparison places the new lowest 
	number into the permanent postition until next loop is completed and the next slot is set to be filled*/
	for (int placement = 0; placement < array_size; placement++) { /*Puts the lowest number into array[placement]*/
		/*This loop compares the number in the permanenet position to the other number inthe array. When a lower one
		is found, the lower number in placed into the permanent slot.*/
		for (int sort = placement + 1; sort < array_size; sort++) { 
			if (selection_list[placement] > selection_list[sort]) { //selection_list[placement] is now the higher number and needs to go
				swap(selection_list[sort], selection_list[placement]); //Put the new lower number into the permanent slot. 
				exchange_index++;
			}

		}
		
	}
		cout << "After Selection Sort: " << endl;
		arrayPrint(selection_list, array_size);

		cout << "Total number of exchanges: " << exchange_index << endl;
}
