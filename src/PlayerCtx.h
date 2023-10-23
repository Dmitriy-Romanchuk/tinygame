#pragma once

#include <string>
#include <array>

struct PlayerCtx
{
    enum class Type
    {
        Player,
        Bot
    };

    Type playerType = Type::Player;
    std::string playerName = "User";
};

using PlayersCtx = std::array<PlayerCtx, 2>;
