#pragma once

#include "page.h"
#include <string>



class GamePage : public Page
{
public:

public:
    GamePage(Application* app);
    //GamePage(const PlayerCtx& player_1, const PlayerCtx& player_2);
    ~GamePage();

public:
    Type getPageType() const;

    void input(const std::string& input) override;
    void update(float dt) override;
    void render() override;
};
