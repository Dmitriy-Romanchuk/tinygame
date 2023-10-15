#include "application.h"

#include <iostream>

int main()
{
    Application game;

    game.init();
    game.run();

    system("pause");

    return EXIT_SUCCESS;
}