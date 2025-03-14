#include "Library.h"
#include <algorithm>
#include <iostream>

using namespace std;

Library::Library() {}


void Library::addItem(Item* item) {
    items.push_back(move(item));
}

bool Library::removeItem(int id) {
    auto it = remove_if(items.begin(), items.end(),
        [id](const std::unique_ptr<Item>& item) {
            return item->getId() == id;
        });

    if (it != items.end()) {
        items.erase(it, items.end());
        return true;
    }
    return false;
}


Item* Library::findItem(int id){
    for (auto& item : items) {
        if (item->getId() == id) {
            return item.get();
        }
    }
    return nullptr;
}

// Prints the details of all items in the library.
void Library::printAllItems() const {
    for (const auto& item : items) {
        item->printDetails();  // Call the virtual function on each Item.
        std::cout << "------------------------" << std::endl;
    }
}
