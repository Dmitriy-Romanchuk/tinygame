#include "application.h"
#include "playing_area.h"

#include <iostream>

int main()
{
    application game;
    std::cout << "Development mode" << std::endl;
    board newboard;
    newboard.drawer();

    return EXIT_SUCCESS;
}