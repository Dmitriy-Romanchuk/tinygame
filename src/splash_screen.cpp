#include "splash_screen.h"

#include <iostream>
#include <windows.h>

velcome_screen::velcome_screen(/* args */)
{
}

velcome_screen::~velcome_screen()
{
}

void velcome_screen::render_velcome_screen()
{
    int i = 5;
    while (i >= 0)
        {
            Sleep(1000);    //задержка в 1000 миллисекунд (1 секунда)
            system("cls");
            std::cout << "Loading... " << i << std::endl;
            i--;
        }
    system("cls");
}