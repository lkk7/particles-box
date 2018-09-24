#include "iostream"
#include "physics.hpp"

Physics::Physics(int width, int height, int size, int quantity) : container_width(width), container_height(height), px_size(size)
{
    particles.resize(quantity);
    for (int i = 0; i < quantity; i++)
    {
        particles[i] = new Particle;
    }

    std::cout << "particle container: " << container_width << " x " << container_height << "\n"
                 "number of particles: " << particles.size() << "\n" 
                 "particle size (pixels): " << px_size << "\n"<< std::flush;
}

Physics::~Physics()
{
    for (unsigned i = 0; i < particles.size(); i++)
    {
        delete(particles[i]);
    }
}