#pragma once

//#include "application.h"
#include "PlayerCtx.h"
#include "page.h"

#include "board.h"

#include <string>

class GamePage : public Page
{
public:
    GamePage(Application* app, const PlayersCtx& playersCtx);

public:
    Type getPageType() const;

    void onInput(const std::string& input) override;
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
    Board m_board;
    
};
