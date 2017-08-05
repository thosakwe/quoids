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
    int plant_default_life_span_;
    int plant_default_range_;
    int plant_default_reproduction_likelihood_;

    void findSeeds(void *, void *, std::vector<void *> *);

public:
    Environment(int, int);

    int get_width();

    int get_height();

    std::vector<std::vector<Tile *> *> *get_tiles();

    bool get_raining();

    int get_plant_default_reproduction_likelihood();

    int get_plant_default_durability();

    int get_plant_default_life_span();

    int get_plant_default_range();

    void Decide(int turn_number);

    Tile ***Grid(const Position &, int);

    void KillPlant(void *);

    void KillSeed(void *);
};


#endif //QUOIDS_ENVIRONMENT_H
