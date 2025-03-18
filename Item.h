#pragma once

#include<string>

using namespace std;

class Item {

protected:
	int id,price;
	string type,name;
	bool isAvailable;

public:
	Item(string t,string n, int i, bool a, int p);

	virtual void printData(ostream& os) const = 0;
	virtual string serialize() const = 0;

	int getId();

	friend ostream& operator<<(ostream& os, Item& item);
	friend bool operator==(Item& i1, Item& i2);

};