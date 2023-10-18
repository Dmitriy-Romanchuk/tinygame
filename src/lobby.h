#pragma once

#include "page.h"
#include "PlayerCtx.h"

#include <string>
#include <cstdint>

class Lobby final : public Page
{
public:
    Lobby(Application* app);
    ~Lobby();

public:
    Type getPageType() const;

    void input(const std::string& input) override;
    void update() override;
    void render() override;

private:
    void renderRequestType(std::string& buff) const;
    void renderRequestName(std::string& buff) const;
    void renderErrorInput(std::string& buff) const;
    void fillPlayerCtx(const std::string& input);

private:
    enum class StateRequest
    {
        PlayerType,
        PlayerName,
    };

private:
    uint32_t m_countPlayers = 0;
    uint32_t m_maxPlayers = 2;
    bool m_hasInputError = false;
    StateRequest m_requestState = StateRequest::PlayerType;
    PlayerCtx m_players[2];
};
