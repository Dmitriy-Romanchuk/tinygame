#include "application.h"
#include "lobby.h"
#include "page.h"
#include "splash.h"

#include <iostream>

Application::Application()
{
}

Application::~Application()
{
    clearCurrentPage();
}

void Application::init()
{
    swapPage(Page::Type::Splash);
}

void Application::run()
{
    constexpr float defaultDeltaTime = 1.0f / 60.0f;
    std::string input;

    while (m_IsRunning)
    {
        system("cls");

        m_currentPage->render();

        input.clear();
        processInput(input);
        m_currentPage->input(input);
        m_currentPage->update();
    }
}

void Application::deinit()
{
}

void Application::processInput(std::string& input) const
{
    if (m_currentPage->getPageType() == Page::Type::Splash)
    {
        return;
    }
    std::cin >> input;
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

Page* Application::createSplashPage()
{
    return new Splash(this);
}

Page* Application::createLobbyPage()
{
    return new Lobby(this);
}

Page* Application::createGamePage()
{
    return new GamePage(this);
}

void Application::clearCurrentPage()
{
    delete m_currentPage;
}
