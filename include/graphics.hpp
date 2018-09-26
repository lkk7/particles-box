#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "physics.hpp"

class Graphics
{
    public:
        bool error;                                                        // State of the graphic engine after init
        Graphics(Physics* phys, int w, int h, std::string title); // Sets essential parameters and the Physics object.
        ~Graphics();                                                       // Destructor
        bool init_self();                                                  // SDL and resources initiation
        bool get_particle_texture();                                       // Get the texture for particles                  
        void display_all();                                                // Present background and all particles to the screen

    private:
        int win_w;              // Window width
        int win_h;              // Window height
        std::string win_title;  // Window title
        Physics* physics;       // Physics object from which data is taken
        SDL_Window* window;     // Pointer to the window
        SDL_Renderer* renderer; // Renderer for the graphics
        SDL_Texture* texture;   // Texture of a particle 
        SDL_Rect rect;         // Universal Rect for drawing
};

#endif