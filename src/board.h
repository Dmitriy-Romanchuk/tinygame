#pragma once

#include "page.h"

#include <stdint.h>
#include <string>
#include <array>

class Board final
{
public:
    using Data = std::array<char, 9>;

public:
    Board();
    
public:
    void render(std::string& buff) const;
    bool trySetPoint(uint32_t cellNumber, char symbol);

    const Data& getData() const;

private:
    void fillBoard(std::string& boardBuff) const;

private:
    Data m_data;
    std::string m_gameBoard;
    

};


// процессинтпут запрашивает номер ячейки, потом передает его в геймпэйдж, геймпэйдж передает его в oninput плейера
// где он валидируется и передается в setpoint борда, а гейм пэдж переключает юзеров 
