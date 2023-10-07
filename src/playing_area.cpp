#include "playing_area.h"

#include <iomanip>
#include <iostream>

board::board()
{
}

board::~board()
{
}

void board::render_playing_area()
{   
    std::cout << std::setw(4) << "|" << std::setw(4) << "|" << std::endl;
    std::cout << " X "  << "|" << " O " << "|" << " O " << std::endl;
    std::cout << std::setfill('-') << std::setw(4)  << "|" << std::setw(4) << "|" << std::setw(4) << '\n';
    std::cout << std::setfill(' ') << " O "  << "|" << " X " << "|" << " O " << std::endl;
    std::cout << std::setfill('-') << std::setw(4)  << "|" << std::setw(4) << "|" << std::setw(4) << '\n';
    std::cout << std::setfill(' ') << " O "  << "|" << " O " << "|" << " X " << std::endl;
    std::cout << std::setw(4) << "|" << std::setw(4) << "|" <<  std::endl;
}


   