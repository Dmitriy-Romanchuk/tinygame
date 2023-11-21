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

    if (m_state == Board::State::Active)
    {
        m_stepsCount++;
    }

    if (m_state == Board::State::ReadyToStart)
    {
        m_state = Board::State::Active;
    }
}

const Board::Data& Board::getData() const
{
    return m_data;
}

const Board::State& Board::getState() const
{
    return m_state;
}

uint32_t Board::getCurrentPlayerIndex() const
{
    return m_stepsCount % 2;
}

void Board::start()
{
    m_state = State::ReadyToStart;
    m_stepsCount = 0;
    clearBoard();
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
        return false;
    }

    m_data[cellNumber] = symbol;
    return true;
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

void Board::updateState()
{
    if ((m_data[1] != ' ' && m_data[0] == m_data[1] && m_data[1] == m_data[2])
        || (m_data[4] != ' ' && m_data[3] == m_data[4] && m_data[4] == m_data[5])
        || (m_data[7] != ' ' && m_data[6] == m_data[7] && m_data[7] == m_data[8])
        || (m_data[3] != ' ' && m_data[0] == m_data[3] && m_data[3] == m_data[6])
        || (m_data[4] != ' ' && m_data[1] == m_data[4] && m_data[4] == m_data[7])
        || (m_data[5] != ' ' && m_data[2] == m_data[5] && m_data[5] == m_data[8])
        || (m_data[4] != ' ' && m_data[0] == m_data[4] && m_data[4] == m_data[8])
        || (m_data[4] != ' ' && m_data[2] == m_data[4] && m_data[4] == m_data[6]))
    {
        m_state = Board::State::Win;
    }
    else if (m_stepsCount == 9)
    {
        m_state = Board::State::Draw;
    }
}