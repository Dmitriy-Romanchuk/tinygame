#include "player.h"

#include "application.h"

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
    if (input.size() > 1 || std::stoi(input) > 9 || std::stoi(input) <= 0)
    {
        return true;
    }

    int cellNumber = std::stoi(input) - 1;

    if(m_board->trySetPoint(cellNumber, m_symbol) == true)
    {
        return true;
    }

    return false;
}

std::string Player::getPlayerName()
{
    return m_ctx.playerName;
}
