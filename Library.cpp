#include "Library.h"
#include "Book.h"
#include "Dvd.h"
#include "Vinyl.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

Library::Library() {}

bool Library::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file for reading: " << filename << "\n";
        throw runtime_error("Could not open file for reading: " + filename);
        return false;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, '|')) {
            tokens.push_back(token);
        }

        if (tokens[0] == "Book" && tokens.size() == 7) {
            string name = tokens[1];
            int id = stoi(tokens[2]);
            bool available = (stoi(tokens[3]) != 0);
            int price = stoi(tokens[4]);
            string author = tokens[5];
            int pages = stoi(tokens[6]);
            Book* b = new Book(name, id, available, price, author, pages);
            addItem(b);
        }
        else if (tokens[0] == "Dvd" && tokens.size() == 8) {
            string name = tokens[1];
            int id = stoi(tokens[2]);
            bool available = (stoi(tokens[3]) != 0);
            int price = stoi(tokens[4]);
            string director = tokens[5];
            string genre = tokens[6];
            int duration = stoi(tokens[7]);
            Dvd* d = new Dvd(name, id, available, price, director, genre, duration);
            addItem(d);
        }
        else if (tokens[0] == "Vinyl" && tokens.size() == 8) {
            string name = tokens[1];
            int id = stoi(tokens[2]);
            bool available = (stoi(tokens[3]) != 0);
            int price = stoi(tokens[4]);
            string artist = tokens[5];
            string genre = tokens[6];
            int duration = stoi(tokens[7]);
            Vinyl* v = new Vinyl(name, id, available, price, artist, genre, duration);
            addItem(v);
        }
        else {
            cerr << "Unrecognized format or incorrect token count in line: " << line << "\n";
        }
    }
    file.close();
    return true;
}
bool Library::saveToFile(const string& filename){
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file for writing: " << filename << "\n";
        throw runtime_error("Could not open file for writing: " + filename);
        return false;
    }
    for (Item* item : items) {  
        file << item->serialize() << "\n";
    }
    file.close();
    return true;
}


void Library::addItem(Item* item) {
    items.push_back(move(item));
}

bool Library::removeItem(int id) {
    auto it = remove_if(items.begin(), items.end(),
        [id](Item* item) {
            return item->getId() == id;
        });

    if (it != items.end()) {
        items.erase(it, items.end());
        return true;
    }
    return false;
}


Item* Library::findItem(int id) {
    auto it = find_if(items.begin(), items.end(),
        [id](Item* item) {
            return item->getId() == id;
        });
    return (it != items.end()) ? *it : nullptr;
}

void Library::printAllItems() {
    vector<Item*> sortedItems = items;

    sort(sortedItems.begin(), sortedItems.end(),
        [](Item* a, Item* b) {
            return a->getId() < b->getId();
        });

    for (Item* item : sortedItems) {
        item->printData(cout); 
        cout << "\n------------------------\n";
    }
}

Library& Library::operator+=(Item* item)
{
    addItem(item);
    return *this;
}

