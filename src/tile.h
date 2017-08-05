//
// Created by thosa on 8/4/2017.
//

#ifndef QUOIDS_TILE_H
#define QUOIDS_TILE_H

#include "thing.h"

struct Position {
    int x, y;
};

struct Tile {
    Position position;
    Thing* thing;
};

#endif //QUOIDS_TILE_H
