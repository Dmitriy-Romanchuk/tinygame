#include "game_page.h"

#include <iostream>

GamePage::GamePage(Application* app, const PlayersCtx& playersCtx)
    : Page(app)
{
    m_players[0] = createPlayer(playersCtx[0], 'X');
    m_players[1] = createPlayer(playersCtx[1], 'O');
}

GamePage::~GamePage()
{
    for (auto player : m_players)
    {
        delete player;
    }
}

Page::Type GamePage::getPageType() const
{
    return Page::Type::Game;
}

void GamePage::onInput(const std::string& input)
{
    if (m_requestState == StateRequest::Welcome)
    {
        return;
    }
    else if (m_requestState == StateRequest::CellNumber)
    {
        m_succesSetPoint = m_players[m_currentPlayerIndex]->onInput(input);

    }
}

void GamePage::update()
{
    //bool noError = false;
    //if (noError == false)
    //{
    //    return;
    //}

    if (m_requestState == StateRequest::Welcome)
    {
        m_requestState = StateRequest::CellNumber;
    }
    
    if(m_succesSetPoint == true)
    {
        m_hasInputError = true;
        togglePlayer();
    }
    else
    {
        m_hasInputError = true;
    }

    
}

void GamePage::render()
{
    std::string buff;
    // buff.reserve(1000);
    // buff.clear();

    switch (m_requestState)
    {
    case StateRequest::Welcome:
        renderWelcome(buff);
        break;

    case StateRequest::CellNumber:
        // m_board.render(buff);
        renderCellNumber(buff);
        break;

        if (m_hasInputError == true)
        {
            renderErrorInput(buff);
            m_hasInputError = false;
        }
    default:
        break;
    }

    std::cout << "\t\t*****GAME PAGE*****\n\n"
              << buff << std::endl;
}

void GamePage::renderWelcome(std::string& buff) const
{
    buff.append("Starting battle!\n");
}

void GamePage::renderCellNumber(std::string& buff) const
{
    m_board.render(buff);

    buff.append("\nSelect cell number in range (1...9): ");
}

void GamePage::renderErrorInput(std::string& buff) const
{
    buff.append("Error input. Try again.\n");
}

Player* GamePage::createPlayer(const PlayerCtx& playersCtx, char symbol)
{
    if (playersCtx.playerType == PlayerCtx::Type::Player)
    {
        return new Player(&m_board, symbol, playersCtx);
    }

    return new Player(&m_board, symbol, playersCtx);
}

void GamePage::togglePlayer()
{
    if(m_currentPlayerIndex == 0)
    {
        m_currentPlayerIndex = 1;
    }
    else
    {
        m_currentPlayerIndex = 0;
    }

}
