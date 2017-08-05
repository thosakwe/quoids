//
// Created by thosa on 8/4/2017.
//

#include "Fruit.h"

Fruit::Fruit(Plant* parent, int seed_count) {
    parent_ = parent;
    seed_count_ = seed_count;
}

Plant *Fruit::get_parent() {
    return parent_;
}

int Fruit::get_seed_count() {
    return seed_count_;
}
