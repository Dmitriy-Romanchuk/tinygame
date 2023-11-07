#include "board.h"

#include <iomanip>
#include <iostream>

namespace
{
    constexpr const char* BoardTemplate = R"(
    1     2     3  
       |     |     
0      |     |     
  -----|-----|-----
1      |     |     
  -----|-----|-----
2      |     |     
       |     |     )";
} // namespace

Board::Board()
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

bool Board::trySetPoint(uint32_t cellNumber, char symbol)
{
    const uint32_t size = m_data.size();

    // if (m_data[x * y - 1] != ' ')
    //{
    //     return false;
    // }

    m_data[cellNumber] = symbol;

    return true;
}

void Board::fillBoard(std::string& boardBuff) const
{
    const int offset[9] = { 45, 51, 57, 85, 91, 97, 125, 131, 137 };

    auto size = m_data.size();
    for (size_t index = 0; index < size; index++)
    {
        boardBuff[offset[index]] = m_data[index];
    }
}
