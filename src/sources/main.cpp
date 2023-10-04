#include "application.h"
#include "board.h"

#include <iostream>

int main()
{
    bool m_IsRunnning = true;
    application game;

    while(m_IsRunnning)
    {
        game.input();
        game.update();
        game.render();
        
    }
    


    return EXIT_SUCCESS;
}