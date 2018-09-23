#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <vector>

class Physics
{
    public:
        int container_width;             // Width of the container
        int container_height;            // Height of the container
        struct Particle                  // A struct which represents a particle
        {
            int x;                       // x position
            int y;                       // y position
        };
        std::vector<Particle> particles; // Vector of all particles 
        Physics(int w, int h)            // Sets width and height of the container 
            : container_width(w), 
              container_height(h) {}
        ~Physics();                      // Destructor
};


#endif