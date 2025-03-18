#include "Vinyl.h"
#include <iostream>

using namespace std;

Vinyl::Vinyl(string n, int i, bool a, int p, string au, string g, int du) : Item("Vinyl",n, i, a, p), author(au), genre(g), duration(du) {}

string Vinyl::serialize() const {
	return "Vinyl|" + name + "|" + to_string(id) + "|" +
		to_string(isAvailable ? 1 : 0) + "|" + to_string(price) + "|" +
		author + "|" + genre + "|" + to_string(duration);
}

void Vinyl::printData(ostream& os) const {
	os << "Type: " << type << "\n"
		<< "Name: " << name << "\n"
		<< "Id: " << id << "\n"
		<< "Available: " << isAvailable << "\n"
		<< "Price: " << price << "\n"
		<< "Author: " << author << "\n"
		<< "Genre: " << genre << "\n"
		<< "Duration: " << duration << endl;
}


