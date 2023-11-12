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
        m_hasInputError = m_players[m_currentPlayerIndex]->onInput(input);
    }
}

void GamePage::update()
{
    if (m_requestState == StateRequest::Welcome)
    {
        m_requestState = StateRequest::CellNumber;
    }

    if (m_hasInputError == false)
    {
        togglePlayer();
    }

    if(m_board.checkWin() == true)
    {
        m_requestState = StateRequest::GameResult;
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

        renderCellNumber(buff);

        if (m_hasInputError == true)
        {
            renderErrorInput(buff);
            m_hasInputError = false;
        }
    
    case StateRequest::GameResult:
        renderGameResult(buff);
        break;

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

    buff.append(m_players[m_currentPlayerIndex]->getPlayerName());
    buff.append("! Yours move in the game!\nSelect cell number in range (1...9): ");
}

void GamePage::renderErrorInput(std::string& buff) const
{
    buff.append("\nError input. Try again.\n");
}

void GamePage::renderGameResult(std::string& buff) const
{
    std::cout << "RenderGameResult" << std::endl;
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
    if (m_currentPlayerIndex == 1)
    {
        m_currentPlayerIndex = 0;
    }
    else
    {
        m_currentPlayerIndex = 1;
    }
}
