#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <vector>

class Physics
{
    public:
        struct Particle                  // A struct which represents a particle
        {
            double x;                       // x position
            double y;                       // y position
            double vx;                      // x velocity
            double vy;                      // y velocity
        };
        bool error;                                              // State of the Physics after init
        Physics(int width, int height, int size, int quantity, double speed);  // Sets necessary parameters of Physics
        ~Physics();                                              // Destructor
        inline int get_px_size() {return px_size;}               
        inline const std::vector<Particle*> get_particles() const {return particles;}
        bool init_particles();                                   // Moves every particle to its initial place, gives each one velocity
        void manage_all();                                       // Manage state of the particles

    private:
        int container_width;                // Width of the container
        int container_height;               // Height of the container
        int px_size;                        // Particle size in pixels, same for every particle
        double particle_speed;              // Speed of particles
        std::vector<Particle*> particles;   // Vector of all particles

};


#endif