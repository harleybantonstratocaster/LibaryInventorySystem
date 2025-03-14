#pragma once

#include "Item.h"

class Vinyl : public Item {
private:
    string author;
    string genre;
    int duration;


public:
    Vinyl(string n, int i, bool a,int p, string a, string g, int du);


    void printData() const override;
};
