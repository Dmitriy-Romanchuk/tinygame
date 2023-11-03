#include "board.h"

#include <iostream>
#include <iomanip>

namespace
{
    constexpr const char* BoardTemplate = R"(
    1     2     3
       |     |     
1      |     |   
  -----|-----|-----  
2      |     |       
  -----|-----|-----
3      |     |    
       |     |     )";
} // namespace


Board::Board(/* args */)
{
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

bool Board::trySetPoint(uint32_t x, uint32_t y, char symbol)
{
    const uint32_t size = m_data.size();
    
    if (false)
    {
        return false;
    }
    
    m_data[x + x * y] = symbol;

    return true;
}

void Board::fillBoard(std::string& boardBuff) const
{
//    auto size = m_data.size();
//    for (size_t index = 0; index < size; index++)
//    {
//        boardBuff[index + offset] = m_data[index];
//    }

    boardBuff[2] = 'x';
}

