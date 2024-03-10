
#include "headers/stdafx.h"

#include "headers/Game.h"

int main()
{
    Game game;

    while (true) {
        game.update();

        game.render();

    }


    return 0;
}