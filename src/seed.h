//
// Created by thosa on 8/4/2017.
//

#ifndef QUOIDS_SEED_H
#define QUOIDS_SEED_H


#include "living_thing.h"
#include "plant.h"

class Seed: public LivingThing {
private:
    Plant* parent_;
    Plant* second_parent_ = nullptr;
    int birth_, incubation_length_;
public:
    int water_level_ = 10;
    Seed(Plant*, int, int);
    Seed(Plant*, Plant*, int, int);
    Plant* get_parent();
    Plant* get_second_parent();
    Plant* grow();

    void decide(int turn_number, Tile *tile, Environment *environment) override;

    LivingThingType get_living_thing_type() override;
};


#endif //QUOIDS_SEED_H
