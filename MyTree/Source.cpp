




/* This is to show an example of calculating the height and width of a tree */

/* 
Sample tree: 
	tree->insert(1021);
	tree->insert(1057);
	tree->insert(2487);
	tree->insert(3769);
	tree->insert(1017);
	tree->insert(1275);
	tree->insert(1899);
	tree->insert(4218);
	tree->insert(1019);
	tree->insert(1018);

								1021						level 1 - width 1
								/	\
							1017	1057					level 2 - width 2
								\		\					
								1019	2487				level 3 - width 2
								/		/	\						
							1018	1275	3769			level 4 - width 3
										\		\
										1899	4218		level 5 - width 2

	Thus the height = 5
			 width = max(1,2,2,3,2) = 3

*/

#include "MyTree.h"
#include <iostream>
using namespace std;

int main()
{
	MyTree *tree = new MyTree;

	tree->insert(1021);
	tree->insert(1057);
	tree->insert(2487);
	tree->insert(3769);
	tree->insert(1017);
	tree->insert(1275);
	tree->insert(1899);
	tree->insert(4218);
	tree->insert(1019);
	tree->insert(1018);

	cout << "Height: " << tree->getHeight() << endl;
	cout << "Width:  " << tree->getWidth() << endl;

	delete tree;


	system("pause");
}