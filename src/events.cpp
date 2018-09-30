#include "events.hpp"

SDL_Event ev;    // Object for storing SDL events

bool handle_events()
{
    // Check for quit button click or escape key.
    while (SDL_PollEvent(&ev))
    {
        if (ev.type == SDL_QUIT)
        {
            return false;
        }
        else if (ev.type == SDL_KEYDOWN)
        {
            if (ev.key.keysym.sym == SDLK_ESCAPE)
            {
                return false;
            }
        }
    }

    return true;
}
