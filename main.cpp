#include "Userinterface.h"
#include <string>
#include <iostream>


using namespace std;

int main() {
    Library library;

    try {
        library.loadFromFile("library.txt");
    }
    catch (const runtime_error& e) {
        cerr << "Error loading library: " << e.what() << endl;
    }

    UserInterface ui(library);
    ui.run();

    try {
        library.saveToFile("library.txt");
    }
    catch (const runtime_error& e) {
        cerr << "Error saving library data: " << e.what() << endl;
    }

    return 0;
}