#pragma once

#include "playing_area.h"
#include "splash_screen.h"

class application
{
private:
    velcome_screen splash;
    board playing_area;
public:
    application(/* args */);
    ~application();

    void init();
    void run();
    void deinit();
};


