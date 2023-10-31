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
            m_playerCounter++;
        }
        break;
    default:
        break;
    }
}

void Lobby::update()
{
    if (m_playerCounter >= m_maxPlayers)
    {
        m_app->swapPage(Page::Type::Game);
    }
}

void Lobby::fillPlayerCtx(const std::string& input)
{
    auto playerCtx = m_app->getPlayerCotext(m_playerCounter);

    if (m_requestState == StateRequest::PlayerType)
    {
        if (input == "1")
        {
            playerCtx.playerType = PlayerCtx::Type::Player;
        }

        if (input == "2")
        {
            playerCtx.playerType = PlayerCtx::Type::Bot;
        }
    }

    if (m_requestState == StateRequest::PlayerName)
    {
        playerCtx.playerName = input;
    }

    m_app->setPlayerCotext(m_playerCounter, playerCtx);
}

void Lobby::renderRequestType(std::string& buff) const
{
    buff.append("Select player type: press [1] - Player, [2] - Bot:");
}

void Lobby::renderRequestName(std::string& buff) const
{
    buff.append("Input player name:");
}

void Lobby::renderErrorInput(std::string& buff) const
{
    buff.append("Error input. Try again.\n");
}

void Lobby::render()
{
    std::string buff;
    // buff.reserve(1000);
    // buff.clear();

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
