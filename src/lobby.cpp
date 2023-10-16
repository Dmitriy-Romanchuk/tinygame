#include "lobby.h"
#include "player.h"

#include <iostream>

Lobby::Lobby(Application* app)
    : Page(app)
{
}

Lobby::~Lobby()
{
}

Page::Type Lobby::getPageType() const
{
    return Page::Type::Lobby;
}

void Lobby::input(const std::string& input)
{
    if (m_requestState == StateRequest::PlayerType)
    {
        
    }

    if (m_requestState == StateRequest::PlayerName)
    {
    }
}

void Lobby::update(float)
{
}

std::string Lobby::renderRequestType() const
{
    return "Select player type: press [1] if User, [2] - Bot:";
}

std::string Lobby::renderRequestName() const
{
    return "Input player name:\n";
}

void Lobby::render()
{
    std::string buff;

    switch (m_requestState)
    {
    case StateRequest::PlayerType:
        buff = renderRequestType();
        break;
    case StateRequest::PlayerName:
        buff = renderRequestName();
        break;
    default:
        break;
    }

    std::cout << "*****LOBBY PAGE*****" << std::endl
              << buff << std::endl;
}
