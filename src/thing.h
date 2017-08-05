//
// Created by thosa on 8/4/2017.
//

#ifndef QUOIDS_THING_H
#define QUOIDS_THING_H

struct Volume {
    int x, y;
};

enum ThingType:int {
    kNonLiving = 0,
    kLiving = 1
};

class Thing {
public:
    double mass_;
    double hardness_;
    Volume* volume = new Volume;

    virtual ThingType get_type()= 0;
};

#endif //QUOIDS_THING_H
