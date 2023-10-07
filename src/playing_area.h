#pragma once

class board
{
private:
    char symbols[3][3] = {};
    
public:
    board();
    ~board();
    void render_playing_area();
};