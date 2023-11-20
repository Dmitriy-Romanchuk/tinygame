#pragma once

#include "page.h"

#include <array>
#include <stdint.h>
#include <string>

class Board final
{
public:
    using Data = std::array<char, 9>;

    enum class State
    {
        Start,
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
    State updateState();

    void update(float dt);

    const Data& getData() const;
    const State& getState() const;

    uint32_t getCurrentPlayerIndex() const;

    void restart();

private:
    void fillBoard(std::string& boardBuff) const;
    void clearBoard();

private:
    Data m_data;

    uint32_t m_stepsCount = 0;
    State m_state = State::NoActive;
};
