#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

class Graphics
{
    public:
        bool error;   // State of the graphic engine after init
        Graphics(int w, int h, std::string title);  // Sets width, height and title of the window
        ~Graphics();            // Destructor
        bool init_self();       // SDL resources initiation
        void draw();            // Draw background and given objects

    private:
        int win_w;              // Window width
        int win_h;              // Window height
        std::string win_title;  // Window title
        SDL_Window* window;     // Pointer to the window
        SDL_Renderer* renderer; // Renderer for the graphics
};

#endif