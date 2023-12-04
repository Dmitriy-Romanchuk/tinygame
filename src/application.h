#pragma once

#include "PlayerCtx.h"
#include "game_page.h"

#include <stdint.h>
#include <string>
#include <ncurses/curses.h>

class Application final
{
public:
    static Application& getInstance();
    ~Application();

    Application(const Application&) = delete;
    Application(Application&&) = delete;

    Application& operator=(const Application&) = delete;
    Application& operator=(Application&&) = delete;

public:
    void init();
    void run();
    void deinit();

    void swapPage(Page::Type pageType);

    const PlayerCtx& getPlayerCotext(uint32_t index) const;
    void setPlayerCotext(uint32_t index, const PlayerCtx& playerCtx);

private:
    Application(){};

private:
    void processInput(std::string& input) const;
    void render() const;
    
    Page* createSplashPage();
    Page* createLobbyPage();
    Page* createGamePage();

    void clearCurrentPage();


private:
    PlayersCtx m_players;
    PlayerCtx m_currentPlayer;

private:
    Page* m_currentPage = nullptr;
};
