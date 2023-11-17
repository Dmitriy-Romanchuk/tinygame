#include <cassert>
#include <charconv>
#include <iomanip>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <system_error>

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
    //if (ec == std::errc())
    //    std::cout << "Result: " << inputOnInt << '\n';
    //else if (ec == std::errc::invalid_argument)
    //    std::cout << "This is not a number.\n";
    //else if (ec == std::errc::result_out_of_range)
    //    std::cout << "This number is larger than an int.\n";

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
