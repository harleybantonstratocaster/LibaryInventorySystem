#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(string n, int i, bool a,int p, string au, int pa) : Item("Book",n, i, a,pa), author(au), pages(pa) {}

string Book::serialize() const{
	return "Book|" + name + "|" + to_string(id) + "|" +
		to_string(isAvailable ? 1 : 0) + "|" + to_string(price) + "|" +
		author + "|" + to_string(pages);
}

void Book::printData(ostream& os) const {
	os << "Type: " << type << "\n"
		<< "Name: " << name << "\n"
		<< "Id: " << id << "\n"
		<< "Available: " << isAvailable << "\n"
		<< "Price: " << price << "\n"
		<< "Author: " << author << "\n"
		<< "Pages: " << pages << endl;
}


