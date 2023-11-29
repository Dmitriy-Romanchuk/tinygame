#pragma once

#include "page.h"
#include <string>


class Splash final : public Page
{
public:
    Splash(){};

public:
    Type getPageType() const override;

    void onInput(const std::string& input) override;
    void update(float dt) override;
    void render(std::string& buff) override;

private:
    float m_DelayTime = 3000.0f; //ms
};
