//
// Created by thosa on 8/5/2017.
//

#include "genetic.h"

int GeneticInt(int parent1, int parent2) {
    int type = rand() % 4;

    switch (type) {
        case 0:
            return parent1;
        case 1:
            return parent2;
        case 2:
            return rand() % parent1 + parent2;
        default:
            return parent2 + 1;
    }
}

int PossibleMutationInt(int trait, int addend) {
    int t = (rand() % 100 + 1);
    if (t == 1) {
        return trait + addend;
    } else if (t == 2) {
        int x = trait - addend;
        return x > 0 ? x : 1;
    } else {
        return trait;
    }
}
