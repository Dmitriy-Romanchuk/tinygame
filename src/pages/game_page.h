#pragma once

#include "PlayerCtx.h"
#include "page.h"

#include "board.h"
#include "player.h"

#include <memory>
#include <string>

class GamePage : public Page
{
public:
    GamePage(const PlayersCtx& playersCtx);

public:
    Type getPageType() const;

    void onInput(const std::string& input) override;
    void update(float dt) override;
    void render(std::string& buff) override;

    bool isReadyToQuit() override;

private:
    void renderWelcome(std::string& buff) const;
    void renderCellNumber(std::string& buff) const;
    void renderErrorInput(std::string& buff) const;
    void renderWinner(std::string& buff) const;
    void renderDraw(std::string& buff) const;

    Player* createPlayer(const PlayerCtx& playersCtx, char symbol);

private:
    bool m_hasInputError = false;
    Board m_board;
    bool m_readyToQuit = false;

    using Players = std::array<std::unique_ptr<Player>, 2>;
    Players m_players;
};
