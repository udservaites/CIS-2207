

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

const int MAX_SIZE = 10; //Explict size. Written different from C

void selectionSort(int *list, int size);
void swap(int &first, int &second);
void showArray(int *list, int size);
bool binarySearch(int *list, int size, int value); //Binary search. Returns whether it was found or not. 

int main() {
	int array[MAX_SIZE] = {1,2,3,4,5};
//There is  problem with this array becuase of C++ creaters
	//If you change these numbers, all your other code will be worng, becuase your size will be differeent
	//And you will throw out of bounds errors. 
	//You can prevent that by putting in a [MAX_SIZE]

	//int *const array1 = {1,2,3,4,5}; //This is the same as above. This says the pointer cannot change
	//First one is easier to understand. 

	//An array is a pointer where you cannot change the location. int *array --> location can be changed
	
	/*int array2[MAX_SIZE];
	//You can do this to initilize:
	array[0] = 5;
	array[1] = 6;*/

	//Or this
	for (int index = 0; index < MAX_SIZE; index++) {
		
		array[index] = rand() % 20; /*When using random number generator, the same numbers will be generated every time
									because c always uses the same numbers. To get a more randome selection, use the current time)*/
	}

	cout <<"Before Sort: " <<endl;
	showArray(array, MAX_SIZE);

	cout <<"After Sort: " <<endl;
	selectionSort(array, MAX_SIZE);
	showArray(array, MAX_SIZE);

	cout << "Is 4 in the list? " << binarySearch(array, MAX_SIZE, 4) << endl;
	system("pause");
	return(0);
}

void swap(int &first, int &second) { //Passing a reference
	int hold = first;
	first = second;
	second = hold;
	//Make this more efficient by making hold static
}

void selectionSort (int *list, int size) {
	for (int outer = 0; outer < size - 1; outer++) {
		for (int inner = outer + 1; inner < size; inner++) {
			if(list[outer] > list[inner]) { //Swap the numbers if outer is greater than inner. Need a method called swap.
				swap(list[outer], list[inner]); //You are passing by value here. We want to pass by reference by using &
			}
		}
}
}

	void showArray(int *list, int size) {

		for (int index = 0; index < size; index++) {
			cout << list[index] << endl;
		}
	}

	bool binarySearch(int *list, int size, int value) { //0 is false, 1 is true
		bool found = false;
		int first = 0; //First item in sub-array. Sub array is the narrowed array as the binary search narrows the paramenter. 
		int last = size - 1;
		int middle = (first + last)/2;
		//A more efficient way is to do a bit shift. int middle = (first + last) >> 1, but it gets confusing, so don't do it. 

		while ((first < last) && (!found)) {
			if (list[middle] == value) {
				found = true;
			} else if (list[middle] > value) {/*If true, we want to look at first half of array. Reassign last as 
											 the last number in the first half*/
				last = middle -1;

			}else {
				first = middle + 1; //This is if we need to look at the second half. 
			}

			middle = (first + last)/2;
		}
		return found;
	}
