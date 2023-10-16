#pragma once

#include "game_page.h"

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

private:
    Page* createSplashPage();
    Page* createLobbyPage();
    Page* createGamePage();

    void clearCurrentPage();

private:
    bool m_IsRunning = true;

private:
    Page* m_currentPage = nullptr;
};
