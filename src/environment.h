//
// Created by thosa on 8/4/2017.
//

#ifndef QUOIDS_ENVIRONMENT_H
#define QUOIDS_ENVIRONMENT_H

#include <iostream>
#include <vector>
#include "tile.h"

class Environment {
private:
    int width_, height_;
    std::vector<std::vector<Tile *> *> tiles_;

    // Weather
    bool raining_ = false;
    int rain_chance_, rain_max_length_, rain_length_, rain_start_;

    // Plant reproduction probability
    int plant_default_durability_;
    int plant_default_reproduction_likelihood_;
public:
    Environment(int, int);

    int get_width();

    int get_height();

    std::vector<std::vector<Tile *> *> *get_tiles();

    bool get_raining();

    int get_plant_default_reproduction_likelihood();

    int get_plant_default_durability();

    void decide(int turn_number);
};


#endif //QUOIDS_ENVIRONMENT_H
