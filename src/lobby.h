#pragma once

#include "page.h"
#include <string>

class Lobby final : public Page
{

public:
    Lobby(/* args */);
    ~Lobby();

public:
    Type getPageType() const; 

    void input(std::string) override;
    void update(float dt) override;
    void render() override;

};
