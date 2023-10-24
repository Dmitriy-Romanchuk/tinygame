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

void Board::fillBoard(std::string& boardBuff) const
{
//    auto size = m_data.size();
//    for (size_t index = 0; index < size; index++)
//    {
//        boardBuff[index + offset] = m_data[index];
//    }  
}

