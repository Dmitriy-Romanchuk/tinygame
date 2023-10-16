#include "board.h"

#include <iostream>
#include <iomanip>

board::board(/* args */)
{
}

board::~board()
{
}

void board::input(const std::string& input)
{

}
void board::update(float dt)
{

}

void board::render()
{
    std::cout << std::setw(4) << "|" << std::setw(4) << "|" << std::endl;
    std::cout << " X "
              << "|"
              << " O "
              << "|"
              << " O " << std::endl;
    std::cout << std::setfill('-') << std::setw(4) << "|" << std::setw(4) << "|" << std::setw(4) << '\n';
    std::cout << std::setfill(' ') << " O "
              << "|"
              << " X "
              << "|"
              << " O " << std::endl;
    std::cout << std::setfill('-') << std::setw(4) << "|" << std::setw(4) << "|" << std::setw(4) << '\n';
    std::cout << std::setfill(' ') << " O "
              << "|"
              << " O "
              << "|"
              << " X " << std::endl;
    std::cout << std::setw(4) << "|" << std::setw(4) << "|" << std::endl;
}
