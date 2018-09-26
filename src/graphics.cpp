#include <iostream>
#include <string>
#include <SDL2/SDL_image.h>
#include "graphics.hpp"


Graphics::Graphics(Physics* phys, int w = 800, int h = 600, std::string title = "particles_box")
    : win_w(w), win_h(h), win_title(title), physics(phys)
{
    /* Check if SDL inits correctly */
    if (!init_self())
    {
        error = 1;
    }
    error  = 0;
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
        std::cout << "SDL: init error! " << SDL_GetError() << "\n" << std::flush;
        return 0;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cout << "SDL_IMG: PNG module init error! " << SDL_GetError() << "\n" << std::flush;
        return 0;
    }

    /* Initialize the window */
    window = SDL_CreateWindow(win_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_w, win_h, SDL_WINDOW_SHOWN);
    if (window == NULL)
        {
            std::cout << "SDL: window creation error! " << SDL_GetError() << "\n" << std::flush;
            return 0;
        }

    /* Initialize the renderer */
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        std::cout << "SDL: renderer creation error! " << SDL_GetError() << "\n" << std::flush;
        return 0;
    }

    /* Create the texture of particles */
    SDL_Surface* surface = IMG_Load("resources/particle.png");
    if (surface == NULL)
    {
        std::cout << "SDL_IMG: unable to find resources/particle.png " << SDL_GetError() << "\n" << std::flush;
        return 0;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        std::cout << "SDL: error while creating texture from surface " << SDL_GetError() << "\n" << std::flush;
        return 0;
    }
    SDL_FreeSurface(surface);

    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);   // Background color

    std::cout << "window: " << win_w << " x " << win_h << " px\n" << std::flush;
    return 1;
}

void Graphics::display_all()
{
    SDL_RenderClear(renderer);
    for (auto particle : physics->particles)
    {
        (&rect)->x = particle->x;
        (&rect)->y = particle->y;
        (&rect)->w = physics->get_px_size();
        (&rect)->h = physics->get_px_size();
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }

    SDL_RenderPresent(renderer);
}

