#pragma once

#include "page.h"

class board : public Page
{
private:
    /* data */
public:
    board(/* args */);
    ~board();

public:
    void input(const std::string& input) override;
    void update(float dt) override;
    void render() override;
};

board::board(/* args */)
{
}

board::~board()
{
}
