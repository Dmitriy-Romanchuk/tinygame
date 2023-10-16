#pragma once

#include "page.h"
#include <string>

struct PlayerCtx
{
    enum class Type
    {
        Player,
        Bot
    };

    Type playerType;
    const char* playerName;
};

class GamePage : public Page
{
private:
    char symbols[3][3] = {};

public:
    GamePage();
    GamePage(const PlayerCtx& player_1, const PlayerCtx& player_2);
    ~GamePage();

public:
    Type getPageType() const;

    void input(const std::string& input) override;
    void update(float dt) override;
    void render() override;
};
