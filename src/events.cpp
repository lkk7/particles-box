#include "events.hpp"

SDL_Event ev;    // Object for storing SDL events

bool handle_events()
{
    while (SDL_PollEvent(&ev))
    {
        if (ev.type == SDL_QUIT)
        {
            return true;
        }
        else if (ev.type == SDL_KEYDOWN)
        {
            if (ev.key.keysym.sym == SDLK_ESCAPE)
            {
                return true;
            }
        }
    }

    return false;
}
