#include <cassert>
#include <charconv>
#include <iostream>
#include <string>

#include "player.h"

#include "application.h"

Player::Player(Board* board, char symbol, const PlayerCtx& ctx)
    : m_board(board)
    , m_symbol(symbol)
    , m_ctx(ctx)
{
}

bool Player::onInput(const std::string& input)
{
    int inputOnInt{};

    auto [ptr, ec] = std::from_chars(input.data(), input.data() + input.size(), inputOnInt);

    inputOnInt = inputOnInt - 1;

    if (inputOnInt > 8 || inputOnInt < 0)
    {
        return true;
    }

    if (m_board->trySetPoint(inputOnInt, m_symbol) == true)
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