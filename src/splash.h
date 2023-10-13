#pragma once

#include "page.h"
#include <string>

class Splash final : public Page
{

public:
    Splash(/* args */);
    ~Splash();

public:
    Type getPageType() const override; 

    void input(std::string) override;
    void update(float dt) override;
    void render() override;

};




