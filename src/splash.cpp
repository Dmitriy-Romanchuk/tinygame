#include "splash.h"

#include <iostream>
#include <windows.h>

Splash::Splash(/* args */)
{
}

Splash::~Splash()
{
}

Page::Type Splash::getPageType() const
{
    return Page::Type::Splash;
}

void Splash::input(const std::string& input)
{
}

void Splash::update(float)
{
}

void Splash::render()
{
    int i = 3;
    while (i >= 0)
    {
        Sleep(1000); // задержка в 1000 миллисекунд (1 секунда)
        system("cls");
        std::cout << "Loading... " << i << std::endl;
        i--;
    }
    system("cls");
}