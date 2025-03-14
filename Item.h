#pragma once

#include<string>

using namespace std;

class Item {

private:
	int id,price;
	string name;
	bool isAvailable;

public:
	Item(string n, int i, bool a, int p);

	virtual void printData() const = 0;

	int getId();

};