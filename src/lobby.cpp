#include "lobby.h"
#include "player.h"

#include <iostream>

Lobby::Lobby(/* args */)
{
}

Lobby::~Lobby()
{
}

Page::Type Lobby::getPageType() const
{
    return Page::Type::Lobby;
}

void Lobby::input(std::string)
{   
 

}

void Lobby::update(float)
{
}

void Lobby::render()
{
}
