#pragma once

#include "Item.h"

class Dvd : public Item {
private:
    string director;
    string genre;
    int duration;
    

public:
    Dvd(string n, int i, bool a,int p, string d, string g, int du);


    void printData() const override;
};
