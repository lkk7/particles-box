#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <vector>

class Physics
{
    public:
        /* A struct which represents a particle */
        struct Particle
        {
            /* x position */
            double x;
            /* y position */
            double y;
            /* x velocity */
            double vx;
            /* y velocity */
            double vy;
        };
        /* State of the Physics after init */
        bool error;
        /* Sets necessary parameters of Physics */
        Physics(int width, int height, int size, int quantity, double speed);
        /* Destructor */
        ~Physics();
        /* Returns px_size*/
        inline int get_px_size() {return px_size;} 
        /* Returns read-only reference to particles */              
        inline const std::vector<Particle*>& get_particles() const {return particles;}
        /* Moves every particle to its initial place, gives each one velocity */
        bool init_particles();
        /* Manage state of the particles */
        void manage_all();

    private:
        /* Width of the container */
        int container_width;
        /* Height of the container */
        int container_height;
        /* Particle size in pixels, same for every particle */
        int px_size;
        /* Speed of particles */
        double particle_speed;
        /* Vector of all particles */
        std::vector<Particle*> particles;

};


#endif