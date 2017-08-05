//
// Created by thosa on 8/4/2017.
//

#include <cstdlib>
#include "environment.h"

Environment::Environment(int width, int height) {
    width_ = width;
    height_ = height;

    // Weather
    rain_chance_ = rand() % 10 + 1;
    rain_max_length_ = rand() % 20 + 1;

    // By default, plants have at most a 40% chance of reproduction.
    plant_default_reproduction_likelihood_ = rand() % 40 + 1;
    plant_default_durability_ = rand() % 6 + 3;
}

int Environment::get_width() {
    return width_;
}

int Environment::get_height() {
    return height_;
}

std::vector<std::vector<Tile*>*>* Environment::get_tiles() {
    return &tiles_;
}

bool Environment::get_raining() {
    return raining_;
}

void Environment::decide(int turn_number) {
    if (raining_) {
        // End the rain, if we have been
        if ((turn_number - rain_start_) <= rain_start_) {
            raining_ = false;
            std::cout << "It has stopped raining after " << rain_length_ << " turn(s)." << std::endl;
        }
    } else {
        // Decide if we want to rain...
        if ((rand() % 10 + 1) <= rain_chance_) {
            rain_length_ = rand() % rain_max_length_ + 1;
            rain_start_ = turn_number;
            raining_ = true;
            std::cout << "It has begun to rain." << std::endl;
        }
    }
}

int Environment::get_plant_default_reproduction_likelihood() {
    return plant_default_reproduction_likelihood_;
}

int Environment::get_plant_default_durability() {
    return plant_default_durability_;
}
