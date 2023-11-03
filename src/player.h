#pragma once

#include <string>

class Board;

class Player
{
public:
    Player(Board* board, char symbol, const PlayerCtx& ctx);
    ~Player();

public:
    bool onInput(std::string input);

private:
    Board* m_board = nullptr;
    char m_symbol;
    PlayerCtx m_ctx;
};
