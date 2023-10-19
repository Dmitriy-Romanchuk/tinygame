#include "board.h"
#include "game_page.h"
#include "lobby.h"

#include <iomanip>
#include <iostream>

GamePage::GamePage(Application* app)
    : Page(app)
{
}

// GamePage::GamePage(const PlayerCtx)
//{
//     std::cout << "constructor Game page";
// }

GamePage::~GamePage()
{
}

Page::Type GamePage::getPageType() const
{
    return Page::Type::Game;
}

void GamePage::input(const std::string& input)
{
    std::cout << "Hello";
}

void GamePage::update()
{
}

void GamePage::render()
{
    std::cout << "\t\t*****GAME PAGE*****" << std::endl;
    std::cout <<;
}
