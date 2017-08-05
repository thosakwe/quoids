//
// Created by thosa on 8/4/2017.
//

#ifndef QUOIDS_PLANT_H
#define QUOIDS_PLANT_H

#include "living_thing.h"

class Plant : public LivingThing {
    int birth_, durability_, life_span_, reproduction_likelihood_, range_;
    int thirst_start = -1;
    Plant* parent_;
public:
    int water_level_ = 10;
    Plant(int, int, int, int, int);
    Plant(int, int, int, int, int, Plant*);
    int get_reproduction_likelihood();
    int get_durability();
    int get_range();
    int get_life_span();
    Plant* get_parent();

    void decide(int turn_number, Tile *tile, Environment *environment) override;

    LivingThingType get_living_thing_type() override;
};


#endif //QUOIDS_PLANT_H
