#include "Address.h"


Address::Address()
{
	street = "";
	city = "";
	state = "";
	zip = "";
}


Address::~Address()
{
}

ostream &operator<<(ostream &strm, Address &obj) {

	strm << "\n" << obj.street << "\n" << obj.city << ", " << obj.state <<
		" " << obj.zip;

	return strm;
}

