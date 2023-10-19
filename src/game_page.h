#pragma once

#include "PlayerCtx.h"
#include "page.h"
#include <string>

class GamePage : public Page
{
public:
public:
    GamePage(Application* app);
    
    GamePage(const PlayerCtx);
    ~GamePage();

public:
    Type getPageType() const;

    void input(const std::string& input) override;
    void update() override;
    void render() override;
};
