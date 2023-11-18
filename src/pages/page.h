#pragma once

#include <string>

class Application;

class Page
{
public:
    enum class Type
    {
        Splash,
        Lobby,
        Game
    };

public:
    Page(){};
    virtual ~Page(){};

protected:
    Page(Application* app)
        : m_app(app){};

public:
    virtual Type getPageType() const = 0;

public:
    virtual void onInput(const std::string& input) = 0;
    virtual void update(float dt) = 0;
    virtual void render() = 0;

protected:
    Application* m_app;
};