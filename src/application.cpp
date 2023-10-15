#include "application.h"

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
    std::string input = "Test";

    while (m_IsRunning)
    {
        input.clear();
        processInput(input);
        m_currentPage->input(input);
        m_currentPage->update(defaultDeltaTime);

        m_currentPage->render();
    }
}

void Application::deinit()
{
}

void Application::processInput(std::string& input) const
{
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
        return;
    }

    if (pageType == Page::Type::Game)
    {
        clearCurrentPage();
        return;
    }
}

Page* Application::createSplashPage()
{
    m_currentPage = new Splash;
    return m_currentPage;
}

Page* Application::createLobbyPage()
{
    m_currentPage = new Lobby;
    return m_currentPage;
}

Page* Application::createGamePage()
{
    m_currentPage = new GamePage;
    return m_currentPage;
}

void Application::clearCurrentPage()
{
    delete m_currentPage;
}
