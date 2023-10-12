#pragma once

#include "application.h"

class Player
{
private:
    enum m_player_type{Bot, People};
    const char m_cross = 'X';
    const char m_zero = '0';
    
public:
    Player(/* args */);
    ~Player();
};


