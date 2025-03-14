#pragma once

#include "Item.h"

class Book : public Item {
private:
    string author;
    int pages;

public:
    Book(string n, int i, bool a,int p, string au, int pa);
        

    void printData() const override;

};
