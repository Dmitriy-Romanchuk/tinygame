#pragma once

#include "application.h"
#include "PlayerCtx.h"
#include "page.h"
#include <string>

class GamePage : public Page
{
public:
public:
   //GamePage(Lobby* lbb);
    GamePage();
    //GamePage(const PlayerCtx, const PlayerCtx);
    //GamePage::GamePage(){};
    ~GamePage();

public:
    Type getPageType() const;
    Board* createGameBoard() const;

    void input(const std::string& input) override;
    void update() override;
    void render() override;

private:
    void renderWelcome(std::string& buff) const;
    void renderCellNumber(std::string& buff) const;
    void renderErrorInput(std::string& buff) const;

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
};
