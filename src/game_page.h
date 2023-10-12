#pragma once

#include "page.h"
#include <string>

class GamePage : public Page
{
private:
    char symbols[3][3] = {};
    
public:
    GamePage();
    ~GamePage();

public:
    Type getPageType() const; 

    void input(std::string) override;
    void update(float dt) override;
    void render() override;    
};