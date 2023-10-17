#pragma once

#include "page.h"
#include <string>

class Lobby final : public Page
{
public:
    Lobby(Application* app);
    ~Lobby();

public:
    struct PlayerCtx
    {
        enum class Type
        {
            Player,
            Bot
        };
    
        Type playerType;
        const char* playerName;
    };
public:
    Type getPageType() const;

    void input(const std::string& input) override;
    void update(float dt) override;
    void render() override;

private:
void renderRequestType(std::string& buff) ;
void renderRequestName(std::string& buff) const;
void renderErrorInput(std::string& buff) const;


private:
enum class StateRequest
{
    PlayerType,
    PlayerName,
};

private:
    StateRequest m_requestState = StateRequest::PlayerType;
    bool m_inputError = false;

};
