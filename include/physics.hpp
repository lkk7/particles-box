#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <vector>

class Physics
{
    public:
        struct Particle                  // A struct which represents a particle
        {
            int x;                       // x position
            int y;                       // y position
            int vx;                      // x velocity
            int vy;                      // y velocity
        };
        Physics(int width, int height, int size, int quantity);  // Sets width, height of the container, size and quantity of particles
        ~Physics();                      // Destructor

    private:
        int container_width;             // Width of the container
        int container_height;            // Height of the container
        int px_size;                     // Particle size in pixels, same for every particle
        std::vector<Particle*> particles; // Vector of all particles

};


#endif