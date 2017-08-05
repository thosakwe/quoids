//
// Created by thosa on 8/4/2017.
//

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <iomanip>
#include "game.h"
#include "plant.h"

void Game::start(int width, int height) {
    environment_ = new Environment(width, height);
    std::cout << "Starting new " << width << "x" << height << " game" << std::endl;

    for (int i = 0; i < height; i++) {
        environment_->get_tiles()->push_back(new std::vector<Tile *>());
    }


    // Generate random tiles...
    srand((unsigned int) time(NULL));

    // At most, a 40% chance of spawning something.
    int chanceOfSpawn = rand() % 4 + 1;
    //std::cout << "Chance: " << (chanceOfSpawn * 10) << "%" << std::endl;

    for (int y = 0; y < height; y++) {
        std::vector<Tile *> *row = environment_->get_tiles()->at((unsigned int) y);

        for (int x = 0; x < width; x++) {
            Tile *tile = new Tile();
            row->push_back(tile);

            int spawn = rand() % 10 + 1;

            if (spawn <= chanceOfSpawn) {
                // These numbers will need to be tweaked eventually.
                int type = rand() % 10;

                switch (type) {
                    case 0:
                    case 1:
                        tile->thing = new Plant(rand() % environment_->get_plant_default_reproduction_likelihood() + 1,
                                                rand() % environment_->get_plant_default_durability() + 1);
                        //std::cout << "Plant at (" << x << ", " << y << ")" << std::endl;
                        break;
                    default:
                        break;
                }
            }
        }
    }

    while (!done_) {
        turn();
    }
}

void Game::turn() {
    if (paused_) return;

    turn_number_++;

    // Decide the weather, etc.
    environment_->decide(turn_number_);

    // Let everything take a turn.
    int alive = 0;
    for (int y = 0; y < environment_->get_height(); y++) {
        std::vector<Tile *> *row = environment_->get_tiles()->at((unsigned int) y);

        for (int col = 0; col < environment_->get_width(); col++) {
            Tile *tile = row->at((unsigned int) col);

            if (tile != nullptr && tile->thing != nullptr) {
                Thing *thing = tile->thing;

                if (thing->get_type() == ThingType::kLiving) {
                    alive++;
                    LivingThing *livingThing = (LivingThing *) thing;
                    livingThing->decide(turn_number_, tile, environment_);
                }
            }
        }
    }

    if (alive == 0) {
        std::cout << "Everything has died!" << std::endl;
        done_ = true;
        return;
    }

    // Bring everything closer to death...

    // Print...

    std::cout << "Turn #" << (turn_number_ + 1) << std::endl;

    for (int y = 0; y < environment_->get_height(); y++) {
        std::cout << std::setw(2) << y;
        std::cout << ": ";
        std::vector<Tile *> *row = environment_->get_tiles()->at((unsigned int) y);

        for (int col = 0; col < environment_->get_width(); col++) {
            Tile *tile = row->at((unsigned int) col);

            if (tile != nullptr && tile->thing != nullptr) {
                Thing *thing = tile->thing;

                if (thing->get_type() == ThingType::kLiving) {
                    LivingThing *livingThing = (LivingThing *) thing;

                    if (livingThing->get_living_thing_type() == LivingThingType::kPlant) {
                        std::cout << "P";
                    }
                }
            } else std::cout << "_";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    // Wait a bit before continuing.
    sleep(2);
}
