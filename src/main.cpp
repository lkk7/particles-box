#include <iostream>
#include <string>
#include "physics.hpp"
#include "graphics.hpp"
#include "events.hpp"

/* Config */
namespace CFG
{
    int WIN_W = 800;
    int WIN_H = 600;
    std::string WIN_TITLE = "particles_box";
    int PARTICLE_PX_SIZE = 10;
    int NUMBER_OF_PARTICLES = 30;

}

int main(int argc, char const *argv[])
{
    bool quit = false;
    Graphics graphics = Graphics(CFG::WIN_W, CFG::WIN_H, CFG::WIN_TITLE);
    Physics physics = Physics(CFG::WIN_W, CFG::WIN_H, CFG::PARTICLE_PX_SIZE, CFG::NUMBER_OF_PARTICLES);

    /* Main loop */
    while (!quit)
    {
        if (handle_events()) 
        {
            quit = true;
        }
        graphics.draw();
    }

    return 0;
}