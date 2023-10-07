#pragma once

class board
{
private:
    char symbols[3][3] = {};
    char cross = 'X';
    char zero = 'O';
public:
    board();
    ~board();
    void render_playing_area();
};