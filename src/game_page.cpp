#include "game_page.h"

#include <iomanip>
#include <iostream>

GamePage::GamePage()
{
}

GamePage::~GamePage()
{
}

void GamePage::input(std::string)
{
}

void GamePage::update(float dt)
{
}

void render()
{   
    std::cout << std::setw(4) << "|" << std::setw(4) << "|" << std::endl;
    std::cout << " X "  << "|" << " O " << "|" << " O " << std::endl;
    std::cout << std::setfill('-') << std::setw(4)  << "|" << std::setw(4) << "|" << std::setw(4) << '\n';
    std::cout << std::setfill(' ') << " O "  << "|" << " X " << "|" << " O " << std::endl;
    std::cout << std::setfill('-') << std::setw(4)  << "|" << std::setw(4) << "|" << std::setw(4) << '\n';
    std::cout << std::setfill(' ') << " O "  << "|" << " O " << "|" << " X " << std::endl;
    std::cout << std::setw(4) << "|" << std::setw(4) << "|" <<  std::endl;
}


   