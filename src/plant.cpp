//
// Created by thosa on 8/4/2017.
//

#include "plant.h"
#include "seed.h"

Plant::Plant(int birth, int life_span, int reproduction_likelihood, int durability, int range, Plant *parent) {
    birth_ = birth;
    life_span_ = life_span;
    reproduction_likelihood_ = reproduction_likelihood;
    durability_ = durability;
    range_ = range;
    parent_ = parent;
}

Plant::Plant(int birth, int life_span, int reproduction_likelihood, int durability, int range) {
    birth_ = birth;
    life_span_ = life_span;
    reproduction_likelihood_ = reproduction_likelihood;
    durability_ = durability;
    range_ = range;
    parent_ = nullptr;
}

int Plant::get_reproduction_likelihood() {
    return reproduction_likelihood_;
}

int Plant::get_durability() {
    return durability_;
}

Plant *Plant::get_parent() {
    return parent_;
}


void Plant::decide(int turn_number, Tile *tile, Environment *environment) {
    bool alive = true;

    if ((turn_number - birth_) >= life_span_) {
        alive = false;
        tile->thing = nullptr;
        environment->KillPlant(this);
    } else if (!environment->get_raining()) {
        if (thirst_start == -1) {
            thirst_start = turn_number;
        } else if (thirst_start != -1 && (turn_number - thirst_start) >= durability_) {
            // TODO: Environment kill plant
            alive = false;
            tile->thing = nullptr;
            environment->KillPlant(this);
            //std::cout << "No water!!! Dead after " << durability_ << " turn(s)!!!" << std::endl;
        }

        /*
        std::cout << "Don't let me die of thirst! " << (durability_ - (turn_number - thirst_start))
                  << " turn(s) until I die." << std::endl;
       */
    } else {
        thirst_start = -1;
    }

    if (!alive) return;

    // Regardless of whether it is raining, a plant may reproduce.
    if ((rand() % 100 + 1) <= reproduction_likelihood_) {
        // TODO: Search for plants within range
        // TODO: Make range genetic
        //std::cout << "Reproduction desire at (" << tile->position.x << ", " << tile->position.y << ")" << std::endl;
        //std::cout << "Likelihood: " << reproduction_likelihood_ << std::endl;

        std::vector<Tile *> openSpaces;
        std::vector<Plant *> otherPlants;
        Tile ***grid = environment->Grid(tile->position, range_);

        for (int row = 0; row < range_; row++) {
            Tile **arr = grid[row];

            if (arr != nullptr) {
                for (int col = 0; col < range_; col++) {
                    Tile *t = arr[col];

                    if (t != nullptr) {
                        if (t->thing == nullptr) {
                            openSpaces.push_back(t);
                        } else if (t->thing->get_type() == ThingType::kLiving) {
                            LivingThing *livingThing = (LivingThing *) t->thing;
                            if (livingThing->get_living_thing_type() == LivingThingType::kPlant) {
                                Plant *other = (Plant *) livingThing;
                                if (other != parent_)
                                    otherPlants.push_back(other);
                            }

                        }
                    }
                }
            }
        }

        if (!openSpaces.empty()) {
            // TODO: Incubation length
            Tile *t = openSpaces.at(rand() % openSpaces.size());

            // Try to reproduce with another plant
            if (!otherPlants.empty()) {
                Plant *mate = otherPlants.at(rand() % otherPlants.size());
                t->thing = new Seed(this, mate, turn_number, 3);
            } else {
                // Otherwise, parthenogenesis.
                t->thing = new Seed(this, turn_number, 3);
            }
        }
    }
}

LivingThingType Plant::get_living_thing_type() {
    return LivingThingType::kPlant;
}

int Plant::get_range() {
    return range_;
}

int Plant::get_life_span() {
    return life_span_;
}
