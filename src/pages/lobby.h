#pragma once

#include "page.h"

#include <cstdint>
#include <string>

class Lobby final : public Page
{
public:
    Lobby(){};

public:
    Type getPageType() const;

    void onInput(const std::string& input) override;
    void update(float dt) override;
    void render(std::string& buff) override;

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
    uint32_t m_playerCounter = 0;
    uint32_t m_maxPlayers = 2;
    bool m_hasInputError = false;
    StateRequest m_requestState = StateRequest::PlayerType;
};
