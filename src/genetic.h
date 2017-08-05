//
// Created by thosa on 8/5/2017.
//

#ifndef QUOIDS_GENETIC_H
#define QUOIDS_GENETIC_H

#include <cstdlib>

/**
 * Randomly chooses an integer value from two sexual parents.
 * @param parent1
 * @param parent2
 * @return
 */
int GeneticInt(int parent1, int parent2);

/**
 * An integer can possibly be a mutation, in which case the [addend] is added.
 * @param trait
 * @param addend
 * @return
 */
int PossibleMutationInt(int trait, int addend);

#endif //QUOIDS_GENETIC_H
