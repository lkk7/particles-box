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
    int PARTICLE_PX_SIZE = 20;
    int NUMBER_OF_PARTICLES = 300;
    std::string WIN_TITLE = "particles_box";
    int FPS = 30;
}

int main(int argc, char const *argv[])
{
    Physics *physics = new Physics(CFG::WIN_W, CFG::WIN_H, CFG::PARTICLE_PX_SIZE, CFG::NUMBER_OF_PARTICLES);
    Graphics *graphics = new Graphics(physics, CFG::WIN_W, CFG::WIN_H, CFG::WIN_TITLE);
    auto now = std::chrono::high_resolution_clock::now();

    /* Main loop with a set *average* framerate */
    while (!graphics->error && !physics->error)
    {
        now = std::chrono::high_resolution_clock::now();
        if (!handle_events())
        {
            break;
        }
        graphics->display_all();
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