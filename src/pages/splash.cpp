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

void Splash::onInput(const std::string& input)
{
}

void Splash::update(float dt)
{
    if (m_DelayTime > 0.0f)
    {
        Sleep(dt * 1000.f);
        m_DelayTime -= dt;
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