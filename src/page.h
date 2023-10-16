#pragma once

#include <string>

class Page
{
public:
    enum class Type
    {
        Splash,
        Lobby,
        Game
    };

public:
    virtual ~Page(){};

public:
    virtual Type getPageType() const = 0;

public:
    virtual void input(const std::string& input) = 0;
    virtual void update(float dt) = 0;
    virtual void render() = 0;
};
