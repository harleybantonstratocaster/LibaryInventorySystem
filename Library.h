#pragma once

#include <vector>
#include <memory>
#include "Item.h"

using namespace std;

class Library {
private:
    vector<Item*> items;

public:
    Library();


    void addItem(Item* item);

    bool removeItem(int id);

    Item* findItem(int id);

    void printAllItems();
};

