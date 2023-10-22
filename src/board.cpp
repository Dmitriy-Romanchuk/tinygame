#include "board.h"

#include <iostream>
#include <iomanip>

Board::Board(/* args */)
{
}

Board::~Board()
{
}

std::string Board::getGameBoard()
{
    return m_gameBoard;
}
void Board::setCellNumber()
{}

//void Board::render()
//{
//    std::cout << std::setw(4) << "|" << std::setw(4) << "|" << std::endl;
//    std::cout << " X "
//              << "|"
//              << " O "
//              << "|"
//              << " O " << std::endl;
//    std::cout << std::setfill('-') << std::setw(4) << "|" << std::setw(4) << "|" << std::setw(4) << '\n';
//    std::cout << std::setfill(' ') << " O "
//              << "|"
//              << " X "
//              << "|"
//              << " O " << std::endl;
//    std::cout << std::setfill('-') << std::setw(4) << "|" << std::setw(4) << "|" << std::setw(4) << '\n';
//    std::cout << std::setfill(' ') << " O "
//              << "|"
//              << " O "
//              << "|"
//              << " X " << std::endl;
//    std::cout << std::setw(4) << "|" << std::setw(4) << "|" << std::endl;
//}
