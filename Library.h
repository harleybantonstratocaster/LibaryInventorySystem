#pragma once

#include <vector>
#include "Item.h"

using namespace std;

class Library {
private:
    vector<Item*> items;

public:
    Library();

    bool loadFromFile(const string& filename);
    bool saveToFile(const string& filename);


    void addItem(Item* item);

    bool removeItem(int id);

    Item* findItem(int id);

    void printAllItems();
    
    Library& operator+=(Item* item);
};

