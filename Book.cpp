#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(string n, int i, bool a,int p, string au, int pa) : Item(n, i, a,pa), author(au), pages(pa) {}

void Book::printData() const {
	cout << "Name: " << name << "\n"
		<< "Id: " << id << "\n"
		<< "Available: " << isAvailable << "\n"
		<< "Author: " << author << "\n"
		<< "Pages: " << pages << endl;
}


