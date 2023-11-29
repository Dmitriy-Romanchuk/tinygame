#include "splash.h"

#include "application.h"
#include <format>
#include <iostream>


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
        m_DelayTime -= dt;
    }
    else
    {
        auto& app = Application::getInstance();
        app.swapPage(Page::Type::Lobby);
    }
}

void Splash::render(std::string& buff)
{
    buff.append(std::format("Loading... {:f}", m_DelayTime));
}
