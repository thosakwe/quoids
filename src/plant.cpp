//
// Created by thosa on 8/4/2017.
//

#include "plant.h"

Plant::Plant(int reproduction_likelihood, int durability) {
    reproduction_likelihood_ = reproduction_likelihood;
    durability_ = durability;
}

int Plant::get_reproduction_likelihood() {
    return reproduction_likelihood_;
}

int Plant::get_durability() {
    return durability_;
}

void Plant::decide(int turn_number, Tile *tile, Environment *environment) {
    if (!environment->get_raining()) {
        if (thirst_start == -1) {
            thirst_start = turn_number;
        } else if (thirst_start != -1 && (turn_number - thirst_start) >= durability_) {
            // TODO: Environment kill plant
            tile->thing = nullptr;
            //std::cout << "No water!!! Dead after " << durability_ << " turn(s)!!!" << std::endl;
        }

        /*
        std::cout << "Don't let me die of thirst! " << (durability_ - (turn_number - thirst_start))
                  << " turn(s) until I die." << std::endl;
       */
    } else {
        thirst_start = -1;
    }
}

LivingThingType Plant::get_living_thing_type() {
    return LivingThingType::kPlant;
}
