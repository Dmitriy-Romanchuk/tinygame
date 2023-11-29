#include "game_page.h"
#include "application.h"

#include <iostream>

GamePage::GamePage(const PlayersCtx& playersCtx)
{
    m_players[0].reset(createPlayer(playersCtx[0], 'X'));
    m_players[1].reset(createPlayer(playersCtx[1], 'O'));
}

Page::Type GamePage::getPageType() const
{
    return Page::Type::Game;
}

void GamePage::onInput(const std::string& input)
{
    if (input == "quit")
    {
        m_readyToQuit = true;
    }

    auto boardState = m_board.getState();

    if ((boardState == Board::State::Draw || boardState == Board::State::Win) && input == "yes")
    {
        m_board.start();
    }

    if (boardState == Board::State::Active)
    {
        m_hasInputError = m_players[m_board.getCurrentPlayerIndex()]->onInput(input);
    }
}

void GamePage::update(float dt)
{
    if (m_hasInputError == false)
    {
        m_board.update(dt);
    }
}

void GamePage::render(std::string& buff)
{
    
    // buff.reserve(1000);
    // buff.clear();

    switch (m_board.getState())
    {
    case Board::State::ReadyToStart:
        renderWelcome(buff);
        break;

    case Board::State::Active:

        renderCellNumber(buff);

        if (m_hasInputError == true)
        {
            renderErrorInput(buff);
            m_hasInputError = false;
        }
        break;

    case Board::State::Win:
        renderWinner(buff);
        break;

    case Board::State::Draw:
        renderDraw(buff);
        break;

    default:
        break;
    }

    std::cout << "\t\t*****GAME PAGE*****\n\n"
              << buff << std::endl;
}

bool GamePage::isReadyToQuit()
{
    return m_readyToQuit;
}

void GamePage::renderWelcome(std::string& buff) const
{
    buff.append("Starting battle!\nPress \"1\" to start");
}

void GamePage::renderCellNumber(std::string& buff) const
{
    m_board.render(buff);

    buff.append(m_players[m_board.getCurrentPlayerIndex()]->getPlayerName());
    buff.append("! Your move in the game!\nSelect cell number in range (1...9): ");
}

void GamePage::renderErrorInput(std::string& buff) const
{
    buff.append("\nError input. Try again.\n");
}

void GamePage::renderWinner(std::string& buff) const
{
    buff.append(m_players[m_board.getCurrentPlayerIndex()]->getPlayerName());
    buff.append(", you are a winner!\n");
    m_board.render(buff);
    buff.append("\nWould you like play again? yes/quit: ");
}

void GamePage::renderDraw(std::string& buff) const
{
    buff.append("It's a draw!\n");
    m_board.render(buff);
    buff.append("\nWould you like play again? y/n: ");
}

Player* GamePage::createPlayer(const PlayerCtx& playersCtx, char symbol)
{
    if (playersCtx.playerType == PlayerCtx::Type::Player)
    {
        return new Player(&m_board, symbol, playersCtx);
    }

    return new Player(&m_board, symbol, playersCtx);
}
