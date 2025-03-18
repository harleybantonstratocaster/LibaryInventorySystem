#pragma once

#include "Library.h"

class UserInterface {
private:
    Library& library;

    void addItemMenu();
    void removeItemMenu();
    void findItemMenu();
    void printAllItemsMenu();

public:
    explicit UserInterface(Library& lib);

    void run();
};
