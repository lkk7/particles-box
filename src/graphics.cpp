#include <iostream>
#include <string>
#include "graphics.hpp"

namespace GRAPHICS_CONSTANTS
{
const std::string WIN_TITLE = "particle2Dsim";
const int WIN_W= 640;
const int WIN_H = 480;
}

Graphics::Graphics()
{
    /* Check if SDL inits correctly */
    if (!init_self())
    {
        works_correctly = 0;
    }
    works_correctly = 1;
}

Graphics::~Graphics()
{
    /* Destroy SDL objects and quit it */
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
}

bool Graphics::init_self()
{
    /* Init the SDL */
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL: init error!" << SDL_GetError();
        return 0;
    }

    /* Get essential values from the GRAPHICS_CONSTANTS namespace */
    win_w = GRAPHICS_CONSTANTS::WIN_W;
    win_h = GRAPHICS_CONSTANTS::WIN_H;
    win_title = GRAPHICS_CONSTANTS::WIN_TITLE;

    /* Initialize the window */
    window = SDL_CreateWindow(win_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_w, win_h, SDL_WINDOW_SHOWN);
    if (window== NULL)
        {
            std::cout << "SDL: window creation error!" << SDL_GetError();
            return 0;
        }

    return 1;
}

