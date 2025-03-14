#include "Vinyl.h"
#include <iostream>

using namespace std;

Vinyl::Vinyl(string n, int i, bool a, int p, string d, string g, int du) : Item(n, i, a, p), author(d), genre(g), duration(du) {}

void Vinyl::printData() const {
	cout << "Name: " << name << "\n"
		<< "Id: " << id << "\n"
		<< "Available: " << isAvailable << "\n"
		<< "Author: " << author << "\n"
		<< "Genre: " << genre << "\n"
		<< "Duration: " << duration << endl;
}


