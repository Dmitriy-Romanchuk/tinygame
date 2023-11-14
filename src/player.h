#pragma once

//#include "board.h"
#include "PlayerCtx.h"

#include <string>

class Board;

class Player
{
public:
    Player(Board* board, char symbol, const PlayerCtx& ctx);
    ~Player();

public:
    bool onInput(const std::string& input);
    std::string getPlayerName();

private:
    Board* m_board = nullptr;
    char m_symbol;
    PlayerCtx m_ctx;
};
