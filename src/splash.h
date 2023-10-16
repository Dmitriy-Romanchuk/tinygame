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

    void input(const std::string& input) override;
    void update(float dt) override;
    void render() override;
};
