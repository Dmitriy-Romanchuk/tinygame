#pragma once

#include <string>

class Player
{
private:
    /* data */
public:
    Player(/* args */);
    ~Player();
public:
    bool onInput(std::string input);
};

Player::Player(/* args */)
{
}

Player::~Player()
{
}
