#pragma once

// #include "application.h"
#include "PlayerCtx.h"
#include "page.h"

#include "board.h"
#include "player.h"

#include <memory>
#include <string>

class GamePage : public Page
{
public:
    GamePage(Application* app, const PlayersCtx& playersCtx);

public:
    Type getPageType() const;

    void onInput(const std::string& input) override;
    void update(float dt) override;
    void render() override;

private:
    void renderWelcome(std::string& buff) const;
    void renderCellNumber(std::string& buff) const;
    void renderErrorInput(std::string& buff) const;
    void renderWinner(std::string& buff) const;
    void renderDraw(std::string& buff) const;

    Player* createPlayer(const PlayerCtx& playersCtx, char symbol);
    void togglePlayer();

private:
    bool m_hasInputError = false;
    Board m_board;

    using Players = std::array<std::unique_ptr<Player>, 2>;
    uint32_t m_currentPlayerIndex = 1u;
    Players m_players;
    Board::State boardState = Board::State::Start;
};
