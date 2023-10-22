#pragma once

#include "page.h"

#include <string>

class Board
{
private:
    std::string m_gameBoard;

public:
    Board(/* args */);
    ~Board();

public:
    std::string getGameBoard();
    void setCellNumber();
};
