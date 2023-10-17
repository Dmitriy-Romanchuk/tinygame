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
        if (input != "1" || input != "2")
        {
            m_inputError = true;
        }
        
    }

    if (m_requestState == StateRequest::PlayerName)
    {
    }
}

void Lobby::update(float)
{
}

void Lobby::renderRequestType(std::string& buff)
{
    if (m_inputError == true)
    {
        renderErrorInput(buff);
        m_inputError = false;
    }
    buff.append("Select player type: press [1] if User, [2] - Bot:");
}

void Lobby::renderRequestName(std::string& buff) const
{
    buff.append("Input player name:\n");
}

void Lobby::renderErrorInput(std::string& buff) const
{
    buff.append("Error input. Try again.\n");
}

void Lobby::render()
{
    std::string buff;
    buff.clear();

    switch (m_requestState)
    {
    case StateRequest::PlayerType:
        renderRequestType(buff);
        break;
    case StateRequest::PlayerName:
        renderRequestName(buff);
        break;
    default:
        break;
    }

    std::cout << "\t\t*****LOBBY PAGE*****" << std::endl
              << std::endl
              << buff << std::endl;
}
