#include <iostream>
#include "src/game.h"

int main(int argc, char **argv) {
    int width, height;

    if (argc > 1)
        sscanf(argv[1], "%d", &width);
    else width = 100;

    if (argc > 2)
        sscanf(argv[2], "%d", &height);
    else height = width;

    Game *game = new Game();
    game->start(width, height);
    return 0;
}