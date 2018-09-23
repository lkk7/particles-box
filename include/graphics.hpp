#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

class Graphics
{
    public:
        bool works_correctly;   // State of the graphic engine after init
        int win_w;              // Window width
        int win_h;              // Window height
        std::string win_title;  // Window title
        Graphics();             // Constructor
        ~Graphics();            // Destructor
        bool init_self();       // SDL resources initiation

    private:
        SDL_Window* window;     // Pointer to the window
        SDL_Renderer* renderer;
};

#endif