#pragma once

#include "playing_area.h"
#include "splash_screen.h"
#include "game_controller.h"
#include "players.h"

class application
{
public:
    velcome_screen splash;
    board playing_area;
    controller sign_controller;
    players bot;
    players player;

public:
    application(/* args */);
    ~application();

    void init();
    void run();
    void deinit();
};


