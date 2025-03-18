#include "Dvd.h"
#include <iostream>

using namespace std;

Dvd::Dvd(string n, int i, bool a,int p , string d, string g, int du) : Item("DVD",n, i, a,p), director(d), genre(g), duration(du) {}

string Dvd::serialize() const{
	return "Dvd|" + name + "|" + to_string(id) + "|" +
		to_string(isAvailable ? 1 : 0) + "|" + to_string(price) + "|" +
		director + "|" + genre + "|" + to_string(duration);
}

void Dvd::printData(ostream& os) const {
	os << "Type: " << type << "\n"
		<< "Name: " << name << "\n"
		<< "Id: " << id << "\n"
		<< "Available: " << isAvailable << "\n"
		<< "Director: " << director << "\n"
		<< "Genre: " << genre << "\n"
		<< "Duration: " << duration << endl;
}


