//
// Created by thosa on 8/4/2017.
//

#ifndef QUOIDS_LIVING_THING_H
#define QUOIDS_LIVING_THING_H


#include "thing.h"
#include "environment.h"

enum LivingThingType {
    kPlant = 0,
    kSeed = 1,
};

class LivingThing : public Thing {
public:
    int health_ = 100;

    ThingType get_type() override;

    virtual void decide(int turn_number, Tile* tile, Environment *environment)= 0;
    virtual LivingThingType get_living_thing_type()= 0;
};


#endif //QUOIDS_LIVING_THING_H
