/*Kathryn Rebecca Servaies
CIS 2207.N01
Files Homework Chapter 12 page 706 #5
09-17-2014
*/
/*5.  Line Numbers
(This assignment could be done as a modification of the program in Programming
Challenge 2.) Write a program that asks the user for the name of a file. The program
should display the contents of the file on the screen. Each line of screen output should
be preceded with a line number, followed by a colon. The line numbering should start
at 1. Here is an example:
1:George Rolland
2:127 Academy Street
3:Brasstown, NC 28706
If the file’s contents won’t fit on a single screen, the program should display 24 lines of
output at a time, and then pause. Each time the program pauses, it should wait for the
user to strike a key before the next 24 lines are displayed. */

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

const int LINE_LIMIT = 24;


int main() {
	string fileName, inFileLine;
	fstream inFile;
	int lineCounter = 1, screenLimitCounter = 0;

	cout << "Please enter the name of the file: " << endl;
	getline(cin, fileName); //Get name of file, assign to fileName

	//For testing
	/*outFile.open(fileName, ios::out);
	outFile << "Here is some text." << endl;
	outFile << "Here's line 2." << endl;
	cout << "Text written" << endl;
	outFile.close();*/



	inFile.open(fileName, ios::in);

	if (inFile) { //Check if file exists
		cout << "Loading file...." << endl;

		//system("CLS");

		getline(inFile, inFileLine); //Initial condition for while loop
		while (!inFile.eof()) { //Check that you haven't hit end of file
			cout << lineCounter << ": " << inFileLine << endl; //Print current line to screen
			screenLimitCounter++;
			lineCounter++;

			
			getline(inFile, inFileLine);//Re-initilaize conditional for while loop
			
			if (screenLimitCounter >= LINE_LIMIT) { /*Limits the amount of lines displayed on screen.
													After user hits carriage return, another 24 will display*/
				system("pause");
				screenLimitCounter = 0;
			}
		}
	}
	else { //Error message if it doesn't exist
		cerr << "Error. File not found." << endl;
	}


	inFile.close(); //Close the opened file


	system("pause");
	return(0);
}