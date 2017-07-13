#pragma once

#include <string>
using namespace std;

class RetailItem
{
private: 
	string sku;
	string description;
	int unitsOnHand;
	double price;

public:
	RetailItem(void);
	RetailItem(string newSku, string newDescription, int newUnitsOnHand, double newPrice);
	~RetailItem(void);

	string getSku() {return sku;}
	string getDescription() {return description;}
	int getUnitsOnHand() {return unitsOnHand;}
	double getPrice() {return price;}


	bool operator>(RetailItem &obj) {return sku > obj.sku;}
	bool operator<(RetailItem &obj) {return sku < obj.sku;}
	bool operator==(RetailItem &obj) {return sku==obj.sku;}

	void print();
};

