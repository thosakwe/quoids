//
// Created by thosa on 8/4/2017.
//

#ifndef QUOIDS_FRUIT_H
#define QUOIDS_FRUIT_H


#include "thing.h"
#include "plant.h"

class Fruit: public Thing {
private:
    Plant* parent_;
    int seed_count_;
public:
    Fruit(Plant*, int);
    Plant* get_parent();
    int get_seed_count();
};


#endif //QUOIDS_FRUIT_H
