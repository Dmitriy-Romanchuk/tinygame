#include "board.h"

#include <iostream>
#include <iomanip>

namespace
{
    constexpr const char* BoardTemplate = "   |   |   \n   |   |   \n   |   |   \n";
} // namespace


Board::Board(/* args */)
{
    // auto size = m_data.size();
    // for (size_t index = 0; index < size; index++)
    // {
    //     m_data[index] = ' ';
    // }

    m_data.fill(' ');
}

const Board::Data& Board::getData() const
{
    return m_data;
}

void Board::render(std::string& buff) const
{
    static std::string boardBuff(BoardTemplate);

    // fill
    fillBoard(boardBuff);

    buff.append(boardBuff);
}

void Board::fillBoard(std::string& boardBuff) const
{
    auto size = m_data.size();
    for (size_t index = 0; index < size; index++)
    {
        boardBuff[index + offset] = m_data[index];
    }
    
}

// std::string Board::getGameBoard()
// {
//     return m_gameBoard;
// }
// void Board::setCellNumber()
// {}

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
