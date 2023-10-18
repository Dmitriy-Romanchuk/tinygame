#pragma once

#include "page.h"

class board
{
private:
    /* data */
public:
    board(/* args */);
    ~board();

public:
    void input(const std::string& input) ;
    void update() ;
    void render() ;
};

board::board(/* args */)
{
}

board::~board()
{
}
