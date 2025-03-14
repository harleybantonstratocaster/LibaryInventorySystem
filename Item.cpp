#include "Item.h"

using namespace std;

Item::Item(string n, int i,bool a,int p): name(n), id(i),isAvailable(a),price(p) {}

int Item::getId() {
	return id;
}