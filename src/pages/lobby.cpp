#include "lobby.h"
#include "application.h"

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

PlayerCtx* Lobby::getContext()
{
    return m_players;
}

void Lobby::input(const std::string& input)
{
    switch (m_requestState)
    {
    case StateRequest::PlayerType:
        if (input != "1" && input != "2")
        {
            m_hasInputError = true;
        }
        else
        {
            fillPlayerCtx(input);
            m_requestState = StateRequest::PlayerName;
        }
        break;
    case StateRequest::PlayerName:
        if (input.empty())
        {
            m_hasInputError = true;
        }
        else
        {
            fillPlayerCtx(input);
            m_requestState = StateRequest::PlayerType;
            m_countPlayers++;
        }
        break;
    default:
        break;
    }
}

void Lobby::update()
{
    if (m_countPlayers >= m_maxPlayers)
    {
        m_app->swapPage(Page::Type::Game);
    }
}

void Lobby::fillPlayerCtx(const std::string& input)
{
    if (m_requestState == StateRequest::PlayerType)
    {
        if (input == "1")
        {
            m_players[m_countPlayers].playerType = PlayerCtx::Type::Player;
        }
        else if (input == "2")
        {
            m_players[m_countPlayers].playerType = PlayerCtx::Type::Bot;
        }
    }

    if (m_requestState == StateRequest::PlayerName)
    {
        m_players[m_countPlayers].playerName = input;
    }
}

void Lobby::renderRequestType(std::string& buff) const
{
    buff.append("Select player type: press [1] - Player, [2] - Bot:");
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

    if (m_hasInputError == true)
    {
        renderErrorInput(buff);
        m_hasInputError = false;
    }

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
