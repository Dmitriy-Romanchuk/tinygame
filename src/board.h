#pragma once

#include "page.h"

#include <stdint.h>
#include <string>
#include <array>

class Board final
{
public:
    using Data = std::array<char, 9>;

    enum class State
    {
        NoActive,
        Active,
        Win,
        Draw
    };

public:
    Board();
    
public:
    void render(std::string& buff) const;
    bool trySetPoint(uint32_t cellNumber, char symbol);
    State getState() const;

    void start();
    void update(float dt);

    const Data& getData() const;

private:
    void fillBoard(std::string& boardBuff) const;
    void clearBoard();

private:
    Data m_data;
    std::string m_gameBoard;
    uint32_t stepsCount = 0;
    
    State m_state = State::NoActive;
};


