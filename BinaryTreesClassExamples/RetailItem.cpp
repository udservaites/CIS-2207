#include "RetailItem.h"
#include<iostream>
#include <string>
#include<iomanip>
using namespace std;


RetailItem::RetailItem(void)
{
	sku = "";
	description = "";
	unitsOnHand = 0;
	price = 0.0;
}
RetailItem::RetailItem(string newSku, string newDescription, int newUnitsOnHand, double newPrice) {
	sku = newSku;
	description = newDescription;
	unitsOnHand = newUnitsOnHand;
	price = newPrice;
	
}
RetailItem::~RetailItem(void)
{
}

void RetailItem::print() {
	cout << "Item: " << sku << endl;
	cout << "\tDescription: " << description << endl;
	cout << "\tOn Hand: " << unitsOnHand << endl;
	cout << "\tPrice: " << price << endl;

}
