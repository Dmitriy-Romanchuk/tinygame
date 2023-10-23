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
}

void GamePage::update()
{
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
        m_board.render(buff);
        renderCellNumber(buff);
        break;
    default:
        break;
    }

    if (m_hasInputError == true)
    {
        renderErrorInput(buff);
        m_hasInputError = false;
    }

    std::cout << "\t\t*****GAME PAGE*****\n\n"
              << buff << std::endl;
}

void GamePage::renderWelcome(std::string& buff) const
{
    buff.append("Starting battle!");
    StateRequest m_requestState = StateRequest::CellNumber;
}

void GamePage::renderCellNumber(std::string& buff) const
{
    buff.append("Enter cell number (e.g. a2)\n");
}

void GamePage::renderErrorInput(std::string& buff) const
{
    buff.append("Error input. Try again.\n");
}
