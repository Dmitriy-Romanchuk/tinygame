#pragma once
#include <string>

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

