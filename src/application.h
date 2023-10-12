#pragma once


#include "page.h"

#include <string>

class Application
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
    Page* createSplashPage() const;
    Page* createLobbyPage() const;
    Page* createGamePage() const;

    void clearCurrentPage();

private:
    bool m_IsRunning = false;

private:
    Page* m_currentPage = nullptr;
};


