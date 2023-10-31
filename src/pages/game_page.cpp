#include "game_page.h"

#include <iostream>

GamePage::GamePage(Application* app, const PlayersCtx& playersCtx)
    : Page(app)
{
}

GamePage::~GamePage()
{
}

Page::Type GamePage::getPageType() const
{
    return Page::Type::Game;
}

void GamePage::input(const std::string& input)
{
    if (m_requestState == StateRequest::Welcome)
    {
        if (input == "q")
        {
            exit(0);
        }
    }
}

void GamePage::update(/*const std::string& input*/)
{
    if (m_requestState == StateRequest::Welcome)
    {
        m_requestState = StateRequest::CellNumber;
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
    buff.append("Starting battle!\nReady? Press any key to start.\nExit - q.");
}

void GamePage::renderCellNumber(std::string& buff) const
{
    m_board.render(buff);
    buff.append("\n\nEnter cell number (e.g. 1 2): ");
}

void GamePage::renderErrorInput(std::string& buff) const
{
    buff.append("Error input. Try again.\n");
}
