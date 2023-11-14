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
    clearBoard();
}

void Board::update(float dt)
{
    updateState();
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

void Board::clearBoard()
{
    m_data.fill(' ');
}

Board::State Board::updateState()
{
    if ((m_data[1] != ' ' && m_data[0] == m_data[1] && m_data[1] == m_data[2])
        || (m_data[4] != ' ' && m_data[3] == m_data[4] && m_data[4] == m_data[5])
        || (m_data[7] != ' ' && m_data[6] == m_data[7] && m_data[7] == m_data[8])
        || (m_data[4] != ' ' && m_data[1] == m_data[4] && m_data[4] == m_data[7])
        || (m_data[5] != ' ' && m_data[2] == m_data[5] && m_data[5] == m_data[8])
        || (m_data[6] != ' ' && m_data[3] == m_data[6] && m_data[6] == m_data[9])
        || (m_data[5] != ' ' && m_data[1] == m_data[5] && m_data[5] == m_data[9])
        || (m_data[5] != ' ' && m_data[3] == m_data[5] && m_data[5] == m_data[7]))
    {
        m_state = Board::State::Win;
        return m_state;
    }
    else
    {
        m_state = Board::State::Active;
        return m_state;
    }
}
