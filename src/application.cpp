#include "application.h"
#include "board.h"
#include "lobby.h"
#include "page.h"
#include "splash.h"

#include <cassert>
#include <chrono>
#include <iostream>
#include <thread>

Application::~Application()
{
    clearCurrentPage();
}

Application& Application::getInstance()
{
    static Application game;
    return game;
}

void Application::init()
{
    initscr();
    swapPage(Page::Type::Splash);
}

void Application::run()
{
    std::string inputStr;
    char* inputChar;

    float defaultDeltaTime = 1.0f / 60.0f;

    while (m_currentPage->isReadyToQuit() == false)
    {
        const auto start = std::chrono::high_resolution_clock::now();

        clear();

        render();

        inputStr.clear();
        processInput(inputChar);
        inputStr = inputChar;
        m_currentPage->onInput(inputStr);
        m_currentPage->update(defaultDeltaTime);

        const auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> elapsed = end - start;

        std::cout << "elapsed.count() " << elapsed.count() << std::endl;

        // defaultDeltaTime = elapsed.count();
        printw("\nelapsed.count = %f", elapsed.count());
        refresh();

        // std::chrono::duration_cast<double>(std::this_thread::sleep_for(std::chrono::milliseconds(defaultDeltaTime - elapsed.count())));
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }
}

void Application::deinit()
{
    endwin();
}

void Application::processInput(char* inputChar) const
{
    if (m_currentPage->getPageType() == Page::Type::Splash)
    {
        return;
    }

    getstr(inputChar);
}

void Application::swapPage(Page::Type pageType)
{
    if (m_currentPage != nullptr && m_currentPage->getPageType() == pageType)
    {
        return;
    }

    if (pageType == Page::Type::Splash)
    {
        clearCurrentPage();
        m_currentPage = createSplashPage();
        return;
    }

    if (pageType == Page::Type::Lobby)
    {
        clearCurrentPage();
        m_currentPage = createLobbyPage();
        return;
    }

    if (pageType == Page::Type::Game)
    {
        clearCurrentPage();
        m_currentPage = createGamePage();
        return;
    }
}

void Application::render() const
{
    std::string buff;
    m_currentPage->render(buff);
    printw(buff.c_str());
    refresh();
}

Page* Application::createSplashPage()
{
    return new Splash();
}

Page* Application::createLobbyPage()
{
    return new Lobby();
}

Page* Application::createGamePage()
{
    return new GamePage(m_players);
}

void Application::clearCurrentPage()
{
    delete m_currentPage;
}

const PlayerCtx& Application::getPlayerCotext(uint32_t index) const
{
    assert(index < m_players.size());
    return m_players[index];
}

void Application::setPlayerCotext(uint32_t index, const PlayerCtx& playerCtx)
{
    assert(index < m_players.size());
    m_players[index] = playerCtx;
}
