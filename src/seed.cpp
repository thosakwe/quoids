//
// Created by thosa on 8/4/2017.
//

#include "seed.h"

Seed::Seed(Plant *parent, int birth, int incubation_length) {
    parent_ = parent;
    birth_ = birth;
    incubation_length_ = incubation_length;
}

Seed::Seed(Plant *parent, Plant *second_parent, int birth, int incubation_length) {
    parent_ = parent;
    second_parent_ = second_parent;
    birth_ = birth;
    incubation_length_ = incubation_length;
}

Plant *Seed::get_parent() {
    return parent_;
}

Plant *Seed::get_second_parent() {
    return second_parent_;
}

Plant *Seed::grow() {
    if (second_parent_ == nullptr) {
        // Parthenogenesis. Produce an exact copy of the parent.
        return new Plant(parent_->get_reproduction_likelihood(), parent_->get_durability());
    } else {
        // Likelihood of reproduction is "genetic," and thus random.
        // It will either be the first/second parent's likelihood, something
        // in between, or the second parent's likelihood plus 1.
        //
        // Eventually, plants can evolve that are more likely to reproduce.
        int type = rand() % 4;
        int likelihood, durability;

        switch (type) {
            case 0:
                likelihood = parent_->get_reproduction_likelihood();
                break;
            case 1:
                likelihood = second_parent_->get_reproduction_likelihood();
                break;
            case 2:
                likelihood =
                        rand() % parent_->get_reproduction_likelihood() + second_parent_->get_reproduction_likelihood();
                break;
            default:
                likelihood = second_parent_->get_reproduction_likelihood() + 1;
        }


        // Same concept for durability, A.K.A. the amount of time a plant can live without water.
        type = rand() % 4;

        switch (type) {
            case 0:
                durability = parent_->get_durability();
                break;
            case 1:
                durability = second_parent_->get_durability();
                break;
            case 2:
                durability =
                        rand() % parent_->get_durability() + second_parent_->get_durability();
                break;
            default:
                durability = second_parent_->get_durability() + 1;
        }

        return new Plant(likelihood, durability);
    }
}

void Seed::decide(int turn_number, Tile *tile, Environment *) {
    // TODO: Die after a certain number of turns without water

    if ((turn_number - birth_) >= incubation_length_) {
        tile->thing = grow();
        std::cout << "Grew into a plant after " << incubation_length_ << " turn(s)!" << std::endl;
    }
}

LivingThingType Seed::get_living_thing_type() {
    return LivingThingType::kSeed;
}
