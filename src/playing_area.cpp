#include "playing_area.h"

#include <iomanip>
#include <iostream>

board::board()
{
}

board::~board()
{
}

void board::drawer()
{   
    std::cout << std::setw(4) << "|" << std::setw(4) << "|" << std::endl;
    std::cout << " O "  << "|" << " O " << "|" << " O " << std::endl;
    std::cout << std::setfill('-') << std::setw(4)  << "|" << std::setw(4) << "|" << std::setw(4) << '\n';
    std::cout << " O "  << "|" << " O " << "|" << " O " << std::endl;
    std::cout << std::setfill('-') << std::setw(4)  << "|" << std::setw(4) << "|" << std::setw(4) << '\n';
    std::cout << " O "  << "|" << " O " << "|" << " O " << std::endl;
    std::cout << std::setw(4) << "|" << std::setw(4) << "|" <<  std::endl;
  



}


   