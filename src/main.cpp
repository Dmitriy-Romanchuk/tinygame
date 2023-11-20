#include "application.h"

#include <iostream>

int main()
{
    Application& app = Application::getInstance();

    app.init();
    app.run();
    app.deinit();

    system("pause");

    return EXIT_SUCCESS;
}