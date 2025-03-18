#include "UserInterface.h"
#include "Book.h"  
#include "Dvd.h"
#include "Vinyl.h"
#include <iostream>
#include <limits>
#include <string>


using namespace std;

UserInterface::UserInterface(Library& lib)
    : library(lib){}

void UserInterface::run() {
    int choice = 0;
    while (true) {
        cout << "\n===== Library Menu =====\n"
            << "1. Add Item\n"
            << "2. Remove Item\n"
            << "3. Find Item\n"
            << "4. Print All Items\n"
            << "5. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        switch (choice) {
        case 1:
            addItemMenu();
            break;
        case 2:
            removeItemMenu();
            break;
        case 3:
            findItemMenu();
            break;
        case 4:
            printAllItemsMenu();
            break;
        case 5:
            cout << "Exiting the program...\n";
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void UserInterface::addItemMenu() {
    cout << "\n-- Add Item --\n"
        << "What type of item do you want to add? (book/dvd/vinyl): ";
    string itemType;
    cin >> itemType;

    if (itemType == "book") {
        string name;
        int id;
        bool available;
        int price;
        string author;
        int pages;

        cout << "Enter book name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        getline(cin, name);

        cout << "Enter book ID (int): ";
        cin >> id;

        cout << "Is the book available? (1 for yes, 0 for no): ";
        cin >> available;

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter author: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, author);

        cout << "Enter number of pages: ";
        cin >> pages;

        Book* newBook = new Book(name, id, available, price, author, pages);
        library.addItem(newBook);
        cout << "Book added successfully.\n";
    }
    else if (itemType == "dvd") {
        string name;
        int id;
        bool available;
        int price;
        string director;
        string genre;
        int duration;

        cout << "Enter DVD name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        cout << "Enter DVD ID (int): ";
        cin >> id;

        cout << "Is the DVD available? (1 for yes, 0 for no): ";
        cin >> available;

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter director: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, director);

        cout << "Enter genre: ";
        getline(cin, genre);

        cout << "Enter duration (in minutes): ";
        cin >> duration;

        Dvd* newDvd = new Dvd(name, id, available, price, director, genre, duration);
        library.addItem(newDvd);
        cout << "DVD added successfully.\n";
    }
    else if (itemType == "vinyl") {
        string name;
        int id;
        bool available;
        int price;
        string artist;
        string genre;
        int duration;

        cout << "Enter Vinyl name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        cout << "Enter Vinyl ID (int): ";
        cin >> id;

        cout << "Is the Vinyl available? (1 for yes, 0 for no): ";
        cin >> available;

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter artist: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, artist);

        cout << "Enter genre: ";
        getline(cin, genre);

        cout << "Enter duration (in minutes): ";
        cin >> duration;

        Vinyl* newVinyl = new Vinyl(name, id, available, price, artist, genre, duration);
        library.addItem(newVinyl);
        cout << "Vinyl added successfully.\n";
    }
    else {
        cout << "Unknown item type. Returning to main menu.\n";
    }
}


void UserInterface::removeItemMenu() {
    cout << "\n-- Remove Item --\n";
    cout << "Enter the ID of the item to remove: ";
    int id;
    cin >> id;

    bool success = library.removeItem(id);
    if (success) {
        cout << "Item removed successfully.\n";
    }
    else {
        cout << "Item with ID " << id << " not found.\n";
    }
}

void UserInterface::findItemMenu() {
    cout << "\n-- Find Item --\n";
    cout << "Enter the ID of the item to find: ";
    int id;
    cin >> id;

    Item* found = library.findItem(id);
    if (found) {
        cout << "Item found:\n" << *found << "\n";
    }
    else {
        cout << "Item with ID " << id << " not found.\n";
    }
}

void UserInterface::printAllItemsMenu() {
    cout << "\n-- Print All Items --\n";
    library.printAllItems();
}
