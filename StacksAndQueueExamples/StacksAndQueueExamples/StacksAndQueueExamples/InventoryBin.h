#pragma once
#include <string>
using namespace std;
class InventoryBin
{
private:
	/*In real life, treat serial numbers and lot numbers as strings,
	becuase they will probably have letters in it. The tartan ID is a 
	string because it has leading zeros.*/
	int serialNum;
	string manufactureDate;
	int lotNumber;
public:
	InventoryBin(void);
	InventoryBin(int sn, string md, int ln) {serialNum = sn; manufactureDate = md; lotNumber = ln;}
	~InventoryBin(void);

	int getSerialNum() { return serialNum; }
	string getManufactureDate() {return manufactureDate;}
	int getLotNumber() {return lotNumber;}
};

