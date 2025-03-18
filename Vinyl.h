#pragma once

#include "Item.h"

class Vinyl : public Item {
private:
    string author;
    string genre;
    int duration;


public:
    Vinyl(string n, int i, bool a,int p, string au, string g, int du);

    virtual string serialize() const override;
    void printData(ostream& os) const override;
};
