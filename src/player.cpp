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

bool Player::onInput(const std::string& input)
{
    int cellNumber = std::stoi(input) - 1;

    if (cellNumber > 8 || cellNumber < 0)
    {
        return true;
    }

    if (m_board->trySetPoint(cellNumber, m_symbol) == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}

std::string Player::getPlayerName()
{
    return m_ctx.playerName;
}
