#include <iostream>
#include <string>
#include <chrono>
#include "physics.hpp"
#include "graphics.hpp"
#include "events.hpp"


/* Config */
namespace CFG
{
    int WIN_W = 800;
    int WIN_H = 600;
    std::string WIN_TITLE = "particles_box";
    int FPS = 30;
    int PARTICLE_PX_SIZE = 200;
    int NUMBER_OF_PARTICLES = 2;
    double PARTICLE_SPEED = 10.0;
}

int main(int argc, char const *argv[])
{
    /* Physics and Graphics objects used to start the program */
    Physics *physics = new Physics(CFG::WIN_W, CFG::WIN_H, CFG::PARTICLE_PX_SIZE, CFG::NUMBER_OF_PARTICLES, CFG::PARTICLE_SPEED);
    Graphics *graphics = new Graphics(physics, CFG::WIN_W, CFG::WIN_H, CFG::WIN_TITLE);
    
    /* Main loop with a set *average* framerate */
    auto now = std::chrono::high_resolution_clock::now();
    while (!graphics->error && !physics->error)
    {
        now = std::chrono::high_resolution_clock::now();

        if (!handle_events())
        {
            break;
        }
        physics->manage_all();
        graphics->display_all();

        /* Sleep to maintain constant framerate*/
        int exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - std::chrono::high_resolution_clock::now()).count();
        int sleep_time = (1000 / CFG::FPS) - exec_time;
        if (sleep_time > 0)
        {
            SDL_Delay(sleep_time);
        }
    }

    free(graphics);
    free(physics);
    return 0;
}