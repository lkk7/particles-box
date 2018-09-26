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
        bool error;                                              // State of the physics engine after init
        Physics(int width, int height, int size, int quantity);  // Sets width, height of the container, size and quantity of particles
        ~Physics();                                              // Destructor
        bool init_particles();                                   // Moves each particle to its initial place
        friend class Graphics;
        inline int get_px_size() {return px_size;}               // Return px_size

    private:
        int container_width;                // Width of the container
        int container_height;               // Height of the container
        int px_size;                        // Particle size in pixels, same for every particle
        std::vector<Particle*> particles;   // Vector of all particles

};


#endif