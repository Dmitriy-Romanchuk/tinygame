#pragma once

class controller
{
private:
    const char cross = 'X';
    const char zero = '0';
    char user_sign = ' ';
public:
    controller(/* args */);
    ~controller();
    
    void select_game_sign();
};


