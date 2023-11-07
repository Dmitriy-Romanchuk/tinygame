#include "player.h"

#include "application.h"

#include <iostream> // need to delete

Player::Player(Board* board, char symbol, const PlayerCtx& ctx)
    : m_board(board)
    , m_symbol(symbol)
    , m_ctx(ctx)
{
}

Player::~Player()
{
}

bool Player::onInput(std::string input)
{   
    if(input.size() > 1)
    {
        return false;
    }

    int cellNumber = input.at(0) - '0';

    m_board->trySetPoint(cellNumber, m_symbol);
    return true;
}