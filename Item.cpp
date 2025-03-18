#include "Item.h"
#include <iostream>

using namespace std;

Item::Item(string t,string n, int i,bool a,int p): type(t), name(n), id(i),isAvailable(a),price(p) {}

int Item::getId() {return id;}

ostream& operator<<(ostream& os, Item& item)
{
	item.printData(os);
	return os;
}

bool operator==(Item& i1, Item& i2) {
	return i1.id == i2.id;
}
