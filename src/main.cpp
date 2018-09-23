#include <iostream>
#include <string>
#include "graphics.hpp"

int main(int argc, char const *argv[])
{
    bool quit = false;
    SDL_Event event;
    Graphics graphics = Graphics();

    /* Handle events */
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    quit = true;
                }
            }
        }
    }

    return 0;
}

