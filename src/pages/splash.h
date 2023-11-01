#pragma once

#include "page.h"
#include <string>

class Splash final : public Page
{
public:
    Splash(Application* app);
    ~Splash();

public:
    Type getPageType() const override;

    void onInput(const std::string& input) override;
    void update() override;
    void render() override;

private:
    int m_DelayTime = 3;
};
