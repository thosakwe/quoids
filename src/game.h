//
// Created by thosa on 8/4/2017.
//

#ifndef QUOIDS_GAME_H
#define QUOIDS_GAME_H


#include "environment.h"

class Game {
private:
    Environment* environment_;
    int turn_number_ = -1;
    bool done_ = false, paused_ = false;
public:
    void start(int w, int h);
    void turn();
};


#endif //QUOIDS_GAME_H
