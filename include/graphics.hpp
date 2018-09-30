#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "physics.hpp"

class Graphics
{
    public:
        /* State of the graphic engine after init */
        bool error;
        /* Sets essential parameters and the Physics object */                                                  
        Graphics(Physics* phys, int w, int h, std::string title);
        /* Destructor */
        ~Graphics();
        /* SDL and resources initiation */    
        bool init_self();
        /* Present background and all particles to the screen */
        void display_all();

    private:
        /* Window width */
        int win_w;
        /* Window height */
        int win_h;
        /* Window title */
        std::string win_title;
        /* Physics object from which data is taken */
        Physics* physics;
        /* Pointer to the window */
        SDL_Window* window;
        /* Renderer for the graphics */
        SDL_Renderer* renderer;
        /* Texture of a particle */
        SDL_Texture* texture;
        /* Universal Rect for drawing */
        SDL_Rect rect;
};

#endif