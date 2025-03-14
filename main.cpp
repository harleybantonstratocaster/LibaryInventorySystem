#include "Book.h"

int main() {
	Book myBook("asd", 1, true, "qq", 123);
	myBook.setId(2);
	myBook.printData();
	return 0;
}