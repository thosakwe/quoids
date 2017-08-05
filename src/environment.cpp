//
// Created by thosa on 8/4/2017.
//

#include <cstdlib>
#include "environment.h"
#include "seed.h"

Environment::Environment(int width, int height) {
    width_ = width;
    height_ = height;

    // Weather
    rain_chance_ = rand() % 10 + 1;
    rain_max_length_ = rand() % 20 + 1;

    // By default, plants have at most a 50% chance of reproduction.
    plant_default_reproduction_likelihood_ = rand() % 50 + 10;
    plant_default_durability_ = rand() % 6 + 3;
    plant_default_range_ = rand() % 3 + 1;
    plant_default_life_span_ = rand() % 10 + 1;
}

int Environment::get_width() {
    return width_;
}

int Environment::get_height() {
    return height_;
}

std::vector<std::vector<Tile *> *> *Environment::get_tiles() {
    return &tiles_;
}

bool Environment::get_raining() {
    return raining_;
}

void Environment::Decide(int turn_number) {
    if (raining_) {
        // End the rain, if we have been
        if ((turn_number - rain_start_) >= rain_length_) {
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

int Environment::get_plant_default_range() {
    return plant_default_range_;
}

int Environment::get_plant_default_life_span() {
    return plant_default_life_span_;
}

Tile ***Environment::Grid(const Position &position, int range) {
    Tile ***rows = new Tile **[range];
    int offset_y = 0;

    for (int y = position.y - range; y < position.y + range; y++) {
        if (y < 0 || y >= tiles_.size()) {
            // If we're out of range, return a nullptr
            rows[offset_y++] = nullptr;
        } else {
            Tile **row = rows[offset_y++] = new Tile *[range];
            std::vector<Tile *> *vector = tiles_.at((unsigned int) y);

            int offset_x = 0;
            for (int x = position.x - range; x < position.x + range; x++) {
                if (x < 0 || x >= vector->size() || (x == position.x && y == position.y))
                    row[offset_x++] = nullptr;
                else
                    row[offset_x++] = tiles_.at((unsigned int) y)->at((unsigned int) x);
            }
        }
    }

    return rows;
}

void Environment::KillSeed(void *s) {
    Seed* seed = (Seed *) s;

    // If no other seeds share the parent/second parent, then delete the parent as well.
    std::vector<Seed*> parentSeeds;
    findSeeds(seed->get_parent(), seed, (std::vector<void *> *) &parentSeeds);

    if (parentSeeds.empty())
        delete(seed->get_parent());

    if (seed->get_second_parent() != nullptr) {
        std::vector<Seed *> secondParentSeeds;
        findSeeds(seed->get_second_parent(), seed, (std::vector<void *> *) &secondParentSeeds);

        if (secondParentSeeds.empty())
            delete(seed->get_second_parent());
    }

    delete(seed);
}

void Environment::KillPlant(void *p) {
    Plant* plant = (Plant *) p;

    // If there are no seeds, then delete this plant.
    std::vector<Seed*> seeds;
    findSeeds(plant, nullptr, (std::vector<void *> *) &seeds);

    if (seeds.empty())
        delete(plant);
}

void Environment::findSeeds(void* plant, void* ref, std::vector<void*>* seeds) {

    if (plant != nullptr) {
        for (unsigned int row = 0; row < tiles_.size(); row++) {
            std::vector<Tile*>* vector = tiles_.at(row);

            for (unsigned int col = 0; col < vector->size(); col++) {
                Tile* tile = vector->at(col);

                if (tile != nullptr && tile->thing != nullptr && tile->thing->get_type() == ThingType::kLiving) {
                    LivingThing* livingThing = (LivingThing *) tile->thing;
                    if (livingThing->get_living_thing_type() == LivingThingType::kSeed && livingThing != ref) {
                        seeds->push_back((Seed*) livingThing);
                    }
                }
            }
        }
    }
}
