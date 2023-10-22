#include "game_page.h"
#include "board.h"
#include "lobby.h"

#include <iostream>

//GamePage::GamePage(Lobby* lbb)
//    : Page(lbb)
//{
//}

// GamePage::GamePage(const PlayerCtx)
//{
//     std::cout << "constructor Game page";
//}

GamePage::GamePage()
{
}

GamePage::~GamePage()
{
}

Page::Type GamePage::getPageType() const
{
    return Page::Type::Game;
}

Board* GamePage::createGameBoard() const
{
    return new Board;
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
    buff.clear();

    if (m_hasInputError == true)
    {
        renderErrorInput(buff);
        m_hasInputError = false;
    }

    switch (m_requestState)
    {
    case StateRequest::Welcome:
        renderWelcome(buff);
        break;
    case StateRequest::CellNumber:
        renderCellNumber(buff);
        break;
    default:
        break;
    }

    std::cout << "\t\t*****GAME PAGE*****" << std::endl
              << std::endl
              << buff << std::endl;
}

void GamePage::renderWelcome(std::string& buff) const
{
    buff.append("Starting battle!");
    StateRequest m_requestState = StateRequest::CellNumber;
    createGameBoard()->getGameBoard();
}

void GamePage::renderCellNumber(std::string& buff) const
{
    buff.append("Enter cell number (e.g. a2)\n");
}

void GamePage::renderErrorInput(std::string& buff) const
{
    buff.append("Error input. Try again.\n");
}
