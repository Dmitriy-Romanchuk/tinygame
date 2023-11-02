#include "player.h"

bool Player::onInput(std::string input)
{
    if(input.length() > 3 || input[1] != ' ')
    {
        return true;
    }
}