#include "application.h"

#include <iostream>

int main()
{
    Application game;

    game.init();
    game.run();
    game.deinit();

    system("pause");

    return EXIT_SUCCESS;
}