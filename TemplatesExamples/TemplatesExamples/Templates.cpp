#include "TestScores.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*Start with this:
int times10(int num); 
to get this: */
template <class T> T times10(T);


int main()
{
	int item = 5;
	double foo = 10.4;
	string bar = "help me";

	cout << times10(item) << endl;
	cout <<times10(foo) << endl;
	cout << times10(bar) << endl;

	TestScores<string> *test = new TestScores<string>("pass");
	cout << test->getScore() << endl;
	
	//Vectors!!
	/*A vector is an array that can allocate more space. You can 
	treat a vector just like an array.*/

	string *names = new string[10];
	names[0] = "dave";
	names[1] = "dave";
	names[2] = "dave";
	names[3] = "dave";
	names[4] = "dave";
	names[5] = "dave";

	/*Instead of an array of strings, you could have used a vector*/

	vector<string> *names2;
	names2[0] = "dave";
	names2[1] = "dave";
	names2[2] = "dave";
	names2[3] = "dave";
	names2[4] = "dave";
	names2[5] = "dave";
	names2[6] = "dave";
	names2[0] = "dave";
	names2.push_back("fred");

	cout << names2[4] << endl;
	//.at dereferences the array
	cout <, names2.at(4) << endl;
	//Vectors pass along the size of the array.
	//Behind the scenes it is created an iterator to keep count
	for(string name : names) {
		cout << name << endl;

	}
	//Vectors are a wrapper around an array







	system("pause");
	return(0);
}

/*Start off writing the function with a primative data type. it makes it much 
easier to debug. Then go through and change it to a template. */
/*int times10(int num) {
	return num*10;
}*/

template <class T> T times10(T num) {
	return num * 10;
/*If you try to pass a string through here, you will get a compile error.
With templates you must be careful to use an appropriate data type relevent
to the function. Example, you can't multiply a string. */
}
 
/*double times10(double num) {
	return num*10;
}*/
