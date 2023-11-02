#pragma once

#include "game_page.h"
#include "PlayerCtx.h"

#include <stdint.h>
#include <string>

class Application final
{
public:
    Application(/* args */);
    ~Application();

    void init();
    void run();
    void deinit();

    void processInput(std::string& input) const;
    void swapPage(Page::Type pageType);

    const PlayerCtx& getPlayerCotext(uint32_t index) const;
    void setPlayerCotext(uint32_t index, const PlayerCtx& playerCtx);

private:
    Page* createSplashPage();
    Page* createLobbyPage();
    Page* createGamePage();

    void clearCurrentPage();

private:
    bool m_IsRunning = true;
    PlayersCtx m_players;
    PlayerCtx m_currentPlayer;

private:
    Page* m_currentPage = nullptr;
};
