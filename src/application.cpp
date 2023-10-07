#include "application.h"

application::application(/* args */)
{
}

application::~application()
{
}

void application::init()
{
    splash.render_velcome_screen();
    sign_controller.select_game_sign();

}

void application::run()
{
    playing_area.render_playing_area();
}

void application::deinit()
{
}

