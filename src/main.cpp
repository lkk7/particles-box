#include <iostream>
#include <string>
#include "graphics.hpp"
#include "events.hpp"

namespace CFG_CONST
{
const std::string WIN_TITLE = "particle2Dsim";
const int WIN_W= 800;
const int WIN_H = 600;
}

int main(int argc, char const *argv[])
{
    bool quit = false;
    Graphics graphics = Graphics(CFG_CONST::WIN_W, CFG_CONST::WIN_H, CFG_CONST::WIN_TITLE);

    /* Main loop */
    while (!quit)
    {
        if (handle_events()) quit = true;
        graphics.draw();
    }

    return 0;
}