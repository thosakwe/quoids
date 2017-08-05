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

Plant *Seed::grow(int turn_number) {
    if (second_parent_ == nullptr) {
        // Parthenogenesis. Produce an exact copy of the parent.
        // Each quality can potentially mutate, and increase.
        return new Plant(
                turn_number,
                PossibleMutationInt(parent_->get_life_span(), 1),
                PossibleMutationInt(parent_->get_reproduction_likelihood(), rand() % 10 + 1),
                PossibleMutationInt(parent_->get_durability(), 1),
                PossibleMutationInt(parent_->get_range(), 1),
                parent_);
    } else {
        // Likelihood of reproduction is "genetic," and thus random.
        // It will either be the first/second parent's likelihood, something
        // in between, or the second parent's likelihood plus 1.
        //
        // Eventually, plants can evolve that are more likely to reproduce.
        int likelihood, durability, range, life_span;

        likelihood = GeneticInt(parent_->get_reproduction_likelihood(), second_parent_->get_reproduction_likelihood());

        // Same concept for durability, A.K.A. the amount of time a plant can live without water.
        durability = GeneticInt(parent_->get_durability(), second_parent_->get_durability());

        // And range.
        range = GeneticInt(parent_->get_range(), second_parent_->get_range());

        life_span = GeneticInt(parent_->get_life_span(), second_parent_->get_life_span());

        // Each quality can potentially mutate
        return new Plant(
                turn_number,
                PossibleMutationInt(life_span, 1),
                PossibleMutationInt(likelihood, rand() % 10 + 1),
                PossibleMutationInt(durability, 1),
                PossibleMutationInt(range, 1),
                parent_
        );
    }
}

void Seed::decide(int turn_number, Tile *tile, Environment *environment) {
    if ((turn_number - birth_) >= incubation_length_) {
        tile->thing = grow(turn_number);
        environment->KillSeed(this);
        //std::cout << "Grew into a plant after " << incubation_length_ << " turn(s)!" << std::endl;
    } else if (environment->get_raining()) {
        thirst_start_ = -1;
    } else if (thirst_start_ != -1 && ((turn_number - thirst_start_) >= parent_->get_durability())) {
        // Die of a lack of water
        tile->thing = nullptr;
        environment->KillSeed(this);
    } else if (!environment->get_raining()) {
        thirst_start_ = turn_number;
    }
}

LivingThingType Seed::get_living_thing_type() {
    return LivingThingType::kSeed;
}
