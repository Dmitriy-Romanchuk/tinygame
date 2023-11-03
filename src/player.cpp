#include "player.h"

#include "application.h"
#include "board.h"

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
    m_board->trySetPoint(0u , 0u, m_symbol);
}