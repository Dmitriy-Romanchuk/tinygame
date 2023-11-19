#include "game_page.h"
#include "application.h"

#include <iostream>

GamePage::GamePage(Application* app, const PlayersCtx& playersCtx)
    : Page(app)
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
    if (boardState == Board::State::Active)
    {
        m_hasInputError = m_players[m_currentPlayerIndex]->onInput(input);
    }

    if ((boardState == Board::State::Draw || boardState == Board::State::Win) && input == "n")
    {
        m_endOfGame = true;
    }
}

void GamePage::update(float dt)
{
    m_board.update(dt);
    boardState = m_board.getState();

    if (m_hasInputError == false && boardState == Board::State::Active)
    {
        m_board.incrementStepsCount();
        togglePlayer();
    }

    if (boardState != Board::State::Active && m_endOfGame == true)
    {
        m_app->IsRunningUpdate();
    }
    //else if (boardState != Board::State::Active && m_endOfGame == false)
    //{
    //    boardState = Board::State::Active;
    //}
}

void GamePage::render()
{
    std::string buff;
    // buff.reserve(1000);
    // buff.clear();

    switch (boardState)
    {
    case Board::State::Start:
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

void GamePage::renderWelcome(std::string& buff) const
{
    buff.append("Starting battle!\nPress \"1\" to start");
}

void GamePage::renderCellNumber(std::string& buff) const
{
    m_board.render(buff);

    buff.append(m_players[m_currentPlayerIndex]->getPlayerName());
    buff.append("! Your move in the game!\nSelect cell number in range (1...9): ");
}

void GamePage::renderErrorInput(std::string& buff) const
{
    buff.append("\nError input. Try again.\n");
}

void GamePage::renderWinner(std::string& buff) const
{
    buff.append(m_players[m_currentPlayerIndex]->getPlayerName());
    buff.append(", you are a winner!\n");
    m_board.render(buff);
    buff.append("\nWould you like play again? y/n: ");
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