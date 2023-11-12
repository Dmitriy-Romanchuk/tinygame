#pragma once

#include "page.h"

#include <stdint.h>
#include <string>
#include <array>

class Board final
{
public:
    using Data = std::array<char, 9>;

public:
    Board();
    
public:
    void render(std::string& buff) const;
    bool trySetPoint(uint32_t cellNumber, char symbol);
    bool checkWin() const;

    const Data& getData() const;

private:
    void fillBoard(std::string& boardBuff) const;
    

private:
    Data m_data;
    std::string m_gameBoard;
    

};


