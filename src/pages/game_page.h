#pragma once

//#include "application.h"
#include "PlayerCtx.h"
#include "page.h"

#include "board.h"
#include "player.h"

#include <string>

class GamePage : public Page
{
public:
    GamePage(Application* app, const PlayersCtx& playersCtx);
    ~GamePage();

public:
    Type getPageType() const;

    void onInput(const std::string& input) override;
    void update() override;
    void render() override;

private:
    void renderWelcome(std::string& buff) const;
    void renderCellNumber(std::string& buff) const;
    void renderErrorInput(std::string& buff) const;

    Player* createPlayer(const PlayerCtx& playersCtx, char symbol);
    void togglePlayer();

private:
    enum class StateRequest
    {
        Welcome,
        CellNumber,
        ErrorInput,
    };

private:
    bool m_hasInputError = false;
    StateRequest m_requestState = StateRequest::Welcome;
    Board m_board;

    using Players = std::array<Player*, 2>;
    uint32_t m_currentPlayerIndex = 0u;
    Players m_players;
};
