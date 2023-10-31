#include "splash.h"

#include "application.h"

#include <iostream>
#include <windows.h>

Splash::Splash(Application* app)
    : Page(app)
{
}

Splash::~Splash()
{
}

Page::Type Splash::getPageType() const
{
    return Page::Type::Splash;
}

void Splash::input(const std::string& input)
{
}

void Splash::update(/*const std::string& input*/)
{
    if (m_DelayTime > 0)
    {
        Sleep(1000);
        --m_DelayTime;
    }
    else
    {
        m_app->swapPage(Page::Type::Lobby);
    }
}

void Splash::render()
{
    
    std::cout << "Loading... " << m_DelayTime << std::endl;
    
}