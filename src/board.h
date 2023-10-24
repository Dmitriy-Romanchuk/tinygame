#pragma once

#include "page.h"

#include <string>
#include <array>

class Board final
{
public:
    using Data = std::array<char, 9>;

public:
    Board();
    
public:
    const Data& getData() const;

    void render(std::string& buff) const;

private:
    void fillBoard(std::string& boardBuff) const;

private:
    Data m_data;
    std::string m_gameBoard;

};
