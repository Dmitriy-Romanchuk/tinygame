#include "game_controller.h"
#include "players.h"
#include "application.h"

#include <iostream>

controller::controller(/* args */)
{
}

controller::~controller()
{
}

void controller::select_game_sign()
{
    while(user_sign != cross && user_sign != zero)
    {
        std::cout << "Please, select X or 0" << std::endl;
        std::cin >> user_sign;

        if(user_sign != cross && user_sign != zero)
            {
                std::cout << "Yours input \"" << user_sign << "\" is incorrect. Select X or 0" << std::endl;
            }
    }



}
