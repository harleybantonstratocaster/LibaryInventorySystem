#include "Dvd.h"
#include <iostream>

using namespace std;

Dvd::Dvd(string n, int i, bool a,int p , string d, string g, int du) : Item(n, i, a,p), director(d), genre(g), duration(du) {}

void Dvd::printData() const {
	cout << "Name: " << name << "\n"
		<< "Id: " << id << "\n"
		<< "Available: " << isAvailable << "\n"
		<< "Director: " << director << "\n"
		<< "Genre: " << genre << "\n"
		<< "Duration: " << duration << endl;
}


