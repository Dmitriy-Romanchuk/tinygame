#include "board.h"

#include <iomanip>
#include <iostream>

namespace
{
    constexpr const char* BoardTemplate = R"(
  You play here:              Cell Numbers:          

     |     |                     |     |     
     |     |                  1  |  2  |  3  
-----|-----|-----           -----|-----|-----
     |     |                  4  |  5  |  6  
-----|-----|-----           -----|-----|-----
     |     |                  7  |  8  |  9  
     |     |                     |     |     
     
)";
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

    fillBoard(boardBuff);

    buff.append(boardBuff);
}

bool Board::trySetPoint(uint32_t cellNumber, char symbol)
{
    const uint32_t size = m_data.size();

    if (m_data[cellNumber] != ' ')
    {
        return true;
    }

    m_data[cellNumber] = symbol;
    return false;
}

void Board::fillBoard(std::string& boardBuff) const
{
    const int offset[9] = { 104, 110, 116, 196, 202, 208, 288, 294, 300 };

    auto size = m_data.size();
    for (size_t index = 0; index < size; index++)
    {
        boardBuff[offset[index]] = m_data[index];
    }
}

bool Board::checkWin() const
{
    if(m_data[0] == m_data[1] && m_data[1] == m_data[2]) return true;
    else if(m_data[3] == m_data[4] && m_data[4] == m_data[5]) return true;
    else if(m_data[6] == m_data[7] && m_data[7] == m_data[8]) return true;
    else if(m_data[0] == m_data[3] && m_data[3] == m_data[6]) return true;
    else if(m_data[1] == m_data[4] && m_data[4] == m_data[7]) return true;
    else if(m_data[2] == m_data[5] && m_data[5] == m_data[8]) return true;
    else if(m_data[0] == m_data[4] && m_data[4] == m_data[8]) return true;
    else if(m_data[2] == m_data[4] && m_data[4] == m_data[6]) return true;

    return false;
}
