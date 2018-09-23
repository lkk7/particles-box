#include <iostream>
#include <string>
#include "graphics.hpp"

namespace GRAPHICS_CONSTANTS
{
const std::string WIN_TITLE = "particle2Dsim";
const int WIN_W= 800;
const int WIN_H = 600;
}

Graphics::Graphics(int w = 800, int h = 600, const std::string title = "particle2Dsim")
    : win_w(w), win_h(h), win_title(title)
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

    /* Initialize the window */
    window = SDL_CreateWindow(win_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_w, win_h, SDL_WINDOW_SHOWN);
    if (window == NULL)
        {
            std::cout << "SDL: window creation error!" << SDL_GetError();
            return 0;
        }

    /* Initialize the renderer */
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return 0;
    }
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);   // Background color

    return 1;
}

void Graphics::draw()
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

